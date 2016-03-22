<?php
/**
 * @file
 * c4m_features_og_overview_tasks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_og_overview_tasks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_og_overview_tasks_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
