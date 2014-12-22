<?php
/**
 * @file
 * c4m_content_event.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_event_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_event_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_ds_content_type_icon',
        1 => 'title',
        2 => 'links',
        3 => 'c4m_datetime_end',
        4 => 'c4m_body',
        5 => 'comments',
        6 => 'c4m_vocab_language',
        9 => 'c4m_vocab_geo',
        10 => 'group_documents',
        12 => 'c4m_document_agenda',
        15 => 'c4m_document_presentation',
        18 => 'c4m_related_document',
      ),
      'right' => array(
        7 => 'c4m_related_topic',
        8 => 'og_vocabulary',
        11 => 'group_organiser',
        13 => 'c4m_location',
        14 => 'c4m_organised_by',
        16 => 'c4m_link',
        17 => 'c4m_facebook',
        19 => 'c4m_twitter',
        20 => 'group_details',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_icon' => 'left',
      'title' => 'left',
      'links' => 'left',
      'c4m_datetime_end' => 'left',
      'c4m_body' => 'left',
      'comments' => 'left',
      'c4m_vocab_language' => 'left',
      'c4m_related_topic' => 'right',
      'og_vocabulary' => 'right',
      'c4m_vocab_geo' => 'left',
      'group_documents' => 'left',
      'group_organiser' => 'right',
      'c4m_document_agenda' => 'left',
      'c4m_location' => 'right',
      'c4m_organised_by' => 'right',
      'c4m_document_presentation' => 'left',
      'c4m_link' => 'right',
      'c4m_facebook' => 'right',
      'c4m_related_document' => 'left',
      'c4m_twitter' => 'right',
      'group_details' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|event|full'] = $ds_layout;

  return $export;
}
