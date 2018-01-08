<?php

/**
 * @file
 * Creates calendar displays of Views results.
 */

/**
 * Implements hook_views_plugins().
 */
function c4m_features_overview_events_views_plugins() {
  $module_path = drupal_get_path('module', 'c4m_features_overview_events');

  // Limit these plugins to base tables that represent entities.
  $base = array_keys(date_views_base_tables());

  $data = array(
    'module' => 'c4m_features_overview_events',

    'row' => array(
      'c4m_event_row' => array(
        'title' => t('C4M - Calendar row'),
        'help' => t('Displays each selected entity as a Calendar item.'),
        'handler' => 'c4m_features_overview_events_views_plugin_row',
        'theme' => 'views_view_fields',
        'path' => "$module_path/views/plugins",
        'base' => $base,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
  return $data;
}
