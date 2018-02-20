<?php

/**
 * @file
 * c4m_features_og_group_dashboard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_features_og_group_dashboard_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag subscribe_c4m_follow_content'.
  $permissions['flag subscribe_c4m_follow_content'] = array(
    'name' => 'flag subscribe_c4m_follow_content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_c4m_follow_group'.
  $permissions['flag subscribe_c4m_follow_group'] = array(
    'name' => 'flag subscribe_c4m_follow_group',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_c4m_follow_node'.
  $permissions['flag subscribe_c4m_follow_node'] = array(
    'name' => 'flag subscribe_c4m_follow_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_c4m_follow_term'.
  $permissions['flag subscribe_c4m_follow_term'] = array(
    'name' => 'flag subscribe_c4m_follow_term',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_c4m_follow_content'.
  $permissions['unflag subscribe_c4m_follow_content'] = array(
    'name' => 'unflag subscribe_c4m_follow_content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_c4m_follow_group'.
  $permissions['unflag subscribe_c4m_follow_group'] = array(
    'name' => 'unflag subscribe_c4m_follow_group',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_c4m_follow_node'.
  $permissions['unflag subscribe_c4m_follow_node'] = array(
    'name' => 'unflag subscribe_c4m_follow_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_c4m_follow_term'.
  $permissions['unflag subscribe_c4m_follow_term'] = array(
    'name' => 'unflag subscribe_c4m_follow_term',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
