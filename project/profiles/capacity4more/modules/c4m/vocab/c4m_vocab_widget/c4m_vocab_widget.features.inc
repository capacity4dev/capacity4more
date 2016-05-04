<?php
/**
 * @file
 * c4m_vocab_widget.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_vocab_widget_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}
