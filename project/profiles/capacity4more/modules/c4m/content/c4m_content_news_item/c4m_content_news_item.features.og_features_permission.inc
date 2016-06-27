<?php
/**
 * @file
 * c4m_content_news_item.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function c4m_content_news_item_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:create news_item content'
  $permissions['node:group:create news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any news_item content'
  $permissions['node:group:delete any news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own news_item content'
  $permissions['node:group:delete own news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any news_item content'
  $permissions['node:group:update any news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own news_item content'
  $permissions['node:group:update own news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:create news_item content'
  $permissions['node:project:create news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete any news_item content'
  $permissions['node:project:delete any news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:delete own news_item content'
  $permissions['node:project:delete own news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update any news_item content'
  $permissions['node:project:update any news_item content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:project:update own news_item content'
  $permissions['node:project:update own news_item content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
