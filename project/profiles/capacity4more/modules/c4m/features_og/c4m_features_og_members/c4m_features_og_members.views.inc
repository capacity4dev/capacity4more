<?php

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_plugins().
 */
function c4m_features_og_members_views_plugins() {
  $plugins = [
    'argument default' => [
      'c4m_features_og_members_default_membership_types' => [
        'title' => t('C4M Default membership types for the active group'),
        'handler' => 'c4m_features_og_members_default_membership_types',
        'path' => drupal_get_path('module', 'c4m_features_og_members') . '/includes',
      ],
    ],
  ];
  return $plugins;
}
