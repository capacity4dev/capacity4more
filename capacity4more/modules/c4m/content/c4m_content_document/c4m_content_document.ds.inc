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
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'author_linked',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Document uploaded by',
          'lb-el' => 'span',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'ds_post_date_day',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'span',
        ),
      ),
    ),
    'c4m_ds_node_author_image' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'thumbnail',
    ),
  );
  $export['node|document|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_meta' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'minimal',
    ),
  );
  $export['node|document|teaser'] = $ds_fieldsetting;

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
        0 => 'links',
        1 => 'c4m_body',
        2 => 'c4m_document',
        3 => 'comments',
      ),
      'right' => array(
        4 => 'c4m_ds_node_author_image',
        5 => 'c4m_vocab_document_type',
        6 => 'c4m_related_topic',
        7 => 'author',
        8 => 'post_date',
        9 => 'og_vocabulary',
        10 => 'c4m_vocab_date',
        11 => 'group_node_details',
        12 => 'c4m_vocab_language',
        13 => 'c4m_vocab_geo',
      ),
    ),
    'fields' => array(
      'links' => 'left',
      'c4m_body' => 'left',
      'c4m_document' => 'left',
      'comments' => 'left',
      'c4m_ds_node_author_image' => 'right',
      'c4m_vocab_document_type' => 'right',
      'c4m_related_topic' => 'right',
      'author' => 'right',
      'post_date' => 'right',
      'og_vocabulary' => 'right',
      'c4m_vocab_date' => 'right',
      'group_node_details' => 'right',
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

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_ds_node_meta',
        2 => 'c4m_body',
        3 => 'links',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_ds_node_meta' => 'ds_content',
      'c4m_body' => 'ds_content',
      'links' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|document|teaser'] = $ds_layout;

  return $export;
}
