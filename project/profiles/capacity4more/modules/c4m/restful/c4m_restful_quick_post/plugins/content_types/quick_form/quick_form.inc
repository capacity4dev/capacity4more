<?php

/**
 * @file
 * QuickPost form plugin for RestFul.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Quick post form'),
  'description' => t('Renders Quick Post form.'),
  'required context' => array(
    new ctools_context_required(t('Group'), 'og_context'),
  ),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_restful_quick_post_quick_form_content_type_render($subtype, $conf, $args, $context) {
  $group_id = $context[0]->data->nid;

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = c4m_restful_quick_post_form($group_id);
  return $block;
}

/**
 * Edit form.
 */
function c4m_restful_quick_post_quick_form_content_type_edit_form($form, &$form_state) {
  return $form;
}
