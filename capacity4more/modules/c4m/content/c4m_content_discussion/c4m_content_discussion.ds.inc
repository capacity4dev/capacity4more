<?php
/**
 * @file
 * c4m_content_discussion.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_discussion_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|discussion|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'discussion';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '4',
      'label' => 'above',
      'format' => 'default',
    ),
    'c4m_ds_node_meta' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'information_post',
    ),
    'c4m_related_topic' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|discussion|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|discussion|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'discussion';
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
  $export['node|discussion|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_discussion_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'c4m_ds_node_meta',
        5 => 'c4m_related_topic',
        6 => 'c4m_vocab_date',
        7 => 'c4m_vocab_language',
        8 => 'c4m_vocab_geo',
        9 => 'group_node_details',
      ),
      'left' => array(
        1 => 'links',
        2 => 'c4m_body',
        3 => 'c4m_related_document',
        4 => 'comments',
      ),
    ),
    'fields' => array(
      'c4m_ds_node_meta' => 'right',
      'links' => 'left',
      'c4m_body' => 'left',
      'c4m_related_document' => 'left',
      'comments' => 'left',
      'c4m_related_topic' => 'right',
      'c4m_vocab_date' => 'right',
      'c4m_vocab_language' => 'right',
      'c4m_vocab_geo' => 'right',
      'group_node_details' => 'right',
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
  $export['node|discussion|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|discussion|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'discussion';
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
  $export['node|discussion|teaser'] = $ds_layout;

  return $export;
}
