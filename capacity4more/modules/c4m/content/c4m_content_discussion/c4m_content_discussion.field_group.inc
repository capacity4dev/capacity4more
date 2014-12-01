<?php
/**
 * @file
 * c4m_content_discussion.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_discussion_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_details|node|discussion|full';
  $field_group->group_name = 'group_node_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'discussion';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '14',
    'children' => array(
      0 => 'c4m_related_topic',
      1 => 'c4m_vocab_date',
      2 => 'c4m_vocab_geo',
      3 => 'c4m_vocab_language',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-node-details field-group-fieldset',
      ),
    ),
  );
  $export['group_node_details|node|discussion|full'] = $field_group;

  return $export;
}
