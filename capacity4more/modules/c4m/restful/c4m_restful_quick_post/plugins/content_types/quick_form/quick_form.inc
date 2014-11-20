<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Quick post form'),
  'description' => t('Renders Quick Post form.'),
  'required context' => array(
    new ctools_context_required(t('Group'), 'og_context'),
    new ctools_context_optional(t('String'), 'string'),
    new ctools_context_optional(t('File'), 'file'),
  ),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_restful_quick_post_quick_form_content_type_render($subtype, $conf, $args, $context) {
  $nid = $context[0]->data->nid;
  $content_type = $context[1]->data;
  $file_id = $context[2]->data ? $context[2]->data->fid : NULL;

  $resources = array(
    'discussion' => array(
      'discussions' => array(
        'bundle' => 'Discussion',
        'description' => 'Add a Discussion',
      )
    ),
    'event' => array(
      'events' => array(
        'bundle' => 'Event',
        'description' => 'Add an Event',
      )
    ),
    'document' => array(
      'documents' => array(
        'bundle' => 'Document',
        'description' => 'Upload a Document',
      ),
    ),
  );
  $node_viewed = node_load($nid);
  if (in_array($node_viewed->type, array_keys($resources))) {
    $show_resources = $resources[$node_viewed->type];
    $full_form = TRUE;
    $node = $node_viewed;
    $group_id = entity_metadata_wrapper('node', $nid)->{OG_AUDIENCE_FIELD}->nid->value();
  }
  else {
    $group_id = $nid;
    $show_resources = $content_type && isset($resources[$content_type]) ? $resources[$content_type] : array();
    $full_form = $content_type && isset($resources[$content_type]) ? TRUE : FALSE;
    $node = NULL;
  }

  $block = new stdClass();
  $block->module = 'c4m_restful_quick_post';
  $block->title = '';
  $block->content = c4m_restful_quick_post_form($group_id, $show_resources, $full_form, $node, $file_id);
  return $block;
}

/**
 * Edit form.
 */
function c4m_restful_quick_post_quick_form_content_type_edit_form($form, &$form_state) {
  return $form;
}
