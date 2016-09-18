<?php

/**
 * @file
 * Views plugins.
 */

/**
 * Implements hook_views_plugins().
 */
function c4m_content_book_views_plugins() {
  $plugins = array(
    'module' => 'c4m_content_book',
    'argument default' => array(
      'c4m_content_book_plugin_argument_default' => array(
        'title' => t('C4M book help pages'),
        'handler' => 'c4m_content_book_plugin_argument_default',
        'path' => drupal_get_path('module', 'c4m_content_book') . '/includes',
        'theme path' => drupal_get_path('module', 'views') . '/theme',
        'theme file' => 'theme.inc',
        // So that the parent class is included.
        'parent' => 'fixed',
      ),
    ),
  );

  return $plugins;
}
