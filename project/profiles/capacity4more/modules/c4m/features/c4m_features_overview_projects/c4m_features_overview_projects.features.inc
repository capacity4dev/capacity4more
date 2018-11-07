<?php

/**
 * @file
 * c4m_features_overview_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_overview_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_overview_projects_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
