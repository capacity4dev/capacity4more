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
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '5',
      'label' => 'above',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'ds_post_date_day',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_node_author_image' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'thumbnail',
    ),
    'c4m_ds_author_first_and_last_name' => array(
      'weight' => '7',
      'label' => 'inline',
      'format' => 'author_link',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'information posted by',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'user-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
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
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_day',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_author_first_and_last_name' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'author_link',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lbw-el' => 'span',
          'lbw-cl' => 'user-name',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'user-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
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
      'left' => array(
        0 => 'c4m_ds_content_type_icon',
        1 => 'title',
        2 => 'c4m_ds_content_footer_stats',
        3 => 'c4m_body',
        4 => 'c4m_related_document',
        5 => 'comments',
      ),
      'right' => array(
        6 => 'c4m_ds_node_author_image',
        7 => 'c4m_ds_author_first_and_last_name',
        8 => 'post_date',
        9 => 'c4m_related_topic',
        10 => 'group_node_details',
        11 => 'og_vocabulary',
        12 => 'c4m_vocab_date',
        13 => 'c4m_vocab_language',
        14 => 'c4m_vocab_geo',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_icon' => 'left',
      'title' => 'left',
      'c4m_ds_content_footer_stats' => 'left',
      'c4m_body' => 'left',
      'c4m_related_document' => 'left',
      'comments' => 'left',
      'c4m_ds_node_author_image' => 'right',
      'c4m_ds_author_first_and_last_name' => 'right',
      'post_date' => 'right',
      'c4m_related_topic' => 'right',
      'group_node_details' => 'right',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
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
        1 => 'c4m_ds_author_first_and_last_name',
        2 => 'post_date',
        3 => 'c4m_body',
        4 => 'links',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_ds_author_first_and_last_name' => 'ds_content',
      'post_date' => 'ds_content',
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
