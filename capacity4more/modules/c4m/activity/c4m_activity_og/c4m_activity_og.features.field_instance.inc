<?php
/**
 * @file
 * c4m_activity_og.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_activity_og_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'message-c4m_activity_og_request-c4m_activity_group'
  $field_instances['message-c4m_activity_og_request-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_request',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the request is related to.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_group',
    'label' => 'group',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_join-c4m_activity_group'
  $field_instances['message-c4m_activity_og_join-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_join',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the user joined.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_group',
    'label' => 'group',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_leave-c4m_activity_group'
  $field_instances['message-c4m_activity_og_leave-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_leave',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the user left.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_group',
    'label' => 'group',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('The group the request is related to.');
  t('The group the user joined.');
  t('The group the user left.');
  t('group');

  return $field_instances;
}
