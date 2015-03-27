<?php
/**
 * @file
 * c4m_content_article.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_article_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|c4m_teaser_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'c4m_teaser_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|c4m_teaser_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_article_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|c4m_teaser_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'c4m_teaser_list';
  $ds_layout->layout = 'c4m_ds_3_9_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        1 => 'c4m_media',
      ),
      'right' => array(
        2 => 'c4m_ds_creation_date',
        3 => 'c4m_intro_text',
        4 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'c4m_media' => 'left',
      'c4m_ds_creation_date' => 'right',
      'c4m_intro_text' => 'right',
      'c4m_ds_content_footer_stats' => 'right',
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
  );
  $export['node|article|c4m_teaser_list'] = $ds_layout;

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
        3 => 'c4m_ds_content_footer_stats',
        4 => 'c4m_intro_text',
        5 => 'c4m_body',
        6 => 'comments',
      ),
      'right' => array(
        7 => 'c4m_related_topic',
        8 => 'c4m_vocab_geo',
      ),
    ),
    'fields' => array(
      'c4m_banner' => 'header',
      'title' => 'left',
      'c4m_ds_creation_date' => 'left',
      'c4m_ds_content_footer_stats' => 'left',
      'c4m_intro_text' => 'left',
      'c4m_body' => 'left',
      'comments' => 'left',
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
