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
function kapablo_menu_tree__c4m_og_menu($variables) {
  return '<ul class="nav nav-pills nav-justified" role="tablist">' . $variables['tree'] . '</ul>';
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
 * Overrides theme_menu_tree() for book module.
 */
function kapablo_menu_tree__book_toc(&$variables) {
  $output = '<div class="book-toc">';
  $output .= '<ul role="menu">' . $variables['tree'] . '</ul>';
  $output .= '</div>';
  return $output;
}

/**
 * Overrides theme_menu_tree() for book module.
 */
function kapablo_menu_tree__book_toc__sub_menu(&$variables) {
  return '<ul class="menu" role="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_link() for book module.
 */
function kapablo_menu_link__book_toc(array $variables) {
  $element = $variables['element'];
  $sub_menu = drupal_render($element['#below']);
  $element['#attributes']['role'] = 'presentation';
  $link = TRUE;
  if ($element['#title'] && $element['#href'] === FALSE) {
    $element['#attributes']['class'][] = 'dropdown-header';
    $link = FALSE;
  }
  elseif ($element['#title'] === FALSE && $element['#href'] === FALSE) {
    $element['#attributes']['class'][] = 'divider';
    $link = FALSE;
  }
  elseif (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  if ($link) {
    $element['#title'] = l($element['#title'], $element['#href'], $element['#localized_options']);
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $element['#title'] . $sub_menu . "</li>\n";
}
