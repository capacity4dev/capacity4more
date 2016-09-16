<?php

/**
 * @file
 * c4m_features_overview_projects.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_overview_projects_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'projects';
  $path_breadcrumb->name = 'Projects';
  $path_breadcrumb->path = 'projects';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -94;
  $export['projects'] = $path_breadcrumb;

  return $export;
}
