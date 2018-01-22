<?php

/**
 * @file
 * c4m_message.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_message_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_message_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
