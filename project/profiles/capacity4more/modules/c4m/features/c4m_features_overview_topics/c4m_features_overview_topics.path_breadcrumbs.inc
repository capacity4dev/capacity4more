<?php
/**
 * @file
 * c4m_features_overview_topics.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_overview_topics_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'topics';
  $path_breadcrumb->name = 'Topics';
  $path_breadcrumb->path = 'topics';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Topics',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -95;
  $export['topics'] = $path_breadcrumb;

  return $export;
}
