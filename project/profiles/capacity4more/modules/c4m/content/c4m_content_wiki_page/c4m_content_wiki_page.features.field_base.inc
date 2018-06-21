<?php

/**
 * @file
 * c4m_content_wiki_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_wiki_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_edit_by_members'.
  $field_bases['c4m_edit_by_members'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_edit_by_members',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'FALSE',
        1 => 'TRUE',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
