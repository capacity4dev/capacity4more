<?php

/**
 * @file
 * Template functions.
 */

/**
 * theme_menu_tree__MENU_ID().
 *
 * Add bootstrap classes to the menu to style it as a horizontal menu (default bootstrap).
 *
 * @param $variables
 *
 * @return string
 */
function kapablo_menu_tree__menu_group_menu($variables) {
  return '<ul class="menu nav nav-pills nav-justified" role="tablist">' . $variables['tree'] . '</ul>';
}

/**
 * Activity stream messages preprocess.
 */
function kapablo_preprocess_message(&$variables) {
  if ($variables['view_mode'] != 'activity_stream') {
    return;
  }

  $message = $variables['message'];
  $variables['theme_hook_suggestions'][] = 'message__activity_stream';
  $variables['theme_hook_suggestions'][] = "message__{$message->type}__activity_stream";

  $variables['content'] = $message->getText();

  // Getting the name of the icon image file from the message type.
  $icon_type = explode('__', $message->type);

  $icon_entity_type = $icon_type[1];

  $icon_name = 'missing';

  if ($icon_entity_type == 'node') {
    // Icon image file name is content type of the node.
    $icon_name = $icon_type[2];

    if ($icon_name == 'discussion') {
      $message_wrapper = entity_metadata_wrapper('message', $message);
      // Icon image file name is the discussion type of the discussion node.
      $icon_name = $message_wrapper->field_node->c4m_discussion_type->value();
    }
  }

  $image_path = drupal_get_path('theme', 'kapablo') . '/images/activity_stream_icons';
  $icon_variables = array(
    'path' => $image_path . '/' . $icon_name . '.png',
    'attributes' => array(
      'class' => 'img-responsive',
    )
  );
  $variables['icon'] = theme('image', $icon_variables);
}


/**
 * Node preprocess.
 */
function kapablo_preprocess_node(&$variables) {
  if ($variables['view_mode'] == 'activity_stream') {
    $variables['theme_hook_suggestions'][] = 'node__activity_stream';
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->type . '__activity_stream';
  }
  $preprocess_function = "kapablo_preprocess_node__{$variables['node']->type}";
  if (function_exists($preprocess_function)) {
    $preprocess_function($variables);
  }
}

/**
 * Node event preprocess.
 */
function kapablo_preprocess_node__event(&$variables) {
  if ($variables['view_mode'] != 'activity_stream') {
    // Current view mode is not an 'activity stream'.
    return;
  }

  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  $start = $node_wrapper->c4m_datetime_end->value->value();
  $end = $node_wrapper->c4m_datetime_end->value2->value();

  $start_date = format_date($start ,'custom', 'd/m/Y');
  $end_date = format_date($end ,'custom', 'd/m/Y');

  $start_date_time = format_date($start ,'custom', 'd/m/Y H:i');
  $end_date_time = $start_date == $end_date ? format_date($end ,'custom', 'H:i') : format_date($end ,'custom', 'd/m/Y H:i');

  $variables['event_info'] = t('From @start to @end', array('@start' => $start_date_time, '@end' => $end_date_time));
}

/**
 * Node document preprocess.
 */
function kapablo_preprocess_node__document(&$variables) {
  if ($variables['view_mode'] != 'activity_stream') {
    // Current view mode is not an 'activity stream'.
    return;
  }

  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  $document = $node_wrapper->c4m_document->value();
  if (empty($document)) {
    // There is no file.
    $variables['download_link'] = '';
    $variables['file_info'] = '';
    return;
  }

  $file_uri = file_load($document['fid']);
  $download = file_entity_download_uri($file_uri);
  $variables['download_link'] = l(t('Download this Document'), $download['path'], $download['options']);
  $file_size = format_size($document['filesize']);
  $file_type = $document['type'];
  $variables['file_info'] = t('Filetype: @filetype | Filesize: @filesize', array('@filetype' => $file_type, '@filesize' => $file_size));
}
