<?php
/**
 * @file
 * c4m_features_overview_events.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_overview_events_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'events';
  $path_breadcrumb->name = 'Events';
  $path_breadcrumb->path = 'events';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Events',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -99;
  $export['events'] = $path_breadcrumb;

  return $export;
}
