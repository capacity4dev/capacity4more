<?php
/**
 * @file
 * c4m_content_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_event_field_group_info() {
  $export = array();

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
    'weight' => '9',
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
  $export['c4m_documents|node|event|form'] = $field_group;

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
    'weight' => '13',
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
  $export['c4m_metadata|node|event|form'] = $field_group;

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
    'weight' => '14',
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
  $export['c4m_og|node|event|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_language',
      2 => 'c4m_vocab_topic',
      3 => 'og_vocabulary',
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
  $export['group_details|node|event|full'] = $field_group;

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
    'weight' => '5',
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
        'classes' => 'group-node-documents field-group-fieldset',
      ),
    ),
  );
  $export['group_documents|node|event|full'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'c4m_location',
      1 => 'c4m_field_location_city_country',
      2 => 'c4m_content_event_link_to_gmap',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Location',
      'instance_settings' => array(
        'classes' => 'group-node-location field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_location|node|event|full'] = $field_group;

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
    'label' => 'Actions',
    'weight' => '8',
    'children' => array(
      0 => 'c4m_ds_content_actions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Actions',
      'instance_settings' => array(
        'classes' => 'group-node-actions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_node_actions|node|event|full'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'c4m_facebook',
      1 => 'c4m_link',
      2 => 'c4m_organised_by',
      3 => 'c4m_twitter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-node-organiser field-group-fieldset',
      ),
    ),
  );
  $export['group_organiser|node|event|full'] = $field_group;

  return $export;
}
