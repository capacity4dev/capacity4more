<?php
/**
 * @file
 * c4m_content_document.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_document_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_meta' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_document_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_body',
        1 => 'c4m_document',
        2 => 'comments',
      ),
      'right' => array(
        3 => 'c4m_ds_node_meta',
        4 => 'group_node_details',
        5 => 'c4m_vocab_document_type',
        6 => 'c4m_related_topic',
        7 => 'og_vocabulary',
        8 => 'c4m_vocab_date',
        9 => 'c4m_vocab_language',
        10 => 'c4m_vocab_geo',
      ),
    ),
    'fields' => array(
      'c4m_body' => 'left',
      'c4m_document' => 'left',
      'comments' => 'left',
      'c4m_ds_node_meta' => 'right',
      'group_node_details' => 'right',
      'c4m_vocab_document_type' => 'right',
      'c4m_related_topic' => 'right',
      'og_vocabulary' => 'right',
      'c4m_vocab_date' => 'right',
      'c4m_vocab_language' => 'right',
      'c4m_vocab_geo' => 'right',
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
  );
  $export['node|document|full'] = $ds_layout;

  return $export;
}
