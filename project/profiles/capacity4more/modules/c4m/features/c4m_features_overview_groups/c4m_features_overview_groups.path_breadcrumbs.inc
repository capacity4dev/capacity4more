<?php
/**
 * @file
 * c4m_features_overview_groups.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_overview_groups_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'groups';
  $path_breadcrumb->name = 'Groups';
  $path_breadcrumb->path = 'groups';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Groups',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -96;
  $export['groups'] = $path_breadcrumb;

  return $export;
}
