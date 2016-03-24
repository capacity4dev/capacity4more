<?php
/**
 * @file
 * c4m_field_body.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_field_body_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_body'.
  $field_bases['c4m_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  return $field_bases;
}
