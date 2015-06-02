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
    'related_articles_by_topic' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'related_groups_by_topic' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'related_projects_by_topic' => array(
      'weight' => '0',
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
    'c4m_related_articles' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'panel-pane',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_related_group_unlimited' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'panel-pane',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_related_projects_unlimited' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'panel-pane',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
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

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_articles_by_topic';
  $ds_field->label = 'Related Articles by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_nodes-block_2',
    'block_render' => '2',
  );
  $export['related_articles_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_groups_by_topic';
  $ds_field->label = 'Related Groups by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_nodes-block',
    'block_render' => '2',
  );
  $export['related_groups_by_topic'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'related_projects_by_topic';
  $ds_field->label = 'Related Projects by Topic';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'topic|full';
  $ds_field->properties = array(
    'block' => 'views|c4m_related_nodes-block_1',
    'block_render' => '2',
  );
  $export['related_projects_by_topic'] = $ds_field;

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
        4 => 'c4m_header_meta',
        5 => 'title',
        7 => 'c4m_body',
      ),
      'right' => array(
        1 => 'related_articles_by_topic',
        2 => 'related_groups_by_topic',
        3 => 'related_projects_by_topic',
        8 => 'c4m_related_group_unlimited',
        9 => 'c4m_related_projects_unlimited',
        10 => 'c4m_related_articles',
      ),
      'left' => array(
        6 => 'activity_stream_by_topic',
      ),
    ),
    'fields' => array(
      'c4m_banner' => 'header',
      'related_articles_by_topic' => 'right',
      'related_groups_by_topic' => 'right',
      'related_projects_by_topic' => 'right',
      'c4m_header_meta' => 'header',
      'title' => 'header',
      'activity_stream_by_topic' => 'left',
      'c4m_body' => 'header',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|topic|full'] = $ds_layout;

  return $export;
}
