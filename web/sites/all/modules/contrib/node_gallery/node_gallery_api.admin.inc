<?php

/**
 * @file
 * Node Gallery API admin interface.
 */

/**
 * Displays a list of all defined Gallery-to-Image relationships.
 *
 * @return string
 *   A themed table suitable for output
 */
function node_gallery_api_relationship_type_list() {
  $relationship_types = node_gallery_api_get_all_relationship_types();
  if (!empty($relationship_types)) {
    $headers = array(
      t('Relationship name'),
      t('Gallery types'),
      t('Item types'),
      t('File field'),
      t('Actions'),
    );
    foreach ($relationship_types as $id => $relationship_type) {
      $gallery_links = array();
      $item_links = array();
      foreach ($relationship_type->gallery_types as $gallery_type) {
        $gallery_type_url_str = str_replace('_', '-', $gallery_type);
        $gallery_links[] = l($gallery_type, 'admin/structure/types/manage/' . $gallery_type_url_str);
      }
      foreach ($relationship_type->item_types as $item_type) {
        $item_type_url_str = str_replace('_', '-', $item_type);
        $item_links[] = l($item_type, 'admin/structure/types/manage/' . $item_type_url_str);
      }
      if ($relationship_type->filefield_name == 'node_gallery_none') {
        $field_label = t('None');
      }
      else {
        $field_label = l($relationship_type->filefield_name, 'admin/structure/types/manage/' . $item_type_url_str . '/fields/' . $relationship_type->filefield_name);
      }
      $rows[] = array(
        array(
          'data' => check_plain($relationship_type->label),
        ),
        theme('item_list',
          array(
            'items' => $gallery_links,
          )
        ),
        theme('item_list',
          array(
            'items' => $item_links,
          )
        ),
        $field_label,
        theme('links',
          array(
            'links' => node_gallery_api_relationship_operations($relationship_type->id),
          )
        ),
      );
    }
    return theme('table',
      array(
        'header' => $headers,
        'rows' => $rows,
        'attributes' => array('class' => array('node-gallery-config-list')),
      )
    );
  }
  else {
    return t("There are no gallery relationships defined.");
  }
}

/**
 * Returns a list of operations available to a Gallery-to-Image relationship.
 *
 * @return array
 *   An array of associative arrays with keys and values of titles
 *   and href links.
 */
function node_gallery_api_relationship_operations($rid) {
  $items[] = array(
    'title' => t('Change content types'),
    'href' => 'admin/config/content/node-gallery/relationship-type/content_types/' . $rid,
  );
  $items[] = array(
    'title' => t('Change settings'),
    'href' => 'admin/config/content/node-gallery/relationship-type/settings/' . $rid,
  );
  $items[] = array(
    'title' => t('Delete'),
    'href' => 'admin/config/content/node-gallery/delete/' . $rid,
  );

  return $items;
}


/**
 * Form definition for relationship type content types.
 */
function node_gallery_api_relationship_type_content_types_form($form, $form_state, $relationship_type = NULL) {
  static $node_types;
  $form['relationship_type'] = array(
    '#tree' => TRUE,
  );

  if (empty($node_types)) {
    foreach (node_type_get_types() as $node_type) {
      $node_types[$node_type->type] = check_plain($node_type->name);
    }
  }
  $form['#relationship_type'] = $relationship_type;
  $form['relationship_type']['gallery_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Gallery Types'),
    '#options' => $node_types,
    '#description' => t('Select which content type should be used as the gallery type.'),
    '#default_value' => !empty($relationship_type->gallery_types) ? $relationship_type->gallery_types : NULL,
    '#required' => TRUE,
  );
  $form['relationship_type']['item_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Item Types'),
    '#options' => $node_types,
    '#description' => t('Select which content type should be used as the item type.'),
    '#default_value' => !empty($relationship_type->item_types) ? $relationship_type->item_types : NULL,
    '#required' => TRUE,
  );

  $item_types = isset($relationship_type->item_types) ? $relationship_type->item_types : NULL;
  if (empty($item_types)) {
    $item_types = array_keys(node_type_get_types());
  }
  $item_fields = node_gallery_api_get_fields_from_content_types($item_types);
  $file_fields = array('node_gallery_none' => 'None');
  foreach ($item_fields as $name => $field) {
    $item_field_options[$name] = check_plain($field['label']);
    if (!empty($field['field_info']) && in_array($field['field_info']['type'], array('file', 'image'))) {
      $file_fields[$name] = $name;
    }
  }
  if (!array_key_exists(NODE_GALLERY_MEDIA_FIELD, $file_fields)) {
    $file_fields['node_gallery_create'] = t('Create new file field');
  }

  $form['relationship_type']['filefield_name'] = array(
    '#type' => 'select',
    '#title' => t('File storage field'),
    '#description' => t("Select the file field that will be used for storing gallery item media.  In most cases, you shouldn't need to change this setting."),
    '#options' => $file_fields,
    '#default_value' => (!empty($relationship_type->filefield_name)) ? $relationship_type->filefield_name : NODE_GALLERY_MEDIA_FIELD,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Validation callback for the relationship form.
 */
function node_gallery_api_relationship_type_content_types_form_validate($form, &$form_state) {
  $gallery_types = $form_state['values']['relationship_type']['gallery_types'];
  $item_types = $form_state['values']['relationship_type']['item_types'];
  foreach ($gallery_types as $gallery_type) {
    if (in_array($gallery_type, $item_types)) {
      form_set_error('relationship_type][gallery_types', t("A node type cannot be both a gallery and an item type."));
    }
    $existing_gallery_type = node_gallery_api_get_relationship_type($gallery_type);
    if (!empty($existing_gallery_type) && $existing_gallery_type->id != $form['#relationship_type']->id) {
      form_set_error('relationship_type][gallery_types', t('The !gallery_type type is already part of a node gallery relationship.', array('!gallery_type' => $gallery_type)));
    }
  }
  foreach ($item_types as $item_type) {
    $existing_item_type = node_gallery_api_get_relationship_type(NULL, $item_type);
    if (!empty($existing_item_type) && $existing_item_type->id != $form['#relationship_type']->id) {
      form_set_error('relationship_type][item_types', t('The !item_type type is already part of a relationship.', array('!item_type' => $item_type)));
    }
  }
}


/**
 * Submit handler for relationship settings form.
 */
function node_gallery_api_relationship_type_content_types_form_submit($form, &$form_state) {
  $r = $form['#relationship_type'];
  if (is_null($r)) {
    // New relationship.
    $r = new NodeGalleryRelationshipType();
    $r->settings = node_gallery_api_relationship_type_settings_defaults();
  }
  $send_to_settings_form = FALSE;
  $r->settings['relationship_type']['gallery_types'] = array_keys($form_state['values']['relationship_type']['gallery_types']);
  $r->settings['relationship_type']['item_types'] = array_keys($form_state['values']['relationship_type']['item_types']);
  $r->filefield_name = $form_state['values']['relationship_type']['filefield_name'];
  if ($r->filefield_name == 'node_gallery_create') {
    $r->filefield_name = NODE_GALLERY_MEDIA_FIELD;
  }

  if (!isset($r->id)) {
    $send_to_settings_form = TRUE;
    $r->label = $r->settings['relationship']['name'];
    drupal_set_message(t('Default settings applied. Please verify them below.'), 'warning');
  }
  else {
    drupal_set_message(t('Node Gallery relationship updated'));
  }
  $r->save();
  variable_set('menu_rebuild_needed', TRUE);
  if ($send_to_settings_form) {
    $form_state['redirect'] = 'admin/config/content/node-gallery/relationship-type/settings/' . $r->id;
  }
  else {
    $form_state['redirect'] = 'admin/config/content/node-gallery';
  }
}

/**
 * Get all field info for content types.
 */
function node_gallery_api_get_fields_from_content_types($types) {
  $fields = array();
  foreach ($types as $type) {
    $fields += field_info_instances('node', $type);
    $fields += field_info_extra_fields('node', $type, 'form');
  }

  foreach ($fields as $name => $field) {
    $fields[$name]['field_info'] = field_info_field($name);
  }
  uasort($fields, '_node_gallery_api_sort_fields_by_weight');
  return $fields;
}

/**
 * Form definition for Relationship Type settings form.
 */
function node_gallery_api_relationship_type_settings_form($form, $form_state, $relationship_type) {
  $view_modes = node_gallery_api_get_view_modes();
  $item_fields = node_gallery_api_get_fields_from_content_types($relationship_type->item_types);
  $item_field_options = array();
  foreach ($item_fields as $key => $info) {
    $item_field_options[$key] = $info['label'];
  }

  $form['#tree'] = TRUE;
  $form['#relationship_type'] = $relationship_type;
  $form['relationship'] = array(
    '#type' => 'fieldset',
    '#title' => t('Relationship settings'),
    '#description' => t('This area defines the settings used to define the relationship between the Gallery and Item content types.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['relationship']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Relationship Name'),
    '#description' => t('Enter a name for this relationship which will only be viewed by the admin user.'),
    '#default_value' => $relationship_type->settings['relationship']['name'],
    '#required' => TRUE,
  );

  $viewdisplays = node_gallery_api_build_views_select('node_gallery_items');

  $form['view_modes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Gallery View Modes'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('This area defines the settings used to display an individual gallery node.'),
  );
  foreach ($view_modes as $name => $label) {
    $form['view_modes'][$name] = array(
      '#type' => 'fieldset',
      '#title' => $label,
      '#collapsible' => TRUE,
      '#collapsed' => !($name == 'full' || $name == 'teaser'),
    );
    $form['view_modes'][$name]['view']  = array(
      '#type' => 'select',
      '#title' => 'View',
      '#description' => t("Select the display of the gallery items which will be shown in this view mode. Only Views tagged with 'node_gallery_items' are displayed here."),
      '#options' => $viewdisplays,
      '#default_value' => isset($relationship_type->settings['view_modes'][$name]['view']) ? $relationship_type->settings['view_modes'][$name]['view'] : '',
    );
  }

  // Image view options.
  $form['item_view'] = array(
    '#type' => 'fieldset',
    '#title' => t('Item view settings'),
    '#description' => t('This area defines the settings used when displaying an individual item node.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['item_view']['display_navigator'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display item navigator on item pages?'),
    '#default_value' => $relationship_type->settings['item_view']['display_navigator'],
    '#description' => t('When checked, the navigator (bar providing "Previous", "Next", etc. links) will be displayed at the top of the item page.'),
  );
  $form['item_view']['view_navigator_item_display'] = array(
    '#type' => 'select',
    '#title' => t('Item navigator sort view'),
    '#description' => t("Select the display that defines the desired sort order to be used when displaying items. You must include the 'Node: Nid' field in this view. Only Views tagged with 'node_gallery_items' are displayed here."),
    '#options' => $viewdisplays,
    '#default_value' => isset($relationship_type->settings['item_view']['view_navigator_item_display']) ? $relationship_type->settings['item_view']['view_navigator_item_display'] : '',
  );
  $form['item_view']['page_fragment'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Named Anchors on Image "Previous" and "Next" links?'),
    '#default_value' => $relationship_type->settings['item_view']['page_fragment'],
    '#description' => t('When checked, the "Previous" and "Next" links will jump to the top of the image. You might want to leave this unchecked if you have ads at the top of your image pages.'),
  );

  // Manage images tab settings.
  $form['manage_items'] = array(
    '#type' => 'fieldset',
    '#title' => t('Manage Items tab settings'),
    '#description' => t('This area defines the settings used by the Manage Items tab.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['manage_items']['items_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Manage Items Fields'),
    '#options' => $item_field_options,
    '#description' => t('Specify which fields should be displayed on the Manage Items tab of a gallery node.'),
    '#default_value' => $relationship_type->settings['manage_items']['items_fields'],
  );
  $form['manage_items']['items_per_page'] = array(
    '#type' => 'textfield',
    '#maxlength' => 5,
    '#size' => 5,
    '#title' => t('Enter the number of images displayed on each Manage Items page'),
    '#default_value' => $relationship_type->settings['manage_items']['items_per_page'],
    '#description' => t('If this number is exceeded, a pager will be displayed below each corresponding Manage Items page.'),
  );
  if (image_get_toolkit() != 'gd' || function_exists("imagerotate")) {
    $form['manage_items']['enable_rotation'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable the rotation of images on the Manage Items page'),
      '#default_value' => $relationship_type->settings['manage_items']['enable_rotation'],
      '#description' => t('If checked, image rotation operations will be displayed on each image on the Manage Items tab.'),
    );
    $form['manage_items']['rotation_radios'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show radio buttons for rotation.'),
      '#default_value' => isset($relationship_type->settings['manage_items']['rotation_radios']) ? $relationship_type->settings['manage_items']['rotation_radios'] : 1,
      '#description' => t('If checked, image rotation can be done by selecting radio buttons for the rotation degree.'),
      '#states' => array(
        'disabled' => array(
          ':input[name="manage_items[enable_rotation]"]' => array(
            'checked' => FALSE,
          ),
        ),
      ),
    );
    $form['manage_items']['rotation_modal'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show link for rotation popup.'),
      '#default_value' => isset($relationship_type->settings['manage_items']['rotation_modal']) ? $relationship_type->settings['manage_items']['rotation_modal'] : 1,
      '#description' => t('If checked, image rotation can be done with a popup box that display all options.'),
      '#states' => array(
        'disabled' => array(
          ':input[name="manage_items[enable_rotation]"]' => array(
            'checked' => FALSE,
          ),
        ),
      ),
    );
  }
  $has_og = module_exists('og');
  $form['og'] = array(
    '#type' => 'fieldset',
    '#title' => t('Organic Groups'),
    '#collapsible' => TRUE,
    '#collapsed' => !$has_og,
  );
  $form['og']['sync_items'] = array(
    '#type' => 'checkbox',
    '#title' => t("Keep gallery item Group Audience in sync with gallery Group Audience"),
    '#default_value' => isset($relationship_type->settings['og']['sync_items']) ? $relationship_type->settings['og']['sync_items'] : 1,
    '#description' => t('If checked, changes to the Group Audience of a gallery will be copied to all items in that gallery.'),
  );
  if (!$has_og) {
    $form['og']['sync_items']['#attributes']['disabled'] = 'disabled';
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 8,
  );
  $form['#submit'] = array('node_gallery_api_relationship_settings_form_submit');

  return $form;
}

/**
 * Submit handler for relationship settings form.
 */
function node_gallery_api_relationship_settings_form_submit($form, &$form_state) {
  $r = $form['#relationship_type'];

  $settings = isset($r->settings) ? $r->settings : array();
  $valid_settings = array(
    'relationship',
    'view_modes',
    'item_view',
    'manage_items',
    'og',
  );
  foreach ($form_state['values'] as $k => $v) {
    if (in_array($k, $valid_settings)) {
      $settings[$k] = $v;
    }
  }

  $r->settings = $settings;
  $r->label = $settings['relationship']['name'];
  $r->save();

  menu_cache_clear_all();
  drupal_set_message(t('Node Gallery relationship updated'));

  $form_state['redirect'] = 'admin/config/content/node-gallery';
}

/**
 * Builds the form used to delete relationships.
 */
function node_gallery_api_relationship_type_delete_form($form, $form_state, $relationship_type) {
  $form['relationship_type_id'] = array(
    '#type' => 'value',
    '#value' => $relationship_type->id,
  );
  $form['relationship_type_label'] = array(
    '#type' => 'value',
    '#value' => $relationship_type->label,
  );

  return confirm_form($form, t('Are you sure you want to delete the relationship %name?', array('%name' => $relationship_type->label)),
   'admin/config/content/node-gallery', NULL, t('Delete'), t('Back'));
}

/**
 * Submit handler for the deletion form.
 */
function node_gallery_api_relationship_type_delete_form_submit($form, &$form_state) {

  entity_delete('node_gallery_relationship_type', $form_state['values']['relationship_type_id']);

  drupal_set_message(t('Relationship %name has been deleted.', array('%name' => $form_state['values']['relationship_type_label'])));
  watchdog(
    'node_gallery',
    'Node Gallery relationship deleted.',
    WATCHDOG_NOTICE
  );

  $form_state['redirect'] = 'admin/config/content/node-gallery';
}


/**
 * Displays the form at admin/config/content/node_gallery/settings.
 */
function node_gallery_api_settings_form($form, &$form_state) {
  $form['node_gallery_api_plupload_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('plupload settings'),
    '#description' => t('This area defines the settings used when integrating Node Gallery with plupload.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_integration'] = array(
    '#type' => 'checkbox',
    '#weight' => 0,
    '#title' => t('Use plupload module to upload images?'),
    '#default_value' => variable_get('node_gallery_api_plupload_integration', TRUE),
    '#description' => t('When checked, the plupload widget will be used on the "Upload Images" tab to add new images to a gallery.'),
  );
  $form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_manage_images_integration'] = array(
    '#type' => 'checkbox',
    '#weight' => 1,
    '#title' => t('Integrate plupload and the Manage Images tab?'),
    '#default_value' => variable_get('node_gallery_api_plupload_manage_images_integration', TRUE),
    '#description' => t('When checked, the first visit to the Manage Images tab after uploading new images will only show newly uploaded images.'),
  );
  $form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_manage_images_limit'] = array(
    '#type' => 'textfield',
    '#maxlength' => 5,
    '#size' => 5,
    '#title' => t('Enter the limit on the number of images displayed after upload.'),
    '#default_value' => variable_get('node_gallery_plupload_api_manage_images_limit', 100),
    '#description' => t("Displaying too many images on the Manage Images tab at once will exhaust the server's memory.  This setting limits the number of images listed."),
  );
  if (!module_exists('plupload')) {
    $form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_integration']['#disabled'] = TRUE;
    $form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_integration']['#default_value'] = FALSE;
    $form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_integration']['#description'] = t('You need to download and install the <a href="@plupload_url">plupload module</a> to enable this option.', array('@plupload_url' => url('http://drupal.org/project/plupload')));
  }
  $form['node_gallery_api_misc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['node_gallery_api_misc']['node_gallery_api_keyboard_shortcuts'] = array(
    '#type' => 'checkbox',
    '#weight' => 0,
    '#title' => t('Enable keyboard shortcuts when Item Navigator is displayed?'),
    '#default_value' => variable_get('node_gallery_api_keyboard_shortcuts', FALSE),
    '#description' => t('When checked, users can press the left and right arrow keys to move between gallery items.'),
  );
  $form['node_gallery_api_misc']['node_gallery_api_display_exif_creation_date'] = array(
    '#type' => 'checkbox',
    '#weight' => 3,
    '#title' => t('Display creation date from EXIF data in Sort Items tab?'),
    '#default_value' => variable_get('node_gallery_api_display_exif_creation_date', FALSE),
    '#description' => t('When checked, you get an additional column in Sort Items tab, showing EXIF original creation date and time of the photo is available.'),
  );
  $form['node_gallery_api_misc']['node_gallery_api_activate_chronological_sorting_button'] = array(
    '#type' => 'checkbox',
    '#weight' => 4,
    '#title' => t('Activate the chronological order sorting feature in Sort Items tab?'),
    '#default_value' => variable_get('node_gallery_api_activate_chronological_sorting_button', FALSE),
    '#description' => t('When checked, you get an additional button in Sort Items tab, allowing to set shown images in chronological order, from JPEG embeded EXIF data.'),
  );

  // TODO: Recreate wizard interface.
  // $form['#submit'] = array('node_gallery_api_settings_menu_rebuild');
  $form = system_settings_form($form);
  return $form;
}

/**
 * Submit handler for the Node Gallery settings form to flag the
 * menu system as needing to be rebuilt if needed.
 */
function node_gallery_api_settings_menu_rebuild($form, &$form_state) {
  // If either plupload integration is toggled, or the Create content link is
  // changed, the menu system needs to be rebuilt.
  if (($form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_integration']['#default_value'] != $form_state['values']['node_gallery_api_plupload_integration']) || ($form['node_gallery_api_plupload_settings']['node_gallery_api_plupload_wizard']['#default_value'] != $form_state['values']['node_gallery_api_plupload_wizard'])) {
    variable_set('menu_rebuild_needed', TRUE);
  }
}

/**
 * Builds a list of all views tagged with 'node_gallery'.
 *
 * @return array
 *   An associative array where the key is a serialized array, and the value
 *   is the title of the view display.  The serialized array key is:
 *     - name: the name of the view.
 *     - display_id: the display_id of the display.
 */
function node_gallery_api_build_views_select($tags = 'node_gallery') {
  // Load list of views into array for select lists.
  $tags = (is_array($tags)) ? $tags : array($tags);
  $select = array('' => t('None'));
  foreach (views_get_all_views() as $view) {
    if (!in_array($view->tag, $tags)) {
      continue;
    }
    foreach ($view->display as $display) {
      // Don't show the "Master" view.
      if ($display->id != 'default') {
        $select[$view->name][$view->name . ':' . $display->id] = $display->display_title;
      }
    }
  }
  return $select;
}

/**
 * Sort function for sorting fields by widget weight.
 *
 * @param array $a
 *   widget a
 * @param array $b
 *   widget b
 *
 * @return int
 *   sort order
 */
function _node_gallery_api_sort_fields_by_weight($a, $b) {
  $a_weight = (int) isset($a['widget']['weight']) ? $a['widget']['weight'] : $a['weight'];
  $b_weight = (int) isset($b['widget']['weight']) ? $b['widget']['weight'] : $b['weight'];
  return $a_weight - $b_weight;
}