<?php
/**
 * @file
 * c4m_field_media.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_field_media_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|document|c4m_preview';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'c4m_preview';
  $ds_fieldsetting->settings = array(
    'c4m_ds_download_link' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'c4m_ds_formatter_link_and_size',
    ),
  );
  $export['file|document|c4m_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|document|teaser';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'c4m_ds_download_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'c4m_ds_formatter_link_and_size',
    ),
  );
  $export['file|document|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|image|c4m_preview';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'c4m_preview';
  $ds_fieldsetting->settings = array(
    'c4m_ds_download_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'c4m_ds_formatter_link_and_size',
    ),
  );
  $export['file|image|c4m_preview'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|image|teaser';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'c4m_ds_download_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'c4m_ds_formatter_link_and_size',
    ),
  );
  $export['file|image|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_field_media_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|document|c4m_preview';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'c4m_preview';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
    ),
    'fields' => array(
      'file' => 'left',
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
  $export['file|document|c4m_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|document|teaser';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_ds_download_link',
      ),
    ),
    'fields' => array(
      'c4m_ds_download_link' => 'ds_content',
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
  $export['file|document|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|c4m_preview';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'c4m_preview';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
    ),
    'fields' => array(
      'file' => 'left',
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
  $export['file|image|c4m_preview'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|teaser';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_ds_download_link',
      ),
    ),
    'fields' => array(
      'c4m_ds_download_link' => 'ds_content',
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
  $export['file|image|teaser'] = $ds_layout;

  return $export;
}
