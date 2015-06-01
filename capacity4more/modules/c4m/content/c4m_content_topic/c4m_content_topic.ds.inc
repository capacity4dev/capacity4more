<?php
/**
 * @file
 * c4m_content_topic.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_topic_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|topic|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'topic';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'activity_stream' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'activity_stream_by_topic' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|topic|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function c4m_content_topic_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'activity_stream_by_topic';
  $ds_field->label = 'Activity Stream by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_content-block',
    'block_render' => '2',
  );
  $export['activity_stream_by_topic'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_topic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|topic|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'topic';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'c4m_banner',
        1 => 'c4m_header_meta',
        3 => 'title',
        4 => 'c4m_body',
      ),
      'left' => array(
        2 => 'activity_stream_by_topic',
      ),
      'right' => array(
        5 => 'activity_stream',
        6 => 'c4m_related_group_unlimited',
        7 => 'c4m_related_projects_unlimited',
        8 => 'c4m_related_articles',
      ),
    ),
    'fields' => array(
      'c4m_banner' => 'header',
      'c4m_header_meta' => 'header',
      'activity_stream_by_topic' => 'left',
      'title' => 'header',
      'c4m_body' => 'header',
      'activity_stream' => 'right',
      'c4m_related_group_unlimited' => 'right',
      'c4m_related_projects_unlimited' => 'right',
      'c4m_related_articles' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
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
  $export['node|topic|full'] = $ds_layout;

  return $export;
}
