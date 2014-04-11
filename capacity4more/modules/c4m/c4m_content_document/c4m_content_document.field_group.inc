<?php
/**
 * @file
 * c4m_content_document.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_document_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_metadata|node|document|form';
  $field_group->group_name = 'c4m_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '3',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4d-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['c4m_metadata|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_og|node|document|form';
  $field_group->group_name = 'c4m_og';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'OG',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'OG',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-og field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['c4m_og|node|document|form'] = $field_group;

  return $export;
}
