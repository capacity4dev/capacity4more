<?php
/**
 * @file
 * c4m_content_tasklist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_tasklist_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_tasklist_node_info() {
  $items = array(
    'tasklist' => array(
      'name' => t('Task list'),
      'base' => 'node_content',
      'description' => t('A Tasklist is used within Groups and Projects.
It groups tasks.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
