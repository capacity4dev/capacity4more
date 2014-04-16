<?php
/**
 * @file
 * c4m_content_tasklist.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_tasklist_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_tasklist_status'
  $field_bases['c4m_tasklist_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_tasklist_status',
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
        0 => 'Close',
        1 => 'Open',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
