<?php

/**
 * @file
 * c4m_og_group_menu.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_og_group_menu_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:administer og menu'
  $permissions['node:group:administer og menu'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:project:administer og menu'
  $permissions['node:project:administer og menu'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
