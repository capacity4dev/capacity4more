<?php
/**
 * @file
 * c4m_content_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog post'),
      'base' => 'node_content',
      'description' => t('A Blog is used within Groups and Projects.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
