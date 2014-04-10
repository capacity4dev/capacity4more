<?php
/**
 * @file
 * c4m_content_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_project_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_project_details|node|project|form';
  $field_group->group_name = 'c4m_project_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project details',
    'weight' => '6',
    'children' => array(
      0 => 'c4m_date',
      1 => 'c4m_source_of_funding',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4m-project-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['c4m_project_details|node|project|form'] = $field_group;

  return $export;
}
