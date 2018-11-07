<?php

/**
 * @file
 * c4m_content_photo.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_photo_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'node_gallery_ref_1'.
  $field_bases['node_gallery_ref_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'node_gallery_ref_1',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'node_gallery',
      'handler_settings' => array(
        'behaviors' => array(
          'node_gallery_behavior' => array(
            'status' => TRUE,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'node_gallery_relationship_type' => 1,
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
