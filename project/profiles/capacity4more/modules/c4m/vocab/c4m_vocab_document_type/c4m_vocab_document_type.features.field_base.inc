<?php
/**
 * @file
 * c4m_vocab_document_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_vocab_document_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_vocab_document_type'.
  $field_bases['c4m_vocab_document_type'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_vocab_document_type',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'c4m_vocab_document_type',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
