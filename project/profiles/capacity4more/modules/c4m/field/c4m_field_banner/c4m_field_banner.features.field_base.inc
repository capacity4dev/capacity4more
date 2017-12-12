<?php

/**
 * @file
 * c4m_field_banner.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_field_banner_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_banner'.
  $field_bases['c4m_banner'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_banner',
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
