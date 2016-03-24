<?php
/**
 * @file
 * c4m_content_organisation.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_organisation_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_domain'.
  $field_bases['c4m_domain'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_domain',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'c4m_content_organisation',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'c4m_domain',
  );

  // Exported field_base: 'c4m_icon'.
  $field_bases['c4m_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_icon',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
