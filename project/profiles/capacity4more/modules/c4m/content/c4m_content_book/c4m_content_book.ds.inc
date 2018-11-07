<?php

/**
 * @file
 * c4m_content_book.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_book_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_book|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_book';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_c4m_long_without_time',
    ),
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'linked_c4m_user_author_thumb_image',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'linked_user',
    ),
  );
  $export['comment|comment_node_book|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|book|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'book';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|book|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|book|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'book';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'book_navigation' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_dsfield_print_page_button' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'col-md-2 col-md-push-10',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|book|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_book_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_book|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_book';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
      ),
      'right' => array(
        1 => 'c4m_user_first_and_last_name',
        2 => 'post_date',
        3 => 'comment_body',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'c4m_user_first_and_last_name' => 'right',
      'post_date' => 'right',
      'comment_body' => 'right',
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
    'layout_disable_css' => FALSE,
  );
  $export['comment|comment_node_book|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|book|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'book';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_body',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'c4m_body' => 'ds_content',
      'title' => 'ds_content',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|book|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|book|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'book';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_dsfield_print_page_button',
        1 => 'c4m_body',
        2 => 'book_navigation',
        3 => 'comments',
      ),
    ),
    'fields' => array(
      'c4m_dsfield_print_page_button' => 'ds_content',
      'c4m_body' => 'ds_content',
      'book_navigation' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|book|full'] = $ds_layout;

  return $export;
}
