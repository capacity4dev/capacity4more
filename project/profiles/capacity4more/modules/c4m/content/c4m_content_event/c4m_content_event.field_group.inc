<?php

/**
 * @file
 * c4m_content_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_documents|node|event|form';
  $field_group->group_name = 'c4m_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '10',
    'children' => array(
      0 => 'c4m_document_agenda',
      1 => 'c4m_document_presentation',
      2 => 'c4m_related_document',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-c4m-documents field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['c4m_documents|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_metadata|node|event|form';
  $field_group->group_name = 'c4m_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '12',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_language',
      2 => 'c4m_vocab_topic',
      3 => 'og_vocabulary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4m-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_metadata|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_og|node|event|form';
  $field_group->group_name = 'c4m_og';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '13',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Groups',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4m-og field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_og|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|event|full';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '12',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_language',
      2 => 'c4m_vocab_topic',
      3 => 'og_vocabulary',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-details field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_documents|node|event|full';
  $field_group->group_name = 'group_documents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '7',
    'children' => array(
      0 => 'c4m_document_agenda',
      1 => 'c4m_document_presentation',
      2 => 'c4m_related_document',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Documents',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-documents field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_documents|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|event|full';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '11',
    'children' => array(
      0 => 'c4m_location_map',
      1 => 'c4m_field_location_city_country',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-location field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_location|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_actions|node|event|full';
  $field_group->group_name = 'group_node_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
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
        'classes' => 'group-node-actions field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_node_actions|node|event|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organiser|node|event|full';
  $field_group->group_name = 'group_organiser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organiser',
    'weight' => '9',
    'children' => array(
      0 => 'c4m_facebook',
      1 => 'c4m_link',
      2 => 'c4m_organised_by',
      3 => 'c4m_twitter',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Organiser',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-organiser field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_organiser|node|event|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Do more through capacity4dev');
  t('Documents');
  t('Groups');
  t('Location');
  t('Metadata');
  t('Organiser');

  return $field_groups;
}
