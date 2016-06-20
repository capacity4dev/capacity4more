<?php
/**
 * @file
 * Plugin to show the left side of the project page.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Project page left'),
  'description' => t('Renders the contents of the left side of a project page.'),
  'category' => t('C4M'),
  'render callback' => 'c4m_content_project_page_left_render',
);

/**
 * Run time rendering of the left side of the project page.
 *
 * @return object
 *   The block definition.
 */
function c4m_content_project_page_left_render() {
  if ($group = og_context()) {
    if ($node = node_load($group['gid'])) {
      $block = new stdClass();
      $block->content = field_view_field('node', $node, 'c4m_left_column', array('label' => 'hidden'));
      $block->title = '';
      $block->id = 'project_page_left';

      return $block;
    }
  }

  return '';
}
