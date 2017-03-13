<?php
/**
 * @file
 * c4m_og.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_og_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_og_total_comments'.
  $field_bases['c4m_og_total_comments'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_og_total_comments',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'c4m_og_total_posts'.
  $field_bases['c4m_og_total_posts'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_og_total_posts',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
