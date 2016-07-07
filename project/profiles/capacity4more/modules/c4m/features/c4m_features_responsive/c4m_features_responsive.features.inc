<?php

/**
 * @file
 * c4m_features_responsive.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_responsive_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
