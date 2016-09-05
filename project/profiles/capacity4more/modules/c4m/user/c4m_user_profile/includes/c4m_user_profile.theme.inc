<?php

/**
 * @file
 * Theme functions for the c4m_content module.
 */

/**
 * Theme function for user full name with profile picture.
 *
 * @param array $variables
 *    Array with theme variables.
 *
 * @return string
 *    The rendered output.
 */
function theme_c4m_user_profile_picture_fullname(array $variables) {
  $output = '';
  if (empty($variables['user'])) {
    return $output;
  }

  $user         = $variables['user'];
  $user_wrapper = entity_metadata_wrapper('user', $user);
  $fullname   = '<div class="fullname">' . t('Hello !name', array('!name' => c4m_user_name($user))) . '</div>';

  $picture    = $user_wrapper->c4m_media->value();
  if (empty($picture)) {
    // If there is no image, we render initials.
    $picture = c4m_user_get_themed_initials(c4m_user_get_user_initials($user));
  }
  else {
    $picture = array(
      '#theme'      => 'image_style',
      '#style_name' => 'icon_small',
      '#path'       => $picture['uri'],
      '#attributes' => array(
        'class' => array('profile-picture img-circle'),
      ),
    );
    $picture = render($picture);
  }

  // Render the user full name with the profile picture.
  $profile = array(
    '#theme'      => 'html_tag',
    '#tag'        => 'div',
    '#value'      => $picture . $fullname . '<i class="fa fa-chevron-down"></i>',
    '#attributes' => array(
      'class' => array('fullname-picture'),
    ),
  );
  $profile = render($profile);

  // Wrap this content in a link (if set).
  if (!empty($variables['link'])) {
    $options = isset($variables['link']['options'])
                  ? $variables['link']['options'] : array();
    $profile = l($profile, $variables['link']['url'], $options);
  }

  $output = $profile;
  return $output;
}

/**
 * Theme function for user profile menu.
 *
 * @param array $variables
 *    Array with theme variables.
 *
 * @return string
 *    The rendered output.
 */
function theme_c4m_user_profile_menu(array $variables) {
  $output = '';
  if (empty($variables['menu_items'])) {
    return $output;
  }

  $items      = $variables['menu_items'];
  $attributes = $variables['attributes'];

  $links = array();
  foreach ($items as $key => $item) {
    $links[] = l($item['title'], $item['url'], $item['options']);
  }

  $output = array(
    '#theme'      => 'item_list',
    '#items'      => $links,
    '#attributes' => $attributes,
  );

  return render($output);
}

/**
 * Theme function for user groups top bar menu.
 *
 * @param array $variables
 *    Array with theme variables.
 *
 * @return string
 *    The rendered output.
 */
function theme_c4m_user_profile_groups_top_bar(array $variables) {
  $menu_title = array(
    '#theme' => 'html_tag',
    '#tag' => 'div',
    '#value' => t('My Groups'),
    '#attributes' => array(
      'class' => array('fullname'),
    ),
  );
  // Adding the icon before the title of the menu, leaving it outside of the
  // title so it won't be hidden on mobile screens.
  $menu_title = '<i class="fa fa-users"></i>' . render($menu_title);

  $menu = array(
    '#theme'      => 'html_tag',
    '#tag'        => 'div',
    '#value'      => $menu_title . '<i class="fa fa-chevron-down"></i>',
    '#attributes' => array(
      'class' => array('fullname-picture'),
    ),
  );
  $menu = render($menu);

  $output = l($menu, $variables['link']['url'], $variables['link']['options']);

  return $output;
}
