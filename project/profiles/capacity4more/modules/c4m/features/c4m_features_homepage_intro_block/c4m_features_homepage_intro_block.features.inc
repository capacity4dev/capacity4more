<?php

/**
 * @file
 * c4m_features_homepage_intro_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_homepage_intro_block_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
