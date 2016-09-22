<?php
/**
 * @file
 * c4m_features_homepage.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_features_homepage_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'home';
  $path_breadcrumb->name = 'Home';
  $path_breadcrumb->path = 'node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Home',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -81;
  $export['home'] = $path_breadcrumb;

  return $export;
}
