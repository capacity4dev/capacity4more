<?php
/**
 * @file
 * c4m_field_media.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_field_media_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_media'.
  $field_bases['c4m_media'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_media',
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
