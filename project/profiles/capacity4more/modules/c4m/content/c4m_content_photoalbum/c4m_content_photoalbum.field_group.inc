<?php

/**
 * @file
 * c4m_content_photoalbum.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_photoalbum_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_actions|node|photoalbum|full';
  $field_group->group_name = 'group_node_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'photoalbum';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Do more through capacity4dev',
    'weight' => '6',
    'children' => array(
      0 => 'c4m_ds_node_highlight',
      1 => 'c4m_ds_content_actions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Do more through capacity4dev',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-actions',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_node_actions|node|photoalbum|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_meta|node|photoalbum|full';
  $field_group->group_name = 'group_node_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'photoalbum';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group meta author',
    'weight' => '5',
    'children' => array(
      0 => 'c4m_user_picture',
      1 => 'c4m_user_first_and_last_name',
      2 => 'c4m_ds_update_date',
      3 => 'c4m_ds_entity_type_label',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group meta author',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-meta field-group clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_node_meta|node|photoalbum|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Do more through capacity4dev');
  t('Group meta author');

  return $field_groups;
}
