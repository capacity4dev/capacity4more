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
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '4',
      'label' => 'above',
      'format' => 'default',
    ),
    'c4m_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'facebook-page',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'event-website',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_related_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Topics',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_twitter' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'twitter-page',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
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
        0 => 'links',
        1 => 'c4m_datetime_end',
        2 => 'c4m_body',
        4 => 'group_documents',
        5 => 'comments',
        13 => 'c4m_document_agenda',
        14 => 'c4m_document_presentation',
        15 => 'c4m_related_document',
      ),
      'right' => array(
        3 => 'c4m_organised_by',
        6 => 'c4m_related_topic',
        7 => 'group_organiser',
        8 => 'og_vocabulary',
        9 => 'c4m_location',
        10 => 'c4m_vocab_language',
        11 => 'group_details',
        12 => 'c4m_vocab_geo',
        16 => 'c4m_link',
        17 => 'c4m_facebook',
        18 => 'c4m_twitter',
      ),
    ),
    'fields' => array(
      'links' => 'left',
      'c4m_datetime_end' => 'left',
      'c4m_body' => 'left',
      'c4m_organised_by' => 'right',
      'group_documents' => 'left',
      'comments' => 'left',
      'c4m_related_topic' => 'right',
      'group_organiser' => 'right',
      'og_vocabulary' => 'right',
      'c4m_location' => 'right',
      'c4m_vocab_language' => 'right',
      'group_details' => 'right',
      'c4m_vocab_geo' => 'right',
      'c4m_document_agenda' => 'left',
      'c4m_document_presentation' => 'left',
      'c4m_related_document' => 'left',
      'c4m_link' => 'right',
      'c4m_facebook' => 'right',
      'c4m_twitter' => 'right',
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
