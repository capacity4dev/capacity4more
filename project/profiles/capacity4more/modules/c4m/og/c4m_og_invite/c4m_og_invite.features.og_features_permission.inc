<?php
/**
 * @file
 * c4m_og_invite.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_og_invite_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:invite any user'
  $permissions['node:group:invite any user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:invite people'
  $permissions['node:group:invite people'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:invite any user'
  $permissions['node:project:invite any user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:project:invite people'
  $permissions['node:project:invite people'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}