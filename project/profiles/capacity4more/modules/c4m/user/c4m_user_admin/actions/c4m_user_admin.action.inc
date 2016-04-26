<?php
/**
 * @file
 * Callback & forms related to the user admin.
 */

/**
 * Custom actions defined by c4m_user_admin module.
 *
 * @return array
 *   Information about the action.
 */
function _c4m_user_admin_action_info() {
  return array(
    'c4m_user_admin_activate_action' => array(
      'type' => 'user',
      'label' => t('Activate user'),
      'configurable' => FALSE,
      'triggers' => array('any'),
    ),
  );
}

/**
 * Performs the 'activate user' action.
 *
 * @param object $user
 *   The user object.
 */
function c4m_user_admin_activate_action($user) {
  $edit['status'] = 1;
  $edit['c4m_is_spammer'] = 0;
  $edit['c4m_is_deleted'] = 0;
  user_save($user, $edit);
}
