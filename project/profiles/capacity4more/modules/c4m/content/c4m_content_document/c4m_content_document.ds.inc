<?php

/**
 * @file
 * c4m_content_document.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_document_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_document|activity_global';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_document';
  $ds_fieldsetting->view_mode = 'activity_global';
  $ds_fieldsetting->settings = array(
    'c4m_field_og_group' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_group_type' => 1,
        'ft' => array(),
      ),
    ),
  );
  $export['comment|comment_node_document|activity_global'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_document|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_document';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
  $export['comment|comment_node_document|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_document|my_comments';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_document';
  $ds_fieldsetting->view_mode = 'my_comments';
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
    'c4m_ds_comment_node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['comment|comment_node_document|my_comments'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|activity_global';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'activity_global';
  $ds_fieldsetting->settings = array(
    'c4m_field_og_group' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_group_type' => 1,
        'ft' => array(),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'downloads',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'pull-right',
          'fis-at' => '',
          'fis-def-at' => TRUE,
        ),
      ),
    ),
    'c4m_content_document_icon' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_body' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|document|activity_global'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|activity_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'activity_group';
  $ds_fieldsetting->settings = array(
    'c4m_ds_content_footer_stats' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'downloads',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'pull-right',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_content_document_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_body' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|document|activity_group'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|block_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'block_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'c4m_field_og_group' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_group_type' => 1,
        'ft' => array(),
      ),
    ),
    'c4m_ds_submitted_by_and_on' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'j F Y',
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_content_document_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|block_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'comments' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_picture' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'linked_thumbnail',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_update_date' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'last update',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'update-date-wrapper',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_content_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_entity_type_label' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'downloads',
    ),
    'c4m_ds_content_status' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'label label-default pull-right',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_promote' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_shared_to' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_document_icon' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_document_ds_field_pdf_preview' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_actions' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_vocab_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_document_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_geo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_language' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'h3',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'detail-element',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|document|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|highlight_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'highlight_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_submitted_by_and_on' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['node|document|highlight_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|pinned_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'pinned_content';
  $ds_fieldsetting->settings = array(
    'c4m_rendered_content' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:5:{s:9:"view_mode";s:14:"activity_group";s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:11:"entity_view";s:7:"subtype";s:4:"node";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_type_insert_action' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|document|pinned_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_field_og_group' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_group_type' => 1,
        'ft' => array(),
      ),
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_type_insert_action' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'downloads',
    ),
    'c4m_content_document_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|teaser_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'teaser_group';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_update_date' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => ' | ',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_ds_type_update_action' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'downloads',
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_promote' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_document_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|teaser_group'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_document_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_document|activity_global';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_document';
  $ds_layout->view_mode = 'activity_global';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_field_og_group',
        1 => 'comment_body',
      ),
    ),
    'fields' => array(
      'c4m_field_og_group' => 'ds_content',
      'comment_body' => 'ds_content',
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
  $export['comment|comment_node_document|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_document|activity_group';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_document';
  $ds_layout->view_mode = 'activity_group';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'comment_body',
      ),
    ),
    'fields' => array(
      'comment_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['comment|comment_node_document|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_document|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_document';
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
        4 => 'links',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'c4m_user_first_and_last_name' => 'right',
      'post_date' => 'right',
      'comment_body' => 'right',
      'links' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
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
  $export['comment|comment_node_document|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_document|my_comments';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_document';
  $ds_layout->view_mode = 'my_comments';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
      ),
      'right' => array(
        1 => 'c4m_ds_comment_node_link',
        2 => 'post_date',
        3 => 'comment_body',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'c4m_ds_comment_node_link' => 'right',
      'post_date' => 'right',
      'comment_body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
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
  $export['comment|comment_node_document|my_comments'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|activity_global';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'activity_global';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_field_og_group',
        1 => 'c4m_body',
        2 => 'c4m_content_document_icon',
        3 => 'c4m_document',
        4 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'c4m_field_og_group' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_content_document_icon' => 'ds_content',
      'c4m_document' => 'ds_content',
      'c4m_ds_content_footer_stats' => 'ds_content',
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
  );
  $export['node|document|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|activity_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'activity_group';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_body',
        1 => 'c4m_content_document_icon',
        2 => 'c4m_document',
        3 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'c4m_body' => 'ds_content',
      'c4m_content_document_icon' => 'ds_content',
      'c4m_document' => 'ds_content',
      'c4m_ds_content_footer_stats' => 'ds_content',
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
  );
  $export['node|document|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|block_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'block_list';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_content_document_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_ds_node_highlight',
        3 => 'c4m_ds_submitted_by_and_on',
        4 => 'c4m_field_og_group',
      ),
    ),
    'fields' => array(
      'c4m_content_document_icon' => 'left',
      'title' => 'right',
      'c4m_ds_node_highlight' => 'right',
      'c4m_ds_submitted_by_and_on' => 'right',
      'c4m_field_og_group' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
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
  $export['node|document|block_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_body',
        2 => 'c4m_document',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_document' => 'ds_content',
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
  );
  $export['node|document|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_ds_content_type_label',
        3 => 'c4m_ds_content_status',
        6 => 'title',
        10 => 'c4m_ds_content_footer_stats',
        13 => 'c4m_body',
        17 => 'c4m_content_document_ds_field_pdf_preview',
        19 => 'c4m_content_document_icon',
        20 => 'c4m_document',
        21 => 'comments',
      ),
      'right' => array(
        1 => 'c4m_ds_entity_type_label',
        2 => 'c4m_vocab_topic',
        4 => 'c4m_ds_node_highlight',
        5 => 'c4m_user_picture',
        7 => 'c4m_ds_node_promote',
        8 => 'c4m_user_first_and_last_name',
        9 => 'c4m_vocab_document_type',
        11 => 'c4m_vocab_geo',
        12 => 'c4m_ds_content_actions',
        14 => 'c4m_vocab_date',
        15 => 'c4m_ds_update_date',
        16 => 'c4m_vocab_language',
        18 => 'og_vocabulary',
        22 => 'group_node_meta',
        23 => 'group_node_actions',
        24 => 'group_node_details',
        25 => 'c4m_ds_content_shared_to',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_label' => 'left',
      'c4m_ds_entity_type_label' => 'right',
      'c4m_vocab_topic' => 'right',
      'c4m_ds_content_status' => 'left',
      'c4m_ds_node_highlight' => 'right',
      'c4m_user_picture' => 'right',
      'title' => 'left',
      'c4m_ds_node_promote' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_vocab_document_type' => 'right',
      'c4m_ds_content_footer_stats' => 'left',
      'c4m_vocab_geo' => 'right',
      'c4m_ds_content_actions' => 'right',
      'c4m_body' => 'left',
      'c4m_vocab_date' => 'right',
      'c4m_ds_update_date' => 'right',
      'c4m_vocab_language' => 'right',
      'c4m_content_document_ds_field_pdf_preview' => 'left',
      'og_vocabulary' => 'right',
      'c4m_content_document_icon' => 'left',
      'c4m_document' => 'left',
      'comments' => 'left',
      'group_node_meta' => 'right',
      'group_node_actions' => 'right',
      'group_node_details' => 'right',
      'c4m_ds_content_shared_to' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|document|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|highlight_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'highlight_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_ds_content_type_icon',
        1 => 'title',
        2 => 'c4m_ds_node_highlight',
        3 => 'c4m_ds_submitted_by_and_on',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_icon' => 'ds_content',
      'title' => 'ds_content',
      'c4m_ds_node_highlight' => 'ds_content',
      'c4m_ds_submitted_by_and_on' => 'ds_content',
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
  );
  $export['node|document|highlight_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|pinned_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'pinned_content';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_ds_content_type_icon',
        2 => 'c4m_user_first_and_last_name',
        3 => 'c4m_ds_type_insert_action',
        4 => 'c4m_ds_creation_date',
        5 => 'c4m_rendered_content',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_ds_content_type_icon' => 'ds_content',
      'c4m_user_first_and_last_name' => 'ds_content',
      'c4m_ds_type_insert_action' => 'ds_content',
      'c4m_ds_creation_date' => 'ds_content',
      'c4m_rendered_content' => 'ds_content',
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
  );
  $export['node|document|pinned_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_content_document_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_user_first_and_last_name',
        3 => 'c4m_ds_type_insert_action',
        4 => 'c4m_ds_creation_date',
        5 => 'c4m_field_og_group',
        6 => 'c4m_body',
        7 => 'c4m_document',
        8 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'c4m_content_document_icon' => 'left',
      'title' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_ds_type_insert_action' => 'right',
      'c4m_ds_creation_date' => 'right',
      'c4m_field_og_group' => 'right',
      'c4m_body' => 'right',
      'c4m_document' => 'right',
      'c4m_ds_content_footer_stats' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
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
  $export['node|document|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|teaser_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'teaser_group';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_content_document_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_user_first_and_last_name',
        3 => 'c4m_ds_type_update_action',
        4 => 'c4m_ds_update_date',
        5 => 'c4m_body',
        6 => 'c4m_document',
        7 => 'c4m_ds_content_footer_stats',
        8 => 'c4m_ds_node_highlight',
        9 => 'c4m_ds_node_promote',
      ),
    ),
    'fields' => array(
      'c4m_content_document_icon' => 'left',
      'title' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_ds_type_update_action' => 'right',
      'c4m_ds_update_date' => 'right',
      'c4m_body' => 'right',
      'c4m_document' => 'right',
      'c4m_ds_content_footer_stats' => 'right',
      'c4m_ds_node_highlight' => 'right',
      'c4m_ds_node_promote' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
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
  $export['node|document|teaser_group'] = $ds_layout;

  return $export;
}
