<?php

/**
 * @file
 * c4m_content_share.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_share_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_source_entity'.
  $field_bases['c4m_source_entity'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_source_entity',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'discussion' => 'discussion',
          'document' => 'document',
          'event' => 'event',
          'photo' => 'photo',
          'photoalbum' => 'photoalbum',
          'wiki_page' => 'wiki_page',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
