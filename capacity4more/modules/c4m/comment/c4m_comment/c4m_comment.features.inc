<?php
/**
 * @file
 * c4m_comment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_comment_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
