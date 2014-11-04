<?php
/**
 * @file
 * c4m_content_group.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_content_group_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_related_group'
  $field_bases['c4m_related_group'] = array(
    'active' => 1,
    'cardinality' => 3,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_related_group',
    'foreign keys' => array(),
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
          'direction' => 'ASC',
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'group' => 'group',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_membership_requests'
  $field_bases['field_membership_requests'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_membership_requests',
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
        'open' => '<strong>Open</strong><span>Any member of capacity4dev who has access to this Group can become a member without approval by the Group owner or one of the Group administrators.</span>',
        'moderated' => '<strong>Moderated</strong><span>Any member of capacity4dev who has access to this Group can request membership. The Group owner or one of the Group administrators needs to approve the request.</span>',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
