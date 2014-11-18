<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Quick post form'),
  'description' => t('Renders Quick Post form.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_restful_quick_post_quick_form_content_type_render($subtype, $conf, $args, $context) {
  $nid = $context->data->nid;

  $node_viewed = node_load($nid);
  if ($node_viewed->type == 'discussion') {
    $show_resources = array('discussions' => array(
      'bundle' => 'Discussion',
      'description' => 'Add a Discussion',
    ));
    $full_form = TRUE;
    $node = $node_viewed;
    $group_id = entity_metadata_wrapper('node', $nid)->{OG_AUDIENCE_FIELD}->nid->value();
  }
  else {
    $group_id = $nid;
    $show_resources = array();
    $full_form = FALSE;
    $node = NULL;
  }

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = c4m_restful_quick_post_form($group_id, $show_resources, $full_form, $node);
  return $block;
}

/**
 * Edit form.
 */
function c4m_restful_quick_post_quick_form_content_type_edit_form($form, &$form_state) {
  return $form;
}
