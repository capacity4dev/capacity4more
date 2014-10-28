<?php
/**
 * @file
 * c4m_content_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Minisite Page'),
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
