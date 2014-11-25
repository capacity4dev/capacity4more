<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Quick post form'),
  'description' => t('Renders Quick Post form.'),
  'required context' => array(
    new ctools_context_required(t('Group'), 'og_context'),
    new ctools_context_optional(t('Node'), 'node'),
    new ctools_context_optional(t('String'), 'string'),
  ),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_restful_quick_post_quick_form_content_type_render($subtype, $conf, $args, $context) {
  $gid = $context[0]->data->nid;
  $nid = $context[1]->data ? $context[1]->data->nid : NULL;
  $content_type = $context[2]->data;

  $resources = array(
    'discussion' => array(
      'discussions' => array(
        'bundle' => 'Discussion',
        'description' => t('Add a Discussion'),
      )
    ),
    'event' => array(
      'events' => array(
        'bundle' => 'Event',
        'description' => t('Add an Event'),
      )
    ),
    'document' => array(
      'documents' => array(
        'bundle' => 'Document',
        'description' => t('Upload a Document'),
      ),
    ),
  );
  $node = $nid ? node_load($nid) : NULL;
  if ($node && in_array($node->type, array_keys($resources))) {
    $show_resources = $resources[$node->type];
    $full_form = TRUE;
  }
  else {
    $show_resources = $content_type && isset($resources[$content_type]) ? $resources[$content_type] : array();
    $full_form = $content_type && isset($resources[$content_type]) ? TRUE : FALSE;
  }

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = c4m_restful_quick_post_form($gid, $show_resources, $full_form, $node);
  return $block;
}

/**
 * Edit form.
 */
function c4m_restful_quick_post_quick_form_content_type_edit_form($form, &$form_state) {
  return $form;
}
