<?php

/**
 * @file
 * Node Gallery module.
 */

/**
 * Redirect to first item in the gallery.
 * @param $gallery
 */
function node_gallery_api_browse_items($gallery) {
  $first_item = node_gallery_api_get_first_item($gallery->nid);
  $path = 'node/';
  if (is_numeric($first_item)) {
    $path .= $first_item;
    // Set our pretty path.
    $path = drupal_get_path_alias($path);
  }
  drupal_goto($path);
}

/**
 * Form function for the "Sort Items" tab.
 */
function node_gallery_api_sort_items_form($form, $form_state, $gallery, $no_jquery = FALSE) {

  // node_gallery_set_user_breadcrumb($gallery->uid, $gallery);
  $form = array();
  $form['#images'] = array();

  $images = node_gallery_api_get_items($gallery, TRUE, FALSE);
  $image_count = count($images);

  $max_image_count = variable_get('node_gallery_sort_images_max', 750);
  if ($image_count > $max_image_count) {
    drupal_set_message(t('There are too many images in this gallery to display. You can increase the limit by !settings_url. The current limit is !max.', array('!settings' => 'admin/config/content/node-gallery/settings', '!max' => $max_image_count)), 'warning');
    return $form;
  }

  // Form generation starts here.
  $original_sort = array();
  for ($i = 0; $i < $image_count; ++$i) {
    $image = $images[$i];
    $original_sort[] = $image->nid;
    // @todo: We should document how many images will exhaust 128M RAM
    // to manage expectations.  I don't think there's
    // anything we can do here, because it's Drupals' form
    // render process that eats up the heap.
    $form['images-sort-' . $i] = array(
      '#type' => 'weight',
      '#delta' => $image_count,
      '#default_value' => $i,
      '#attributes' => array(
        'class' => array('sort'),
      ),
    );
    $form['#images'][] = array(
      'nid' => $image->nid,
      'title' => check_plain($image->title),
      'created' => $image->created,
      'changed' => $image->changed,
      'status' => $image->status,
      'original_sort' => $i,
      'filepath' => isset($image->node_gallery['item_file_url']) ? $image->node_gallery['item_file_url'] : NULL,
      'file_object' => isset($image->node_gallery['item_file']) ? $image->node_gallery['item_file'] : NULL,
    );
    if (variable_get('node_gallery_api_display_exif_creation_date', FALSE)) {
      $form['#images'][$i]['exif_created'] = node_gallery_api_original_datetime_from_exif($image);
    }
  }

  $original_sort = implode($original_sort, ',');
  $form['original_sort'] = array(
    '#type' => 'hidden',
    '#value' => $original_sort,
  );
  $form['new_sort'] = array(
    '#type' => 'hidden',
    '#default_value' => $original_sort,
  );
  $form['ngid'] = array(
    '#type' => 'value',
    '#value' => $gallery->nid,
  );
  $form['gallery_type'] = array(
    '#type' => 'value',
    '#value' => $gallery->type,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save custom sorting'),
  );
  if (variable_get('node_gallery_api_activate_chronological_sorting_button', FALSE)) {
    $form['chronological_sort'] = array(
      '#type' => 'submit',
      '#value' => t('Set in chronological order'),
      '#submit' => array('node_gallery_api_sort_items_form_set_chronological_sorting'),
    );
  }
  $form['remove'] = array(
    '#type' => 'submit',
    '#value' => t('Restore default sorting'),
    '#submit' => array('node_gallery_api_sort_items_form_remove_weights_submit'),
  );
  return $form;
}

/**
 * Submit function to set image weights reflecting chronological order of their making
 */
function node_gallery_api_sort_items_form_set_chronological_sorting($form, &$form_state) {
  $images = array();
  $ngid = $form_state['values']['ngid'];
  $gallery = node_load($ngid);
  $items = node_gallery_api_get_items($gallery, FALSE, FALSE);
  $no_exif_count = 0;
  $exif = null;

  // Get exif creation DateTime
  foreach ($items as $item) {
    $item->original_DateTime = node_gallery_api_original_datetime_from_exif($item);
    if (!isset($item->original_DateTime)) {
      if (user_access('access site reports')) {
        drupal_set_message(t("Unable to find creation date in exif data for: @title", array('@title' => $item->title)));
      }
      $no_exif_count++;
      if (!empty($item->node_gallery['item_file']['timestamp'])) {
        $item->original_DateTime = $item->node_gallery['item_file']['timestamp'];
      }
      else {
        $item->original_DateTime = $item->created;
      }
    }
  }

  if ($no_exif_count) {
    drupal_set_message(t("Unable to find creation date in exif data for: @count media(s)", array('@count' => $no_exif_count)));
    if ($no_exif_count == count($items)) {
      drupal_set_message(t("The order of the images was left unchanged."));
      return;
    }
  }

  usort($items, 'node_gallery_api_original_datetime_chronological_sort');

  $i = 0;
  foreach ($items as $item) {
    $images[] = array(
      'nid' => $item->nid,
      'ngid' => $ngid,
      'weight' => $i,
    );
    $i++;
  }
  $batch = array(
    'title' => t('Updating image order'),
    'operations' => array(array('node_gallery_api_batch_sorting_callback', array($images))),
    'finished' => 'node_gallery_api_batch_sorting_finished',
    'file' => drupal_get_path('module', 'node_gallery_api') . '/node_gallery_api.inc',
    'init_message' => t('New image positions are being calculated.'),
    'progress_message' => t('Processing image sorting.'),
    'error_message' => t('Image sorting has encountered an error.'),
  );
  batch_set($batch);
}

/**
 * Submit function to reset all image weights in a gallery to 0,
 * effectively removing any custom sort.
 */
function node_gallery_api_sort_items_form_remove_weights_submit($form, &$form_state) {
  $result = db_update('node_gallery_relationship')
    ->fields(array('weight' => 0))
    ->condition('ngid', $form_state['values']['ngid'])
    ->execute();
  if ($result === FALSE) {
    $message = t("There was a problem updating your images.");
  }
  else {
    $message = t("All image weights have been reset. The global sorting is now active again.");
  }
  node_gallery_api_clear_gallery_caches($form_state['values']['ngid']);
  drupal_set_message($message);
}


/**
 * Submit handler for sort form.
 */
function node_gallery_api_sort_items_form_submit($form, &$form_state) {
  $images = array();
  $ngid = $form_state['values']['ngid'];

  // Tabledrag data.
  $i = 0;
  foreach ($form['#images'] as $image) {
    if (isset($form_state['values']['images-sort-' . $i])
         && ($form_state['values']['images-sort-' . $i] != $image['original_sort'])) {
      $images[] = array(
        'nid' => $image['nid'],
        'ngid' => $ngid,
        'weight' => $form_state['values']['images-sort-' . $i],
      );
    }
    $i++;
  }
  if (!empty($images)) {
    $batch = array(
      'title' => t('Updating image order'),
      'operations' => array(array('node_gallery_api_batch_sorting_callback', array($images))),
      'finished' => 'node_gallery_api_batch_sorting_finished',
      'file' => drupal_get_path('module', 'node_gallery_api') . '/node_gallery_api.inc',
      'init_message' => t('New image positions are being calculated.'),
      'progress_message' => t('Processing image sorting.'),
      'error_message' => t('Image sorting has encountered an error.'),
    );
    batch_set($batch);
  }
  else {
    drupal_set_message(t("The order of the images was left unchanged."));
  }
}


/**
 * Displays the content for our "Manage Images" tab, which is a VBO view.
 *
 * @param array $form_state
 *   Drupal $form_state array
 * @param array $gallery
 *   A populated node gallery object.
 *
 * @return array
 *   FAPI array
 */
function node_gallery_api_manage_items_form($form, &$form_state, $gallery) {
  global $pager_page_array, $pager_total;
  $relationship_type = node_gallery_api_get_relationship_type($gallery->type);

  // We must set these globals, because we do not call pager_query.
  $element = 0;
  $pager_page_array = (isset($_GET['page']) ? explode(',', $_GET['page']) : array());
  if (empty($pager_page_array[$element])) {
    $pager_page_array[$element] = 0;
  }
  $items_per_page = $relationship_type->settings['manage_items']['items_per_page'];

  $form = array(
    '#theme' => 'node_gallery_api_manage_items_form',
    '#cache' => TRUE,
  );

  $form['#description'] = t('Manage Images form.');
  $form['#thumb_imagecache'] = 'node-gallery-admin-thumbnail';
  $form['#gallery'] = $gallery;
  $form_state['programmed'] = FALSE;
  $form['#attached']['css'][] = drupal_get_path('module', 'node_gallery_api') . '/node_gallery_api.css';

  $items = array();
  if (isset($_SESSION['node_gallery_api_plupload_nids'][$gallery->nid])) {
    foreach ($_SESSION['node_gallery_api_plupload_nids'][$gallery->nid] as $nid) {
      $item = node_load($nid);
      if (!empty($relationship_type->filefield_name)) {
        $files = field_get_items('node', $item, $relationship_type->filefield_name);
        if (!empty($files)) {
          $item->node_gallery['item_file'] = $files[0];
          $item->node_gallery['item_file_url'] = file_create_url($files[0]['uri']);
        }
      }
      $items[] = $item;
    }
    // We trim the $images array to a max length to prevent
    // OOM's on the manage images form.
    // There's just no easy way to do paging for just one
    // visit to the manage images tab.
    drupal_set_message(t('Current display is filtered to show only images just uploaded.  Please refresh the page to display all images in the gallery.'), 'status');
    $length = min(variable_get('node_gallery_api_plupload_manage_images_limit', 100), count($items));
    $items = array_slice($items, 0, $length);
    $chunks = array_chunk($items, count($items));
    unset($_SESSION['node_gallery_api_plupload_nids'][$gallery->nid]);
  }
  else {
    // $images = node_gallery_api_get_item_nids($gallery->nid, TRUE, FALSE);
    $items = node_gallery_api_get_items($gallery, TRUE, FALSE);
    if (!empty($items)) {
      $chunks = array_chunk($items, $items_per_page);
      $items = $chunks[$pager_page_array[$element]];
    }
  }
  if (empty($items)) {
    return $form;
  }

  $pager_total[$element] = count($chunks);
  $enable_rotation = FALSE;
  if ($relationship_type->settings['manage_items']['enable_rotation'] && (image_get_toolkit() != 'gd' || function_exists("imagerotate"))) {
    $enable_rotation = TRUE;
  }
  if (!empty($items)) {
    $count = 0;
    $form['items']['#tree'] = TRUE;
    foreach ($items as $item) {
      $count++;
      if ($count % 50 == 0) {
        // Make sure we don't run out of memory by clearing the cache.
        // $item = node_load(NULL, NULL, TRUE);
      }
      // $item = node_load($nid);
      $options[$item->nid] = '';
      $form['items'][$item->nid]['item_file'] = array(
        '#type' => 'value',
        '#value' => !empty($item->node_gallery['item_file']) ? $item->node_gallery['item_file'] : '',
      );
      $form['items'][$item->nid]['item_file_url'] = array(
        '#type' => 'value',
        '#value' => !empty($item->node_gallery['item_file_url']) ? $item->node_gallery['item_file_url'] : '',
      );
      $form['items'][$item->nid]['remove'] = array(
        '#type' => 'checkbox',
        '#default_value' => FALSE,
      );
      if ($enable_rotation) {
        if (!empty($relationship_type->settings['manage_items']['rotation_radios'])) {
          $form['items'][$item->nid]['rotate'] = array(
            '#type' => 'radios',
            '#options' => array(
              0 => t('None'),
              90 => t('90° CW'),
              270 => t('90° CCW'),
              180 => t('180°'),
            ),
            '#default_value' => 0,
          );
        }
        else {
          $form['items'][$item->nid]['rotate'] = array(
            '#type' => 'hidden',
            '#default_value' => 0,
          );
        }
        if (!empty($relationship_type->settings['manage_items']['rotation_modal'])) {
          $form['items'][$item->nid]['rotate']['#suffix'] = l(t('rotate'), '', array(
            'fragment' => ' ',
            'attributes' => array(
              'class' => 'node-gallery-api-rotate-link',
              'rel' => image_style_url('node_gallery_api_admin_thumbnail', $item->{$relationship_type->filefield_name}[LANGUAGE_NONE][0]['uri']),
            ),
          ));
        }
      }
      $item_form_values = isset($form_state['values']['items'][$item->nid]['edit_form']) ? $form_state['values']['items'][$item->nid]['edit_form'] : array();
      $form['items'][$item->nid]['edit_form'] = node_gallery_api_item_edit_form($item_form_values, $item, $relationship_type, $form_state);
    }
  }
  $cover_nid = $gallery->node_gallery['cover_item'];
  $form['is_cover'] = array(
    '#type' => 'radios',
    '#default_value' => in_array($cover_nid, array_keys($options)) ? $cover_nid : NULL,
    '#options' => $options,
  );

  $form['pager'] = array(
    '#value' => theme('pager', array('tags' => NULL, 'element' => $element)),
  );

  $form['gallery_nid'] = array(
    '#type' => 'value',
    '#value' => $gallery->nid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 20,
    // Need this because this form is used in image upload ahah also.
    '#submit' => array('node_gallery_api_manage_items_submit'),
    '#validate' => array('node_gallery_api_manage_items_validate'),
  );
  // OG hook_form_alter's the image node form and mucks up the breadcrumbs.
  // Calling our function after we load the image forms fixes that.
  // node_gallery_api_set_user_breadcrumb($gallery->uid, $gallery);
  return $form;
}

/**
 * Validation hanlder for Manage Items form.
 */
function node_gallery_api_manage_items_validate($form, &$form_state) {
  if (!empty($form_state['values']['items'])) {
    foreach ($form_state['values']['items'] as $nid => $image_form_state) {
      node_validate($form['items'][$nid]['edit_form']['#node'], $form['items'][$nid]['edit_form'], $image_form_state['edit_form']);
    }
  }
}

/**
 * Submit handler for Manage Items form.
 */
function node_gallery_api_manage_items_submit(&$form, &$form_state) {
  $relationship_type = node_gallery_api_get_relationship_type($form['#gallery']->type);
  $file_field = field_info_field($relationship_type->filefield_name);
  $compare_fields = array();
  foreach ($relationship_type->settings['manage_items']['items_fields'] as $k => $f) {
    if ($f) {
      if ($k == 'body_field') {
        $compare_fields[] = 'body';
      }
      elseif ($k == 'author') {
        $compare_fields[] = 'name';
        $compare_fields[] = 'date';
      }
      elseif ($k == 'options') {
        // Publication settings.
        $compare_fields[] = 'status';
        $compare_fields[] = 'promote';
        $compare_fields[] = 'sticky';
      }
      else {
        $compare_fields[] = $k;
      }
    }
  }
  if ($form_state['values']['is_cover'] != $form['#gallery']->node_gallery['cover_item']) {
    node_gallery_api_set_gallery_cover_item($form_state['values']['is_cover'], $form['#gallery']->nid);
  }

  foreach ($form_state['values']['items'] as $nid => $form_values) {
    // Strip add-more buttons.
    foreach ($form_values['edit_form'] as $field => $values) {
      if (strpos($field, 'field_') !== FALSE && is_array($values)) {
        unset($form_values['edit_form'][$field][$field . '_add_more-' . $nid]);
      }
    }
    $image_node = (object) $form_values['edit_form'];
    if ($form_values['remove']) {
      $op_images['delete'][] = $image_node->nid;
    }
    else {
      if (node_gallery_api_items_check_update($form['items'][$image_node->nid]['edit_form']['#node'], $image_node, $compare_fields)) {
        // Use strict comparison because the array can contain zeros.
        if (in_array('author', $relationship_type->settings['manage_items']['items_fields'], TRUE)) {
          $new_author = array_shift(user_load_multiple(array(), array('name' => $image_node->name)));
          $image_node->uid = $new_author->uid;
          $image_node->created = strtotime($image_node->date);
        }
        $op_images['update'][] = $image_node;
      }
    }
    if (!empty($form_values['rotate'])) {
      $allowed_degrees = array('90', '270', '180');
      $degrees = (int) $form_values['rotate'];
      if (in_array($degrees, $allowed_degrees)) {
        $node = $form['items'][$image_node->nid]['edit_form']['#node'];
        $node_wrapper = entity_metadata_wrapper('node', $node);
        if ($file_field['cardinality'] == 1) {
          $file = $node_wrapper->{$relationship_type->filefield_name}->value();
        }
        else {
          $file = reset($node_wrapper->{$relationship_type->filefield_name}->value());
        }
        if (!empty($file)) {
          $op_images['rotate'][] = array($file['fid'], $degrees);
        }
      }
    }
  }
  while (!empty($op_images['update'])) {
    $node = array_shift($op_images['update']);
    $operations[] = array('node_gallery_api_batch_node_save', array($node));
  }
  while (!empty($op_images['delete'])) {
    $nid = array_shift($op_images['delete']);
    $operations[] = array('node_gallery_api_batch_node_delete', array($nid));
  }
  while (!empty($op_images['rotate'])) {
    $params = array_shift($op_images['rotate']);
    $operations[] = array('node_gallery_api_batch_rotate', $params);
  }

  $form_state['redirect'] = 'node/' . $form_state['values']['gallery_nid'];
  if (!empty($operations)) {
    $batch = array(
      'operations' => $operations,
      'finished' => 'node_gallery_api_batch_item_process_finished',
      'title' => t("Modifying Images"),
      'init_message' => t("Images modification process is starting."),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Images modification has encountered an error.'),
      'file' => drupal_get_path('module', 'node_gallery_api') . '/node_gallery_api.inc',
    );

    batch_set($batch);
    // For memory management, we wipe the values from the form since
    // it's all on the $operations array now.
    $tmp = $form_state['values']['form_build_id'];
    $form_state = array();
    $form_state['programmed'] = FALSE;
    $form_state['values']['form_build_id'] = $tmp;
    $form = array();
  }
}

/**
 * Gallery Item edit form.
 */
function node_gallery_api_item_edit_form($form_values, $image, $relationship_type, &$entire_form_state) {
  module_load_include('inc', 'node', 'node.pages');
  $form_state = array(
    'values' => $form_values,
    'build_info' => array('args' => array($image)),
    'method' => 'post',
  );

  $display_fields = $relationship_type->settings['manage_items']['items_fields'];
  $form = drupal_retrieve_form($image->type . '_node_form', $form_state);
  drupal_prepare_form($image->type . "_node_form", $form, $form_state);

  // Keep all fields that are added to form state, as some are retrieved from
  // form state during validation and submit (such as for Taxonomy auto-complete
  // fields) and need to be accessible at all times.
  if (isset($form_state['field'])) {
    $entire_form_state['field'] = isset($entire_form_state['field']) ? array_merge($form_state['field'], $entire_form_state['field']) : $form_state['field'];
  }

  $item_form = array();
  $display_fields['#node'] = '#node';

  foreach (array_values($display_fields) as $field_name) {
    if (!empty($field_name) && !empty($form[$field_name])) {
      $item_form[$field_name] = $form[$field_name];
    }
  }
  $item_form += (array) node_gallery_api_get_item_form_value_items($form);
  node_gallery_api_set_item_form_default_values($item_form, $image, $relationship_type);
  $item_form = node_gallery_api_flatten_item_edit_form($item_form);


  foreach (element_children($item_form) as $key) {
    $element = &$item_form[$key];
    if (isset($element['#theme']) && $element['#theme'] == 'content_multiple_values') {
      // We need to override several properties for multi-value fields.
      $nid = $item_form['#node']->nid;
      $fieldname = $element['#field_name'];
      $field_name_css = str_replace('_', '-', $fieldname);
      $item_form[$key]['#prefix'] = '<div id="' . $field_name_css . '-items-' . $nid . '">';
      $item_form[$key][$fieldname . '_add_more-' . $nid] = $item_form[$key][$fieldname . '_add_more'];
      $item_form[$key][$fieldname . '_add_more-' . $nid]['#ahah']['wrapper'] = $field_name_css . '-items-' . $nid;
      // Change the path of the AHAH call.
      $item_form[$key][$fieldname . '_add_more-' . $nid]['#ahah']['path'] = 'node-gallery/json/js_add_more/' . $image->type . '/' . $fieldname;
      $item_form[$key][$fieldname . '_add_more-' . $nid]['#name'] = $fieldname . '_add_more-' . $nid;
      unset($item_form[$key][$fieldname . '_add_more']);
      $item_form[$key]['#theme'] = 'node_gallery_content_multiple_values';
    }
  }
  return $item_form;
}

/**
 * Get item edit for values.
 */
function node_gallery_api_get_item_form_value_items($form) {
  if ($children = element_children($form)) {
    foreach ($children as $child) {
      if (isset($form[$child]['#type']) && ($form[$child]['#type'] == 'value' || $form[$child]['#type'] == 'hidden')) {
        $value_forms[$child] = $form[$child];
      }
    }
  }
  elseif (isset($form['#type']) && ($form['#type'] == 'value' || $form['#type'] == 'hidden')) {
    $value_forms[key($form)] = $form;
  }
  return $value_forms;
}

/**
 * Item form default values.
 */
function node_gallery_api_set_item_form_default_values(&$form, $image, $relationship_type) {
  global $user;

  if (empty($form['title'])) {
    $form['title'] = array(
      '#type' => 'hidden',
      '#value' => empty($image->title) ? basename($image->{$relationship_type->filefield_name}[0]['filepath']) : $image->title,
    );
  }
  else {
    $form['title']['#default_value'] = empty($form['title']['#default_value']) ? basename($image->{$relationship_type->filefield_name}[0]['filepath']) : $form['title']['#default_value'];
  }

  if (!empty($form['body_field'])) {
    $form['body'] = $form['body_field']['body'];
    $form['body']['#rows'] = 3;
    unset($form['body_field']);
  }

  if (!empty($form['changed']) && empty($form['changed']['#value'])) {
    $form['changed']['#value'] = REQUEST_TIME;
  }
  if (user_access('administer nodes') && !isset($form['author'])) {
    $form['name'] = array(
      '#type' => 'value',
      '#value' => $image->name ? $image->name : $user->name,
    );
  }
  if (!empty($form['uid']) && empty($form['uid']['#value'])) {
    $form['uid']['#value'] = $user->uid;
  }
}

/**
 * Eliminates any fieldsets from the image item edit form.
 */
function node_gallery_api_flatten_item_edit_form($form_item, &$flattened = array(), $inheritance = array()) {
  if (empty($form_item) || !is_array($form_item)) {
    return $form_item;
  }
  if (empty($flattened)) {
    // We start with the whole form, because nested values will be overwritten.
    $flattened = $form_item;
  }
  foreach (element_children($form_item) as $key) {
    $element = $form_item[$key];
    if (isset($element['#type']) && $element['#type'] == 'fieldset') {
      if (isset($element['#tree']) && !empty($element['#tree'])) {
        // We have to keep this as its tree preserving. just remove fieldset.
        unset($element['#type']);
        $flattened[$key] = $element;
      }
      else {
        // This overwrites the old level if existing, so the field
        // inherits title and weight from the 'deepest' fieldset.
        $inheritance['#title'] = $element['#title'];
        $inheritance['#weight'] = $element['#weight'];
        unset($flattened[$key]);
        node_gallery_api_flatten_item_edit_form($element, $flattened, $inheritance);
        $inheritance = array();
      }
    }
    else {
      $flattened[$key] = array_merge($inheritance, $element);
    }
  }
  return $flattened;
}


/**
 * Displays the content of the "Upload Items" tab.
 *
 * @param object $gallery
 *   A populated node gallery object which will house the items.
 *
 * @return string
 *   HTML output.
 */
function node_gallery_api_upload_items_form($gallery, $item_type = NULL) {
  global $user;

  if ($gallery->nid > 0) {
    // node_gallery_set_user_breadcrumb($gallery->uid, $gallery);
  }
  $relationship_type = node_gallery_api_get_relationship_type($gallery->type);
  if (empty($item_type)) {
    $item_type = $relationship_type->item_types[0];
  }

  if (module_exists('plupload') && variable_get('node_gallery_api_plupload_integration', TRUE)) {
    if (!empty($gallery->edit_after_plupload)) {
      $settings = array(
        'ngid' => $gallery->nid,
        'galleryType' => $gallery->type,
        'url_prefix' => variable_get('clean_url', 0) > 0 ? '' : '?q=',
        'token' => drupal_get_token('node_gallery_plupload'),
      );
      drupal_add_js(array('node_gallery' => $settings), array('type' => 'setting', 'scope' => JS_DEFAULT));
      drupal_add_js(drupal_get_path('module', 'node_gallery') . '/js/ng_plupload.js');
    }
    $output = drupal_get_form('node_gallery_api_plupload_form', $relationship_type, $gallery->nid, $item_type);

    return $output;
  }

  // Pull the image type from the relationship, and display it's form:
  $node = new stdClass();
  $node->type = $item_type;
  $node->uid = $user->uid;
  $node->name = (isset($user->name) ? $user->name : '');
  $node->language = LANGUAGE_NONE;
  $node->node_gallery_target_id = $gallery->nid;
  $node->node_gallery_field_name = 'node_gallery_ref_' . $relationship_type->id;

  $form_state['build_info']['args'][] = $node;
  form_load_include($form_state, 'inc', 'node', 'node.pages');
  $form = drupal_build_form($item_type . '_node_form', $form_state);

  return $form;
}

/**
 * Plupload integration form.
 */
function node_gallery_api_plupload_form($form, $form_state, $relationship_type, $ngid, $item_type) {
  $instance = field_info_instance('node', $relationship_type->filefield_name, $item_type);
  $allowed_extensions = !empty($instance['settings']['file_extensions']) ? $instance['settings']['file_extensions'] : 'jpg jpeg gif png txt doc xls pdf ppt pps odt ods odp';
  $file_max_size = !empty($instance['settings']['max_filesize']) ? parse_size($instance['settings']['max_filesize']) : file_upload_max_size();
  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $form['upload'] = array(
    '#type' => 'plupload',
    '#upload_validators' => array(
      'file_validate_extensions' => array($allowed_extensions),
      'file_validate_size' => array($file_max_size),
    ),
    '#plupload_settings' => array(
      'max_file_size' => $file_max_size,
      'url' => url('node-gallery/json/item/create/' . $relationship_type->id . '/' . $ngid . '/' . $item_type . '/' . drupal_get_token('node_gallery_api_item_create')),
    ),
  );

  $form['relationship_type'] = array(
    '#type' => 'value',
    '#value' => $relationship_type,
  );
  $form['#attached']['js'][] = drupal_get_path('module', 'node_gallery_api') . '/js/ng_plupload.js';
  return $form;
}

/**
 * Create item from file. Form Plupload.
 */
function node_gallery_api_create_item_from_file($uri, $original_filename, $relationship_type_id, $ngid, $item_type) {
  global $user;
  $relationship_type = node_gallery_api_get_relationship_type(NULL, NULL, $relationship_type_id);
  $instance = field_info_instance('node', $relationship_type->filefield_name, $item_type);

  // Get file schema from field settings.
  $scheme = variable_get('file_default_scheme', 'public') . '://';
  $fields = field_info_fields();
  if (!empty($fields[$instance['field_name']]['settings']['uri_scheme'])) {
    $scheme = $fields[$instance['field_name']]['settings']['uri_scheme'] . '://';
  }

  if (!empty($instance['settings']['file_directory'])) {
    $destination_dir = $scheme . token_replace($instance['settings']['file_directory']);
    $destination_filename = $destination_dir . '/' . $original_filename;
  }
  else {
    $destination_filename = $scheme . $original_filename;
  }
  file_prepare_directory($destination_dir, FILE_CREATE_DIRECTORY);
  $destination = file_stream_wrapper_uri_normalize($destination_filename);
  $destination = file_unmanaged_move($uri, $destination, FILE_EXISTS_RENAME);
  $file = plupload_file_uri_to_object($destination);
  $file->display = 1;
  file_save($file);
  $item = new stdClass();
  $item->type = $item_type;
  $item->uid = $user->uid;
  $item->name = $user->name;
  $item->title = $original_filename;
  $item->{$relationship_type->filefield_name}[LANGUAGE_NONE][0] = (array) $file;
  $fieldname = node_gallery_api_get_item_field_name(NULL, NULL, $relationship_type->id);
  $item->{$fieldname}[LANGUAGE_NONE][0]['target_id'] = $ngid;
  // Get gallery published status and set item to be the same.
  $item->status = db_select('node', 'n')->fields('n', array('status'))->condition('n.nid', $ngid)->execute()->fetchField();
  $item->language = LANGUAGE_NONE;
  node_object_prepare($item);
  node_save($item);
  return $item;
}

/**
 * Create item from JSON. For Plupload integration.
 */
function node_gallery_api_json_create_item($relationship_type_id, $ngid, $item_type, $token) {
  if (!drupal_valid_token($token, 'node_gallery_api_item_create')) {
    drupal_access_denied();
    return;
  }

  // The following code comes almost entirely from plupload_handle_uploads.
  // @todo: Implement file_validate_size();
  // Added a variable for this because in HA environments, temporary may need
  // to be a shared location for this to work.
  $temp_directory = variable_get('plupload_temporary_uri', 'temporary://');
  $writable = file_prepare_directory($temp_directory, FILE_CREATE_DIRECTORY);
  if (!$writable) {
    die('{"jsonrpc" : "2.0", "error" : {"code": 104, "message": "Failed to open temporary directory."}, "id" : "id"}');
  }
  // Try to make sure this is private via htaccess.
  file_create_htaccess($temp_directory, TRUE);

  // Chunk it?
  $chunk = isset($_REQUEST["chunk"]) ? ($_REQUEST["chunk"] + 1) : 0;

  // Get and clean the filename.
  $file_name = isset($_REQUEST["name"]) ? $_REQUEST["name"] : '';
  $file_name = _plupload_fix_temporary_filename($file_name);

  // Check the file name for security reasons; it must contain letters, numbers
  // and underscores followed by a (single) ".tmp" extension. Since this check
  // is more stringent than the one performed in plupload_element_value(), we
  // do not need to run the checks performed in that function here. This is
  // fortunate, because it would be difficult for us to get the correct list of
  // allowed extensions to pass in to file_munge_filename() from this point in
  // the code (outside the form API).
  if (empty($file_name) || !preg_match('/^\w+\.tmp$/', $file_name)) {
    die('{"jsonrpc" : "2.0", "error" : {"code": 105, "message": "Invalid temporary file name."}, "id" : "id"}');
  }

  // Look for the content type header.
  if (isset($_SERVER["HTTP_CONTENT_TYPE"])) {
    $content_type = $_SERVER["HTTP_CONTENT_TYPE"];
  }
  if (isset($_SERVER["CONTENT_TYPE"])) {
    $content_type = $_SERVER["CONTENT_TYPE"];
  }

  // Is this a multipart upload?
  if (strpos($content_type, "multipart") !== FALSE) {
    if (isset($_FILES['file']['tmp_name']) && is_uploaded_file($_FILES['file']['tmp_name'])) {
      // Open temp file.
      $out = fopen($temp_directory . $file_name, $chunk == 0 ? "wb" : "ab");
      if ($out) {
        // Read binary input stream and append it to temp file.
        $in = fopen($_FILES['file']['tmp_name'], "rb");

        if ($in) {
          while ($buff = fread($in, 4096)) {
            fwrite($out, $buff);
          }
          fclose($in);
        }
        else {
          die('{"jsonrpc" : "2.0", "error" : {"code": 101, "message": "Failed to open input stream."}, "id" : "id"}');
        }

        fclose($out);
        drupal_unlink($_FILES['file']['tmp_name']);
      }
      else {
        die('{"jsonrpc" : "2.0", "error" : {"code": 102, "message": "Failed to open output stream."}, "id" : "id"}');
      }
    }
    else {
      die('{"jsonrpc" : "2.0", "error" : {"code": 103, "message": "Failed to move uploaded file."}, "id" : "id"}');
    }
  }
  else {
    // Open temp file.
    $out = fopen($temp_directory . $file_name, $chunk == 0 ? "wb" : "ab");
    if ($out) {
      // Read binary input stream and append it to temp file.
      $in = fopen("php://input", "rb");

      if ($in) {
        while ($buff = fread($in, 4096)) {
          fwrite($out, $buff);
        }
        fclose($in);
      }
      else {
        die('{"jsonrpc" : "2.0", "error" : {"code": 101, "message": "Failed to open input stream."}, "id" : "id"}');
      }

      fclose($out);
    }
    else {
      die('{"jsonrpc" : "2.0", "error" : {"code": 102, "message": "Failed to open output stream."}, "id" : "id"}');
    }
  }

  if (empty($chunk) || $chunk >= $_REQUEST["chunks"]) {
    // At this point, we have a valid file. Create an item node from it.
    $item = node_gallery_api_create_item_from_file($temp_directory . $file_name, $_REQUEST['filename'], $relationship_type_id, $ngid, $item_type);
    if (!empty($item->nid)) {
      $_SESSION['node_gallery_api_plupload_nids'][$ngid][] = $item->nid;
    }
    if (!$item) {
      die('{"jsonrpc" : "2.0", "error" : {"code": 104, "message": "Failed to create item node."}, "id" : "id"}');
    }
  }

  // Return JSON-RPC response.
  die('{"jsonrpc" : "2.0", "result" : null, "id" : "id"}');
}

/**
 * Submit handler for our "Upload Items" form.
 */
function node_gallery_api_upload_items_form_submit($form, &$form_state) {
  global $user;
  $item = new stdClass();
  $item->uid = $user->uid;
  $item->name = (isset($user->name) ? $user->name : '');
  $values = $form_state['values'];
  foreach ($values as $key => $value) {
    $item->$key = $value;
  }
  node_save($item);
  drupal_set_message(t('Created new item node %title.', array('%title' => $item->title)));
}
