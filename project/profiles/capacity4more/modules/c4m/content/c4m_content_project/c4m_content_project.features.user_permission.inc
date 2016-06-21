<?php
/**
 * @file
 * c4m_content_project.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_content_project_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer paragraphs bundles'.
  $permissions['administer paragraphs bundles'] = array(
    'name' => 'administer paragraphs bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'paragraphs',
  );

  return $permissions;
}
