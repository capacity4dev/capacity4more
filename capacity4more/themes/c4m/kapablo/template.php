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
  $tag['element'] = array(
    '#tag' => 'ul',
    '#attributes' => array(
      'id' => '',
      // It will be made collapsible and it will be expanded only for the sub
      // menu of an active menu item.
      // (So we expand current page + first generation children.
      // See kapablo_menu_link__book_toc() for that.
      'role' => array('menu'),
    ),
    '#value' => $variables['tree'],
  );

  return theme_html_tag($tag);
}

/**
 * Overrides theme_menu_link() for book module.
 * Add bootstrap collapsible behaviour to all expandable links.
 *
 * @param array $variables
 * @return string
 */
function kapablo_menu_link__book_toc(array $variables) {
  $element = $variables['element'];
  $sub_menu = drupal_render($element['#below']);

  $link_options = $element['#localized_options'];
  $element['#attributes']['role'] = 'presentation';
  $active = FALSE;
  if (($element['#href'] == $_GET['q'] ||
      ($element['#href'] == '<front>' && drupal_is_front_page())) &&
      (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
    // We expand current page + first generation children
    // We will replace class 'collapse' set in
    // kapablo_menu_tree__book_toc__sub_menu() by 'collapse in'.
    $active = TRUE;
  }

  $replacement = $icon = '';
  if (!empty($sub_menu) &&
      $mlid = $element['#original_link']['mlid']) {
    // The list item should contain an icon which should act as a bootstrap
    // collapse toggle control to hide/show the submenu (= child pages).

    $submenu_id = 'children-of-' . $mlid;

    // See kapablo_menu_tree__book_toc__sub_menu().
    $tag['element'] = array(
      '#tag' => 'span',
      '#attributes' => array(
        // Tell the span element it is a collapse toggle control.
        'data-toggle' => 'collapse',
        // Tell the control which is the target to be controlled.
        'data-target' => '#' . $submenu_id,
        // Give it class as well for easy theming.
        'class' => array('toggle'),
      ),
      '#value' => '',
    );
    if (!$active) {
      $tag['element']['#attributes']['class'][] = 'collapsed';
    }
    else {
      $tag['element']['#attributes']['class'][] = 'expanded';
    }

    $icon = theme_html_tag($tag);

    // Prepare to replace id of submenu.
    // Make all subclasses collapsible.
    $submenu_classes = 'collapse';
    // And expand only if current menu item is active or a child menu item is
    // active. We know the latter by the class 'in' being already present.
    if ($active ||
        strpos($sub_menu, 'collapse in') !== FALSE) {
      $submenu_classes .= ' in';
    }

    $replacement = 'id="' . $submenu_id . '" class="' . $submenu_classes . '"';
  }
  // We replace previously placed empty id by id + classes.
  // So we remove the id if unnecessary or set the id on the target to be
  // controlled by the data toggle controller.
  // We replace classes also like this to prevent that we replace classes
  // of submenus in submenus.
  $sub_menu = preg_replace('/id=\"\"/', $replacement, $sub_menu);

  $link = l($element['#title'], $element['#href'], $link_options);

  return '<li' . drupal_attributes($element['#attributes']) . '>' .
    $icon . $link . $sub_menu . "</li>\n";
}
