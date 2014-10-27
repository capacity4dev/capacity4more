<?php
/**
 * @file
 * c4m_content_blog.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_blog_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_discussion_type'
  $field_bases['field_discussion_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_discussion_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'inforamtion' => 'Information',
        'idea' => 'Idea',
        'question' => 'Question',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
