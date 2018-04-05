<?php

/**
 * @file
 * c4m_content_topic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_topic_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_header_bottom|node|topic|full';
  $field_group->group_name = 'c4m_header_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'c4m_vocab_topic_mapping',
      1 => 'c4m_ds_topic_content_stats',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-c4m-header-bottom field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['c4m_header_bottom|node|topic|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_header_meta|node|topic|full';
  $field_group->group_name = 'c4m_header_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'topic';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'c4m_body',
      1 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-c4m-header-meta field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['c4m_header_meta|node|topic|full'] = $field_group;

  return $field_groups;
}
