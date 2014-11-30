<?php
/**
 * @file
 * c4m_content_groupbanner.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_groupbanner_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_groupbanner_node_info() {
  $items = array(
    'group_banner' => array(
      'name' => t('Group banner'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
