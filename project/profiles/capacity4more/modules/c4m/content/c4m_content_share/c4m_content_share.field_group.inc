<?php

/**
 * @file
 * c4m_content_share.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_share_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_content|node|share|activity_global';
  $field_group->group_name = 'group_shared_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'share';
  $field_group->mode = 'activity_global';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shared content',
    'weight' => '1',
    'children' => array(
      0 => 'c4m_source_entity',
      1 => 'title',
      2 => 'c4m_content_share_original_group',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Shared content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-shared-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_shared_content|node|share|activity_global'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_content|node|share|activity_group';
  $field_group->group_name = 'group_shared_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'share';
  $field_group->mode = 'activity_group';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shared content',
    'weight' => '1',
    'children' => array(
      0 => 'c4m_source_entity',
      1 => 'title',
      2 => 'c4m_content_share_original_group',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Shared content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-shared-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_shared_content|node|share|activity_group'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Shared content');

  return $field_groups;
}
