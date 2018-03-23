<?php

/**
 * @file
 * c4m_features_og_group_dashboard.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_features_og_group_dashboard_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:invite any user'
  $permissions['node:group:invite any user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:invite any user'
  $permissions['node:project:invite any user'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
