<?php
/**
 * @file
 * c4m_message.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_message_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'message-c4m_insert__node__discussion-field_node_discussion_ref'
  $field_instances['message-c4m_insert__node__discussion-field_node_discussion_ref'] = array(
    'bundle' => 'c4m_insert__node__discussion',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'field_node_discussion_ref',
    'label' => 'node discussion ref',
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
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('node discussion ref');

  return $field_instances;
}
