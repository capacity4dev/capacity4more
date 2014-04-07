<?php
/**
 * @file
 * c4m_content_region.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_region_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_region_node_info() {
  $items = array(
    'region' => array(
      'name' => t('Region'),
      'base' => 'node_content',
      'description' => t('A region provides a page where content related to the Region can be grouped.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
