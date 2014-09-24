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

  // Exported field_instance: 'message-c4m_activity_og_approve-c4m_activity_group'
  $field_instances['message-c4m_activity_og_approve-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_approve',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_approve-c4m_activity_user'
  $field_instances['message-c4m_activity_og_approve-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_approve',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_block-c4m_activity_group'
  $field_instances['message-c4m_activity_og_block-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_block',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_block-c4m_activity_user'
  $field_instances['message-c4m_activity_og_block-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_block',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_unblock-c4m_activity_group'
  $field_instances['message-c4m_activity_og_unblock-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_unblock',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_unblock-c4m_activity_user'
  $field_instances['message-c4m_activity_og_unblock-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_unblock',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_request-c4m_activity_group'
  $field_instances['message-c4m_activity_og_request-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_request',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_request-c4m_activity_user'
  $field_instances['message-c4m_activity_og_request-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_request',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_join-c4m_activity_group'
  $field_instances['message-c4m_activity_og_join-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_join',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_join-c4m_activity_user'
  $field_instances['message-c4m_activity_og_join-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_join',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user where membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_leave-c4m_activity_group'
  $field_instances['message-c4m_activity_og_leave-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_leave',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_leave-c4m_activity_user'
  $field_instances['message-c4m_activity_og_leave-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_leave',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_reject-c4m_activity_group'
  $field_instances['message-c4m_activity_og_reject-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_reject',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_reject-c4m_activity_user'
  $field_instances['message-c4m_activity_og_reject-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_reject',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_remove-c4m_activity_group'
  $field_instances['message-c4m_activity_og_remove-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_remove',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_remove-c4m_activity_user'
  $field_instances['message-c4m_activity_og_remove-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_remove',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'message-c4m_activity_og_revoke-c4m_activity_group'
  $field_instances['message-c4m_activity_og_revoke-c4m_activity_group'] = array(
    'bundle' => 'c4m_activity_og_revoke',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The group the membership is about.',
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

  // Exported field_instance: 'message-c4m_activity_og_revoke-c4m_activity_user'
  $field_instances['message-c4m_activity_og_revoke-c4m_activity_user'] = array(
    'bundle' => 'c4m_activity_og_revoke',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'The user the membership is about.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'message',
    'field_name' => 'c4m_activity_user',
    'label' => 'user',
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('The user the membership is about.');
  t('The group the membership is about.');
  t('group');
  t('user');

  return $field_instances;
}
