<?php
/**
 * @file
 * c4m_content_group.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_group_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|group|c4m_dashboard';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'c4m_dashboard';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More details',
    'weight' => '4',
    'children' => array(
      0 => 'c4m_related_topic',
      1 => 'c4m_vocab_geo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More details',
      'instance_settings' => array(
        'classes' => 'group-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_details|node|group|c4m_dashboard'] = $field_group;

  return $export;
}
