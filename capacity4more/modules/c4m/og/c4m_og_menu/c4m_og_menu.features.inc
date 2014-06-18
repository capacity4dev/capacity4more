<?php
/**
 * @file
 * c4m_og_menu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_og_menu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
