<?php

/**
 * @file
 * c4m_user_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_user_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer Terms and Conditions'.
  $permissions['administer Terms and Conditions'] = array(
    'name' => 'administer Terms and Conditions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'view Terms and Conditions'.
  $permissions['view Terms and Conditions'] = array(
    'name' => 'view Terms and Conditions',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'legal',
  );

  return $permissions;
}
