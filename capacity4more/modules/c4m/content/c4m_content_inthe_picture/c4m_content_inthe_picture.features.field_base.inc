<?php
/**
 * @file
 * c4m_content_inthe_picture.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_inthe_picture_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_page'
  $field_bases['field_page'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_page',
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
        'Voices & Views' => 'Voices & Views',
        'Groups' => 'Groups',
        'Projects' => 'Projects',
        'Events' => 'Events',
        'People' => 'People',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
