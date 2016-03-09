<?php
/**
 * @file
 * c4m_content_inthe_picture.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_inthe_picture_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|inthe_picture|inthe_picture_block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'inthe_picture';
  $ds_layout->view_mode = 'inthe_picture_block';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_media',
        1 => 'c4m_body',
        2 => 'c4m_link',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|inthe_picture|inthe_picture_block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|inthe_picture|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'inthe_picture';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_heading',
        1 => 'c4m_media',
        2 => 'c4m_body',
        3 => 'c4m_link',
      ),
    ),
    'fields' => array(
      'c4m_heading' => 'ds_content',
      'c4m_media' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_link' => 'ds_content',
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
  $export['node|inthe_picture|teaser'] = $ds_layout;

  return $export;
}
