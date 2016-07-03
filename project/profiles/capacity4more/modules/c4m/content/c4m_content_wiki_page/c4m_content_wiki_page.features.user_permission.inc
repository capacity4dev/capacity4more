<?php
/**
 * @file
 * c4m_content_wiki_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_content_wiki_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create wiki_page content'.
  $permissions['create wiki_page content'] = array(
    'name' => 'create wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any wiki_page content'.
  $permissions['delete any wiki_page content'] = array(
    'name' => 'delete any wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own wiki_page content'.
  $permissions['delete own wiki_page content'] = array(
    'name' => 'delete own wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any wiki_page content'.
  $permissions['edit any wiki_page content'] = array(
    'name' => 'edit any wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own wiki_page content'.
  $permissions['edit own wiki_page content'] = array(
    'name' => 'edit own wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
