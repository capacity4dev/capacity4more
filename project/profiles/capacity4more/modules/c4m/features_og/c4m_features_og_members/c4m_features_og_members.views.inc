<?php

/**
 * @file
 * Views plugins.
 */

/**
 * Implements hook_views_plugins().
 */
function c4m_features_og_members_views_plugins() {
  $plugins = array(
    'module' => 'c4m_features_og_members',
    'argument default' => array(
      'c4m_features_og_members_plugin_argument_default' => array(
        'title' => t('C4M group members'),
        'handler' => 'c4m_features_og_members_plugin_argument_default',
        'path' => drupal_get_path('module', 'c4m_features_og_members') . '/includes',
        'theme path' => drupal_get_path('module', 'views') . '/theme',
        'theme file' => 'theme.inc',
        // So that the parent class is included.
        'parent' => 'fixed',
      ),
    ),
  );

  return $plugins;
}
