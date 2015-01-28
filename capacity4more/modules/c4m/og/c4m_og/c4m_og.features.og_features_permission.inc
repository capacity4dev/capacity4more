<?php
/**
 * @file
 * c4m_og.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_og_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:view unpublished group content'
  $permissions['node:group:view unpublished group content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}
