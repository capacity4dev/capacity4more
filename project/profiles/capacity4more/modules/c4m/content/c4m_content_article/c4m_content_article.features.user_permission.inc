<?php
/**
 * @file
 * c4m_content_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function c4m_content_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'bypass maxlength'.
  $permissions['bypass maxlength'] = array(
    'name' => 'bypass maxlength',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'maxlength',
  );

  return $permissions;
}
