<?php
/**
 * @file
 * c4m_content_news_item.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_news_item_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_news_item_node_info() {
  $items = array(
    'news_item' => array(
      'name' => t('News item'),
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
