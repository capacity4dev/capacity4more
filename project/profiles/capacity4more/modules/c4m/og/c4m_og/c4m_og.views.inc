<?php
/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_plugins().
 */
function c4m_og_views_plugins() {
  $plugins = array(
    'access' => array(
      'c4m_og_access_og_context' => array(
        'title' => t('User has access to the OG context'),
        'help' => t('this is a custom access plugin'),
        'handler' => 'c4m_og_access_plugin',
        'path' => drupal_get_path('module', 'c4m_og'),
        'uses options' => TRUE,
      ),
    ),
    'argument default' => array(
      'c4m_og_features_argument_default_enabled' => array(
        'title' => t('Enabled features for the active group'),
        'handler' => 'c4m_og_features_argument_default_enabled',
        'path' => drupal_get_path('module', 'c4m_og') . '/plugins/views',
      ),
    ),
  );
  return $plugins;
}
