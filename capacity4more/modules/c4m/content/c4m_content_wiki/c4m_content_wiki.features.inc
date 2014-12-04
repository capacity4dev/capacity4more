<?php
/**
 * @file
 * c4m_content_wiki.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_wiki_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_wiki_node_info() {
  $items = array(
    'wiki' => array(
      'name' => t('Wiki'),
      'base' => 'node_content',
      'description' => t('A "wiki" is the master page of a book. It is not used to store any content; we need the master wiki so users can add and rearrange subpages.
It is a Book powered content type that allows users to create wiki pages and structure them hierarchically.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
