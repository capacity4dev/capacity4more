<?php
/**
 * @file
 * c4m_content_page_element.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_page_element_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_content_page_element_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4m_content_page_element_node_info() {
  $items = array(
    'page_element' => array(
      'name' => t('Page element'),
      'base' => 'node_content',
      'description' => t('Page element.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
