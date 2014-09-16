<?php
/**
 * @file
 * c4m_activity_comment.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_activity_comment_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'message-c4m_activity_comment_delete-c4m_activity_comment'
  $field_instances['message-c4m_activity_comment_delete-c4m_activity_comment'] = array(
    'bundle' => 'c4m_activity_comment_delete',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The comment where this message is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_comment',
    'label' => 'comment',
    'required' => 1,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_comment_delete-c4m_activity_group'
  $field_instances['message-c4m_activity_comment_delete-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_comment_delete',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The (optional) group the comment belongs to.',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_comment_delete-c4m_activity_node'
  $field_instances['message-c4m_activity_comment_delete-c4m_activity_node'] = array(
    'bundle' => 'c4m_activity_comment_delete',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The node where this comment message is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_node',
    'label' => 'node',
    'required' => 1,
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

  // Exported field_instance: 'message-c4m_activity_comment_insert-c4m_activity_comment'
  $field_instances['message-c4m_activity_comment_insert-c4m_activity_comment'] = array(
    'bundle' => 'c4m_activity_comment_insert',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The comment where this message is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_comment',
    'label' => 'comment',
    'required' => 1,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_comment_insert-c4m_activity_group'
  $field_instances['message-c4m_activity_comment_insert-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_comment_insert',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The (optional) group the comment belongs to.',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_comment_insert-c4m_activity_node'
  $field_instances['message-c4m_activity_comment_insert-c4m_activity_node'] = array(
    'bundle' => 'c4m_activity_comment_insert',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The node where this comment message is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_node',
    'label' => 'node',
    'required' => 1,
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

  // Exported field_instance: 'message-c4m_activity_comment_update-c4m_activity_comment'
  $field_instances['message-c4m_activity_comment_update-c4m_activity_comment'] = array(
    'bundle' => 'c4m_activity_comment_update',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The comment where this message is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_comment',
    'label' => 'comment',
    'required' => 1,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_comment_update-c4m_activity_group'
  $field_instances['message-c4m_activity_comment_update-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_comment_update',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The (optional) group the comment belongs to.',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_comment_update-c4m_activity_node'
  $field_instances['message-c4m_activity_comment_update-c4m_activity_node'] = array(
    'bundle' => 'c4m_activity_comment_update',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The node where this comment message is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_node',
    'label' => 'node',
    'required' => 1,
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
  t('The comment where this message is about.');
  t('The (optional) group the comment belongs to.');
  t('The node where this comment message is about.');
  t('comment');
  t('group');
  t('node');

  return $field_instances;
}
