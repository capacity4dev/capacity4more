<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Quick post'),
  'description' => t('Renders Quick Post.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('C4M'),
  'defaults' => array(
    'debug' => FALSE,
  ),
);

/**
 * Render callback.
 */
function c4m_features_overview_quick_post_quick_post_content_type_render($subtype, $conf, $args, $context) {
  $nid = $context->data->nid;

  $debug = $conf['debug'];

  $block = new stdClass();
  $block->module = 'c4m_feature_overview_quick_post';
  $block->title = '';
  $block->content = c4m_features_overview_quick_post_form($nid, $debug);
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_overview_quick_post_quick_post_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['debug'] = array(
    '#title' => t('Debug results'),
    '#type' => 'checkbox',
    '#default_value' => $conf['debug'],
  );
  return $form;
}

/**
 * Edit form submit callback.
 */
function c4m_features_overview_quick_post_quick_post_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['debug'] = $form_state['values']['debug'];
}
