<?php
/**
 * @file
 * c4m_content_wiki_page.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_wiki_page_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|wiki_page|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'wiki_page';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '4',
      'label' => 'above',
      'format' => 'default',
    ),
    'book_navigation' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_wiki_page_navigation' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|wiki_page|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_wiki_page_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|wiki_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'wiki_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_4_8_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'group_pages',
        1 => 'c4m_content_wiki_page_navigation',
        3 => 'c4m_related_topic',
        4 => 'og_vocabulary',
        7 => 'c4m_vocab_date',
        9 => 'c4m_vocab_language',
        11 => 'c4m_vocab_geo',
        12 => 'group_details',
      ),
      'right' => array(
        2 => 'title',
        5 => 'c4m_body',
        6 => 'c4m_related_document',
        8 => 'book_navigation',
        10 => 'comments',
      ),
    ),
    'fields' => array(
      'group_pages' => 'left',
      'c4m_content_wiki_page_navigation' => 'left',
      'title' => 'right',
      'c4m_related_topic' => 'left',
      'og_vocabulary' => 'left',
      'c4m_body' => 'right',
      'c4m_related_document' => 'right',
      'c4m_vocab_date' => 'left',
      'book_navigation' => 'right',
      'c4m_vocab_language' => 'left',
      'comments' => 'right',
      'c4m_vocab_geo' => 'left',
      'group_details' => 'left',
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
  $export['node|wiki_page|full'] = $ds_layout;

  return $export;
}
