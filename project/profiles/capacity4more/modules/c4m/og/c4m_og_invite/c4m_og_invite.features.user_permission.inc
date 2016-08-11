<?php
/**
 * @file
 * c4m_og_invite.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_og_invite_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'answer any organic group invitation'.
  $permissions['answer any organic group invitation'] = array(
    'name' => 'answer any organic group invitation',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'og_invite',
  );

  return $permissions;
}
