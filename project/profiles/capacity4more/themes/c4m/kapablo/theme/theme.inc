<?php

/**
 * @file
 * Theme hooks.
 */

/**
 * Implements hook_theme().
 */
function kapablo_theme() {
  $theme['kapablo_search_advanced_help'] = array(
    'template' => 'kapablo_search_advanced_help',
    'path' => drupal_get_path('theme', 'kapablo') . '/templates',
    'type' => 'theme',
    'variables' => array(),
  );

  return $theme;
}
