<?php
/**
 * @file
 * c4m_user_bar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_user_bar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
