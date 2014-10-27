<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Quick post'),
  'description' => t('Renders Quick Post.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_features_overview_quick_post_quick_post_content_type_render($subtype, $conf, $args, $context) {
  $nid = $context->data->nid;

  $block = new stdClass();
  $block->module = 'c4m_feature_overview_quick_post';
  $block->title = '';
  $block->content = c4m_features_overview_quick_post_form($nid);
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_overview_quick_post_quick_post_content_type_edit_form($form, &$form_state) {
  return $form;
}
