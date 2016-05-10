<?php
/**
 * @file
 * Block definitions for the user profile.
 */

/**
 * Block definition for the top bar (user region).
 *
 * Welcomes the user by name + sub-menu or CTA to login.
 *
 * @return array
 *   The block definition.
 */
function _c4m_user_profile_block_user_welcome() {
  $block = array();
  $block['subject'] = '';

  $content = array(
    t('Welcome.'),
    t('Please <a href="@register">register</a> or <a href="@login">login.</a>',
      array(
        '@register' => url('user/register'),
        '@login' => url('user/login'),
      )
    ),
  );

  if (user_is_anonymous()) {
    $block['content'] = '<div class="userbar-user-login">' . implode(' ', $content) . '</div>';
    return $block;
  }

  // We have a loggedin user.
  global $user;
  $user = user_load($user->uid);

  // User fullname + user picture.
  $full_name_picture = c4m_user_profile_render_user_profile(
                            'c4m_user_profile_picture_fullname', $user);

  // User profile menu.
  $menu_list = array(
    'edit_profile' => array(
      'title'   => t('Edit Profile'),
      'url'     => 'user/' . $user->uid . '/edit/',
      'options' => array(
        'purl'  => array(
          'disabled' => TRUE,
        ),
      ),
    ),
    'user_logout' => array(
      'title'   => t('Log out'),
      'url'     => 'user/logout',
      'options' => array(
        'purl'  => array(
          'disabled' => TRUE,
        ),
      ),
    ),
  );

  $menu = array(
    '#theme'      => 'c4m_user_profile_menu',
    '#menu_items'  => $menu_list,
    '#attributes' => array(
      'class' => array('user-profile-menu', 'dropdown-menu'),
    ),
  );
  $menu = render($menu);

  $output = array(
    '#theme'      => 'html_tag',
    '#tag'        => 'div',
    '#value'      => $full_name_picture . $menu,
    '#attributes' => array(
      'class' => array('userbar-userprofile', 'dropdown'),
    ),
  );

  $block['content'] = render($output);
  return $block;
}

/**
 * Block definition for the top bar (user region).
 *
 * Displays number of messages/notifications/...
 *
 * @return array
 *   The block definition.
 */
function _c4m_user_profile_block_user_notifications() {
  $block = array();
  $block['subject'] = '';

  if (user_is_anonymous()) {
    return NULL;
  }

  // @TODO: submenu, theming function...
  $block['content'] = t('# of messages/notifications/...');

  return $block;
}

/**
 * Helper function to render user profile.
 *
 * @param string $theme_function
 *    Name of the theme function to be used.
 * @param object $user
 *    User object.
 *
 * @return string
 *    The rendered output.
 */
function c4m_user_profile_render_user_profile($theme_function, $user) {
  switch ($theme_function) {
    case 'c4m_user_profile_picture_fullname':
      $user_profile = array(
        '#theme'  => 'c4m_user_profile_picture_fullname',
        '#user'   => $user,
        '#link'   => array(
          'url'     => 'user/' . $user->uid,
          'options' => array(
            'attributes'  => array(
              'class'         => array('dropdown-toggle'),
              'data-toggle'   => array('dropdown'),
              'data-disabled' => TRUE,
            ),
            'html' => TRUE,
            'purl'  => array(
              'disabled' => TRUE,
            ),
          ),
        ),
      );
      break;
  }

  return render($user_profile);
}
