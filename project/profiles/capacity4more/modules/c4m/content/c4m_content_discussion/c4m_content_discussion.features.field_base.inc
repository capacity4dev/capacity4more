<?php
/**
 * @file
 * c4m_content_discussion.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_discussion_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_discussion_type'.
  $field_bases['c4m_discussion_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_discussion_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'info' => 'Share Information',
        'idea' => 'Share an Idea',
        'question' => 'Ask a Question',
        'debate' => 'Start a Debate',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
