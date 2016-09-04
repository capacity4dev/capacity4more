<?php

/**
 * @file
 * Block definitions for the user profile.
 */

/**
 * Block definition for the top bar (user region).
 *
 * Shows user menu (dropdown).
 *
 * @return array
 *   The block definition.
 */
function _c4m_user_profile_block_user_menu() {
  $block = array();
  $block['subject'] = '';

  if (user_is_anonymous()) {
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
    'view_profile' => array(
      'title'   => t('View Profile'),
      'url'     => 'user',
      'options' => array(
        'purl'  => array(
          'disabled' => TRUE,
        ),
      ),
    ),
    'edit_profile' => array(
      'title'   => t('Edit Profile'),
      'url'     => 'user/' . $user->uid . '/edit/',
      'options' => array(
        'purl'  => array(
          'disabled' => TRUE,
        ),
      ),
    ),
    'user_content' => array(
      'title'   => t('My content'),
      'url'     => 'user/' . $user->uid . '/content/',
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
 * Block definition for the user_is_invalid_email block.
 *
 * @return array
 *   The block definition.
 */
function _c4m_user_profile_block_user_is_invalid_email() {
  global $user;

  $edit_path = 'user/' . $user->uid . '/edit';
  if (current_path() !== $edit_path) {
    drupal_goto($edit_path);
  }

  $block = array();
  $block['subject'] = '';

  $block['content'] = t('<div class="well alert"><h3>Your email is no longer valid</h3><p>It seems that the email you used to register on !site !mail is no longer valid.</p><p>Please udpate your profile accordingly.</p><p>Please !contact_us if you think this is a mistake.</div>', array(
    '!site' => variable_get('site_name'),
    '!mail' => l($user->mail, 'mailto:' . $user->mail, array('absolute' => TRUE)),
    '!contact_us' => l(t('contact us'), 'mailto:capacity4dev@ec.europa.eu', array('absolute' => TRUE)),
  ));

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
              'class'         => array('fullname-picture-wrapper', 'dropdown-toggle'),
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

/**
 * Block definition for the user_confirm_email block.
 *
 * @return array
 *   The block definition.
 */
function _c4m_user_profile_block_user_confirm_email() {
  $block = array();
  $block['subject'] = '';

  $block['content'] = t('<div class="well bg-warning"><h3>Your email needs to be confirmed</h3><p>Please check your inbox to confirm your new email address.</p></div>');

  return $block;
}

/**
 * Block definition for the user_my_profile_groups block.
 *
 * @return array
 *   The rendered "my groups" block.
 */
function _c4m_user_profile_block_user_my_profile_groups() {
  module_load_include('inc', 'c4m_features_homepage', 'plugins/content_types/my_groups/my_groups');
  if (!$account = menu_get_object('user')) {
    return;
  }

  $groups = c4m_features_homepage_get_user_groups_grouped_by_membership($account, array('group'));

  $block = array();
  $block['subject'] = '';
  $block['content'] = '';
  if (empty($groups)) {
    return $block;
  }

  $rendered_groups = '';
  // Render node views for each group.
  foreach ($groups as $type => $group_list) {
    $title = c4m_user_profile_get_group_type_title($type);
    $rendered_groups .= '<h3>' . $title . '</h3>';

    foreach ($group_list as $group) {
      $node_view = node_view($group, 'block_list');
      $rendered_groups .= drupal_render($node_view);
    }
  }

  $variables = array(
    'groups' => $rendered_groups,
  );

  $block['content'] = !empty($rendered_groups) ? theme('c4m_user_profile_my_profile_groups', $variables) : FALSE;

  return $block;
}

/**
 * Returns the title for the type of membership of a group.
 *
 * @param string $type
 *   The group membership type.
 *
 * @return string
 *   The translated title for the membership type.
 */
function c4m_user_profile_get_group_type_title($type) {
  $titles = array(
    'owner' => t('Groups I own'),
    'administrator' => t('Groups I manage'),
    'member' => t("Groups I'm member of"),
    'pending' => t('Membership requested'),
  );

  return $titles[$type];
}
