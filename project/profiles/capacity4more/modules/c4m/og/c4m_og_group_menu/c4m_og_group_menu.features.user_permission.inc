<?php

/**
 * @file
 * c4m_og_group_menu.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_og_group_menu_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer og menu'.
  $permissions['administer og menu'] = array(
    'name' => 'administer og menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'og_menu',
  );

  // Exported permission: 'administer og menu configuration'.
  $permissions['administer og menu configuration'] = array(
    'name' => 'administer og menu configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'og_menu',
  );

  return $permissions;
}
