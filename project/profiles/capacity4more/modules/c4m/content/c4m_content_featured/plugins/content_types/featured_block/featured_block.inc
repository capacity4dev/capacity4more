<?php

/**
 * @file
 * Plugin to render the featured block pane.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Featured block'),
  'description' => t('Renders Featured nodes.'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_content_featured_featured_block_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_content_featured';
  $block->title = '';
  $block->content = c4m_content_featured_render_featured_blocks();
  return $block;
}

/**
 * Edit form.
 */
function c4m_content_featured_featured_block_content_type_edit_form($form, &$form_state) {
  return $form;
}
