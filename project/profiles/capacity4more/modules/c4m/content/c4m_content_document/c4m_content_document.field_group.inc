<?php

/**
 * @file
 * c4m_content_document.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_document_field_group_info() {
  $field_groups = array();

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
    'label' => 'Groups',
    'weight' => '10',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Groups',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-og field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_og|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_actions|node|document|full';
  $field_group->group_name = 'group_node_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Do more through capacity4dev',
    'weight' => '10',
    'children' => array(
      0 => 'c4m_ds_node_highlight',
      1 => 'c4m_ds_node_promote',
      2 => 'c4m_ds_content_actions',
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
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_node_actions|node|document|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_details|node|document|full';
  $field_group->group_name = 'group_node_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '11',
    'children' => array(
      0 => 'c4m_vocab_date',
      1 => 'c4m_vocab_document_type',
      2 => 'c4m_vocab_geo',
      3 => 'c4m_vocab_language',
      4 => 'c4m_vocab_topic',
      5 => 'og_vocabulary',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-details field-group-fieldset clearfix',
        'wrapper' => 'section',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_node_details|node|document|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_meta|node|document|full';
  $field_group->group_name = 'group_node_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group meta',
    'weight' => '9',
    'children' => array(
      0 => 'c4m_user_picture',
      1 => 'c4m_user_first_and_last_name',
      2 => 'c4m_ds_update_date',
      3 => 'c4m_ds_entity_type_label',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group meta',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-meta field-group clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_node_meta|node|document|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Do more through capacity4dev');
  t('Group meta');
  t('Groups');

  return $field_groups;
}
