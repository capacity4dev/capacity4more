<?php
/**
 * @file
 * All theme menu functionality.
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
//  dsm($variables);
  return '<ul class="menu nav navbar-nav" role="tablist">' . $variables['tree'] . '</ul>';
}

function kapablo_menu_link__c4m_og_menu($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    elseif ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] == 1)) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      // Generate as standard dropdown.
      $element['#title'] .= ' <span class="caret"></span>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      $element['#localized_options']['attributes']['data-target'] = '#';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }

  $element['#attributes']['class'][] = 'og-menu-link ' . preg_replace("/[^A-Za-z0-9 ]/", '', $element['#original_link']['link_path']);

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // @TODO: SET ACTIVE TRAIL/CLASS FOR OG!!!

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
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

    // Prepare to replace id of submenu.
    // Make all subclasses collapsible.
    $submenu_classes = 'collapse';
    // And expand only if current menu item is active or a child menu item is
    // active. We know the latter by the class 'active' being already present.
    if ($active ||
      strpos($sub_menu, 'active') !== FALSE) {
      $tag['element']['#attributes']['class'][] = 'expanded';
      $submenu_classes .= ' in';
    }
    else {
      $tag['element']['#attributes']['class'][] = 'collapsed';
    }

    $icon = theme_html_tag($tag);


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
