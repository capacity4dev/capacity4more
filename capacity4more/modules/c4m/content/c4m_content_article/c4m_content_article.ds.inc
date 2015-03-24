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
      'left' => array(
        0 => 'c4m_body',
        1 => 'c4m_media',
        2 => 'c4m_vocab_geo',
        3 => 'c4m_has_video',
        4 => 'c4m_related_topic',
        5 => 'c4m_intro_text',
        6 => 'c4m_banner',
        7 => 'comments',
      ),
    ),
    'fields' => array(
      'c4m_body' => 'left',
      'c4m_media' => 'left',
      'c4m_vocab_geo' => 'left',
      'c4m_has_video' => 'left',
      'c4m_related_topic' => 'left',
      'c4m_intro_text' => 'left',
      'c4m_banner' => 'left',
      'comments' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|article|full'] = $ds_layout;

  return $export;
}
