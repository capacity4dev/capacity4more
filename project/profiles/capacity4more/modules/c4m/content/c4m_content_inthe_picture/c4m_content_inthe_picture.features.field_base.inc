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

  // Exported field_base: 'c4m_heading'.
  $field_bases['c4m_heading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_heading',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'c4m_overview_page'.
  $field_bases['c4m_overview_page'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_overview_page',
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
