<?php
/**
 * @file
 * c4m_content_minisite.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_minisite_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_minisite_node_info() {
  $items = array(
    'minisite_page' => array(
      'name' => t('Minisite Page'),
      'base' => 'node_content',
      'description' => t('A Minisite is the master page of a group book. It is not used to store any content; we need the master page so users can add and rearrange subpages.
It is a Book powered content type that allows users to create pages and structure them hierarchically.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
