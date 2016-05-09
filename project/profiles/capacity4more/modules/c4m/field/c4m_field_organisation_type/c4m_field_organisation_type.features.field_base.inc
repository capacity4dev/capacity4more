<?php
/**
 * @file
 * c4m_field_organisation_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function c4m_field_organisation_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'c4m_organisation_type'.
  $field_bases['c4m_organisation_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'c4m_organisation_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'european_institutions' => 'European Institutions',
        'government' => 'Government',
        'international_organisation' => 'International Organisation',
        'civil_society_ngo' => 'Civil Society / NGO',
        'academic' => 'Academic',
        'private_sector' => 'Private Sector',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
