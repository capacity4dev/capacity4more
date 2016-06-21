<?php
/**
 * @file
 * Plugin to show the right side of the project page.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Project page right'),
  'description' => t('Renders the contents of the right side of a project page.'),
  'category' => t('C4M'),
  'render callback' => 'c4m_content_project_page_right_render',
);

/**
 * Run time rendering of the right side of the project page.
 *
 * @return object
 *   The block definition.
 */
function c4m_content_project_page_right_render() {
  $block = new stdClass();
  if ($group = og_context()) {
    if ($node = node_load($group['gid'])) {
      $block->id = 'project_page_right';
      $block->title = '';
      $block->content = field_view_field('node', $node, 'c4m_right_column', array('label' => 'hidden'));
    }
  }

  return $block;
}
