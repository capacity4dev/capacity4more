<?php
/**
 * @file
 * c4m_og_invite.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_og_invite_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'og_membership_invitation'.
  $field_bases['og_membership_invitation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'og_membership',
    ),
    'field_name' => 'og_membership_invitation',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Not an invitation',
        1 => 'Invitation',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
