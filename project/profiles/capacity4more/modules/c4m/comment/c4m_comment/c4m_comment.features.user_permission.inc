<?php

/**
 * @file
 * c4m_comment.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_comment_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'delete all comment replies'.
  $permissions['delete all comment replies'] = array(
    'name' => 'delete all comment replies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_comment_delete',
  );

  // Exported permission: 'delete any comment'.
  $permissions['delete any comment'] = array(
    'name' => 'delete any comment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_comment_delete',
  );

  // Exported permission: 'delete any comments at anytime'.
  $permissions['delete any comments at anytime'] = array(
    'name' => 'delete any comments at anytime',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_comment_delete',
  );

  // Exported permission: 'delete own comments'.
  $permissions['delete own comments'] = array(
    'name' => 'delete own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'c4m_comment_delete',
  );

  // Exported permission: 'delete own comments at anytime'.
  $permissions['delete own comments at anytime'] = array(
    'name' => 'delete own comments at anytime',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_comment_delete',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'move all replies up'.
  $permissions['move all replies up'] = array(
    'name' => 'move all replies up',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'c4m_comment_delete',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
