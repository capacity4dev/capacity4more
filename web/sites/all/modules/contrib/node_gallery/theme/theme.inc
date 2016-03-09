<?php

/**
 * @file
 * Node gallery theme functions
 */

/**
 * Theme function for Manage Items form.
 */
function theme_node_gallery_api_manage_items_form($variables) {
  $form = $variables['form'];

  if (empty($form['items'])) {
    return t('This gallery is empty.');
  }
  // Pull in the multi-select functionality from core.
  drupal_add_js('misc/tableselect.js');
  // Get fieldname to retrieve the filepath for the thumbnail without
  // loading the node.
  $relationship_type = node_gallery_api_get_relationship_type($form['#gallery']->type);
  $enable_rotation = FALSE;
  if ($relationship_type->settings['manage_items']['enable_rotation'] && (image_get_toolkit() != 'gd' || function_exists("imagerotate"))) {
    $enable_rotation = TRUE;
    drupal_add_library('system', 'ui.dialog');
    drupal_add_library('system', 'ui.draggable');
    drupal_add_library('system', 'ui.resizable');
    drupal_add_js(drupal_get_path('module', 'node_gallery') . '/js/ng_manage_images.js');
  }
  $header = array(
    array(
      'data' => t('Delete'),
      'class' => 'select-all',
    ),
    t('Preview'),
    t('Edit'),
    t('Cover'),
  );
  if ($enable_rotation) {
    $header = array(
      array(
        'data' => t('Delete'),
        'class' => 'select-all',
      ),
      t('Preview'),
      t('Edit'),
      t('Rotation'),
      t('Cover'),
    );
  }
  $rows = array();
  foreach (element_children($form['items']) as $nid) {
    $element = &$form['items'][$nid];

    $row = array();
    $row[] = drupal_render($element['remove']);
    $file = $element['item_file']['#value'];
    if (!empty($file)) {
      $file_object = (object) $file;
      $file_view = file_view($file_object, 'node_gallery_api_admin_thumbnail');
      $row[] = drupal_render($file_view);
    }
    else {
      $row[] = '';
    }
    $edit = drupal_render($element['edit_form']);
    if (!empty($element['ngid'])) {
      $edit .= drupal_render($element['ngid']);
    }
    $row[] = $edit;
    if ($enable_rotation && !empty($file) && $file['type'] == 'image') {
      $row[] = drupal_render($element['rotate']);
    }
    elseif ($enable_rotation) {
      drupal_render($element['rotate']);
      $row[] = '';
    }
    if ($form['is_cover']) {
      $row[] = drupal_render($form['is_cover'][$nid]);
    }
    $rows[] = array('data' => $row);
  }
  $output = theme('table',
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array('id' => 'upload-attachments'),
    )
  );
  $output .= theme('pager');
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Theme function for multiple content values.
 */
function theme_node_gallery_content_multiple_values($variables) {
  $element = $variables['element'];
  $nid = $element['#parents'][1];
  $field_name = $element['#field_name'];
  $field = content_fields($field_name);
  $output = '';

  if ($field['multiple'] >= 1) {
    $table_id = $element['#field_name'] . '_values-' . $nid;
    $order_class = $element['#field_name'] . '-delta-order';
    $required = !empty($element['#required']) ? '<span class="form-required" title="' . t('This field is required.') . '">*</span>' : '';

    $header = array(
      array(
        'data' => t('!title: !required', array('!title' => $element['#title'], '!required' => $required)),
        'colspan' => 2,
      ),
      t('Order'),
    );
    $rows = array();

    // Sort items according to '_weight' (needed when the form comes back after
    // preview or failed validation).
    $items = array();
    foreach (element_children($element) as $key) {
      if ($key !== $element['#field_name'] . '_add_more-' . $nid) {
        $items[] = &$element[$key];
      }
    }
    usort($items, '_content_sort_items_value_helper');

    // Add the items as table rows.
    foreach ($items as $key => $item) {
      $item['_weight']['#attributes']['class'] = $order_class;
      $delta_element = drupal_render($item['_weight']);
      $cells = array(
        array(
          'data' => '',
          'class' => 'content-multiple-drag',
        ),
        drupal_render($item),
        array(
          'data' => $delta_element,
          'class' => 'delta-order',
        ),
      );
      $rows[] = array(
        'data' => $cells,
        'class' => 'draggable',
      );
    }

    $output .= theme('table',
      array(
        'header' => $header,
        'rows' => $rows,
        'attributes' => array(
          'id' => $table_id,
          'class' => 'content-multiple-table',
        ),
      )
    );
    $output .= $element['#description'] ? '<div class="description">' . $element['#description'] . '</div>' : '';
    $output .= drupal_render($element[$element['#field_name'] . '_add_more-' . $nid]);

    drupal_add_tabledrag($table_id, 'order', 'sibling', $order_class);
  }
  else {
    foreach (element_children($element) as $key) {
      $output .= drupal_render_children($element[$key]);
    }
  }

  return $output;
}

/**
 * Preprocess function for theme_node_gallery_api_item_navigator().
 */
function template_preprocess_node_gallery_api_item_navigator(&$variables) {
  drupal_add_css(drupal_get_path('module', 'node_gallery_api') . '/node_gallery_api.css');
  $relationship_type = node_gallery_api_get_relationship_type(NULL, $variables['item']->type);
  $fragment = FALSE;
  if ($relationship_type->settings['item_view']['page_fragment']) {
    $fragment = TRUE;
  }
  $entries = array();
  if (isset($variables['navigator']['prev_nid'])) {
    $entries = array_merge($entries, array('prev', 'first'));
  }
  if (isset($variables['navigator']['next_nid'])) {
    $entries = array_merge($entries, array('next', 'last'));
  }
  foreach ($entries as $type) {
    $nid = $variables['navigator'][$type . '_nid'];
    $variables[$type . '_link'] = $fragment ?
      url('node/' . $nid, array('fragment' => 'node-' . $nid)) :
      url('node/' . $nid);
  }
  if (!empty($variables['navigator']['gallery_nid'])) {
    $variables['gallery_link'] = url('node/' . $variables['navigator']['gallery_nid']);
    $gallery = node_load($variables['navigator']['gallery_nid']);
    $variables['gallery_title'] = check_plain($gallery->title);
  }
}

/**
 * Imports the image properties into the variables namespace for easier theming.
 */
function template_preprocess_node_gallery_sort_images_grid_item(&$variables) {
  $variables += $variables['image'];
}


/**
 * Theme function for item sort form.
 */
function theme_node_gallery_api_sort_items_form($variables) {
  $form = $variables['form'];
  $output = '';
  $rows = array();
  $header = array(
    '&uarr;&darr;',
    t('Preview'),
    t('Title'),
    t('Post date'),
    t('Updated date'),
    t('Published'),
    t('Weight'),
  );
  if (variable_get('node_gallery_api_display_exif_creation_date', FALSE)) {
    array_splice($header, 3, 0, t('Creation date'));
  }
  $i = 0;
  foreach ($form['#images'] as $image) {
    $published = ($image['status']) ? t('Yes') : t('No');
    if (!empty($image['file_object'])) {
      $file_object = (object) $image['file_object'];
      $file_view = file_view($file_object, 'node_gallery_api_admin_thumbnail');
    }
    else {
      $file_view = '';
    }

    $row = array(
      // The placeholder for the tabledrag icon.
      '',
      drupal_render($file_view),
      $image['title'],
      format_date($image['created'], 'short'),
      format_date($image['changed'], 'short'),
      $published,
      // The weight drop down.
      drupal_render($form['images-sort-' . $i]),
    );
    if (variable_get('node_gallery_api_display_exif_creation_date', FALSE)) {
      $exif_created = isset($image['exif_created']) ? format_date($image['exif_created']->getTimestamp(), 'short') : t('Unavailable');
      array_splice($row, 3, 0, $exif_created);
    }
    $rows[] = array(
      'data' => $row,
      'class' => array('draggable'),
    );
    $i++;
  }
  // This will replace the weight drop downs with drag&drop when javascript
  // is available.
  drupal_add_tabledrag('sort-images-table', 'order', 'sibling', 'sort');
  $output .= theme('table',
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array('id' => 'sort-images-table'),
    )
  );

  // Render the left over elements, if any.
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Add link to file display.
 *
 * @param array $vars
 *   theme variables
 */
function theme_node_gallery_api_file_display_link($vars) {
  $element = $vars['element'];
  $children = drupal_render($element['#contents']);
  $element['#uri']['options']['html'] = TRUE;
  return l($children, $element['#uri']['path'], $element['#uri']['options']);
}

