<?php
/**
 * @file
 * c4m_features_overview_topics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_overview_topics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_overview_topics_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
