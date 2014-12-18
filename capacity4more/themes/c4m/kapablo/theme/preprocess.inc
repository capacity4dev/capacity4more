<?php
/**
 * @file
 * All preprocess functionality.
 */

/**
 * Implements theme_preprocess_message().
 *
 * Activity stream messages preprocess.
 */
function kapablo_preprocess_message(&$variables) {
  if ($variables['view_mode'] != 'activity_stream') {
    return;
  }

  $message                               = $variables['message'];
  $variables['theme_hook_suggestions'][] = 'message__activity_stream';
  $variables['theme_hook_suggestions'][] = "message__{$message->type}__activity_stream";

  $variables['content'] = $message->getText();

  // Getting the name of the icon image file from the message type.
  $icon_type = explode('__', $message->type);

  $icon_entity_type = $icon_type[1];

  $icon_name = 'missing';

  if ($icon_entity_type == 'comment') {
    $icon_name = 'comment';
  }

  if ($icon_entity_type == 'node') {
    // Icon image file name is content type of the node.
    $icon_name = $icon_type[2];

    if ($icon_name == 'discussion') {
      $message_wrapper = entity_metadata_wrapper('message', $message);
      // Icon image file name is the discussion type of the discussion node.
      $icon_name = 'discussion-' . $message_wrapper->field_node->c4m_discussion_type->value();
    }
  }

  $variables['icon'] = $icon_name;
}

/**
 * Implements theme_preprocess_block().
 */
function kapablo_preprocess_block(&$variables) {
  $block_id        = $variables['block']->module . '-' . $variables['block']->delta;
  $classes         = & $variables['classes_array'];
  $title_classes   = & $variables['title_attributes_array']['class'];
  $content_classes = & $variables['content_attributes_array']['class'];

  // Add classes based on the block delta.
  switch ($block_id) {
    case 'c4m_user_profile-user_welcome':
    case 'c4m_user_profile-user_notifications':
      $classes[] = 'col-sm-12 col-md-6';
      break;
  }
}

/**
 * Implements theme_preprocess_page().
 *
 * @see page.tpl.php
 */
function kapablo_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class_kapablo'] = ' class="col-md-4"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class_kapablo'] = ' class="col-md-8"';
  }
  else {
    $variables['content_column_class_kapablo'] = ' class="col-md-12"';
  }
}

/**
 * Implements template_preprocess_field().
 */
function kapablo_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];
  switch ($element['#field_name']) {
    case 'c4m_ds_group_access_info':
      $group = $element['#object'];
      // Retrieve group access info.
      $group_access = c4m_og_get_access_type($group);

      if (!empty($group_access['type'])) {
        $variables['classes_array'][] = 'group-' .
          drupal_html_class($group_access['type']);
      }
      break;
  }

  $variables['classes_array'][] = 'test';
}