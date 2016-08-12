<?php
/**
 * @file
 * c4m_og_invite.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_og_invite_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'og_membership-og_membership_type_default-og_membership_invitation'.
  $field_instances['og_membership-og_membership_type_default-og_membership_invitation'] = array(
    'bundle' => 'og_membership_type_default',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This marks the membership as an invitation.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'og_membership',
    'field_name' => 'og_membership_invitation',
    'label' => 'Invitation',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Invitation');
  t('This marks the membership as an invitation.');

  return $field_instances;
}
