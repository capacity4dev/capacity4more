<?php
/**
 * @file
 * c4m_features_overview_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_overview_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_overview_homepage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function c4m_features_overview_homepage_node_info() {
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
