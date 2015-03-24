<?php
/**
 * @file
 * c4m_content_article.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'c4m_banner',
      ),
      'left' => array(
        1 => 'title',
        2 => 'c4m_ds_creation_date',
        3 => 'post_date',
        4 => 'links',
        5 => 'c4m_body',
        6 => 'comments',
        7 => 'c4m_media',
        8 => 'c4m_has_video',
        9 => 'c4m_intro_text',
      ),
      'right' => array(
        10 => 'c4m_related_topic',
        11 => 'c4m_vocab_geo',
      ),
    ),
    'fields' => array(
      'c4m_banner' => 'header',
      'title' => 'left',
      'c4m_ds_creation_date' => 'left',
      'post_date' => 'left',
      'links' => 'left',
      'c4m_body' => 'left',
      'comments' => 'left',
      'c4m_media' => 'left',
      'c4m_has_video' => 'left',
      'c4m_intro_text' => 'left',
      'c4m_related_topic' => 'right',
      'c4m_vocab_geo' => 'right',
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
  $export['node|article|full'] = $ds_layout;

  return $export;
}
