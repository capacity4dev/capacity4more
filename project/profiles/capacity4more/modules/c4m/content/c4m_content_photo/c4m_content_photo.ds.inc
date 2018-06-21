<?php

/**
 * @file
 * c4m_content_photo.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_photo_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_photo|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_photo';
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
  $export['comment|comment_node_photo|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_photo|my_comments';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_photo';
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
  $export['comment|comment_node_photo|my_comments'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|activity_global';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
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
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
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
  );
  $export['node|photo|activity_global'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|activity_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'activity_group';
  $ds_fieldsetting->settings = array(
    'c4m_ds_content_footer_stats' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
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
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|photo|activity_group'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|block_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
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
    'c4m_ds_submitted_by_and_on' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'j F Y',
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|photo|block_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|photo|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
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
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_shared_to' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_photo_download' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_actions' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|photo|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|highlight_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
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
  $export['node|photo|highlight_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|pinned_content';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'pinned_content';
  $ds_fieldsetting->settings = array(
    'c4m_rendered_content' => array(
      'weight' => '5',
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
        'link' => 'purl_auto',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
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
    'c4m_ds_content_type_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|photo|pinned_content'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
    'c4m_ds_content_type_icon' => array(
      'weight' => '1',
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
      'format' => 'default',
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_promote' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|photo|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|photo|teaser_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'photo';
  $ds_fieldsetting->view_mode = 'teaser_group';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
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
    'c4m_ds_content_type_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_highlight' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_node_promote' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|photo|teaser_group'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_photo_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_photo|activity_global';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_photo';
  $ds_layout->view_mode = 'activity_global';
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
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['comment|comment_node_photo|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_photo|activity_group';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_photo';
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
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['comment|comment_node_photo|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_photo|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_photo';
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
  $export['comment|comment_node_photo|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_photo|my_comments';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_photo';
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
  $export['comment|comment_node_photo|my_comments'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|activity_global';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'activity_global';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'c4m_field_og_group',
      ),
      'footer' => array(
        1 => 'c4m_ds_content_footer_stats',
      ),
      'left' => array(
        2 => 'c4m_media',
      ),
      'right' => array(
        3 => 'c4m_body',
      ),
    ),
    'fields' => array(
      'c4m_field_og_group' => 'header',
      'c4m_ds_content_footer_stats' => 'footer',
      'c4m_media' => 'left',
      'c4m_body' => 'right',
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
  );
  $export['node|photo|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|activity_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'activity_group';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'footer' => array(
        1 => 'c4m_ds_content_footer_stats',
      ),
      'right' => array(
        2 => 'c4m_body',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'c4m_ds_content_footer_stats' => 'footer',
      'c4m_body' => 'right',
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
  );
  $export['node|photo|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|block_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'block_list';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_ds_node_highlight',
        3 => 'c4m_ds_submitted_by_and_on',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'title' => 'right',
      'c4m_ds_node_highlight' => 'right',
      'c4m_ds_submitted_by_and_on' => 'right',
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
  $export['node|photo|block_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'c4m_body',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'c4m_body' => 'right',
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
  );
  $export['node|photo|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_ds_content_type_label',
        4 => 'title',
        6 => 'c4m_ds_content_footer_stats',
        8 => 'node_gallery_navigation',
        9 => 'c4m_media',
        11 => 'c4m_body',
        12 => 'c4m_ds_photo_download',
      ),
      'right' => array(
        1 => 'c4m_ds_node_highlight',
        2 => 'c4m_ds_entity_type_label',
        3 => 'c4m_user_picture',
        5 => 'c4m_ds_content_actions',
        7 => 'c4m_user_first_and_last_name',
        10 => 'c4m_ds_update_date',
        13 => 'group_node_meta',
        14 => 'group_node_actions',
        15 => 'c4m_ds_content_shared_to',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_label' => 'left',
      'c4m_ds_node_highlight' => 'right',
      'c4m_ds_entity_type_label' => 'right',
      'c4m_user_picture' => 'right',
      'title' => 'left',
      'c4m_ds_content_actions' => 'right',
      'c4m_ds_content_footer_stats' => 'left',
      'c4m_user_first_and_last_name' => 'right',
      'node_gallery_navigation' => 'left',
      'c4m_media' => 'left',
      'c4m_ds_update_date' => 'right',
      'c4m_body' => 'left',
      'c4m_ds_photo_download' => 'left',
      'group_node_meta' => 'right',
      'group_node_actions' => 'right',
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
  $export['node|photo|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|highlight_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
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
  $export['node|photo|highlight_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|pinned_content';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
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
  $export['node|photo|pinned_content'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'c4m_ds_4_8_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'c4m_ds_content_type_icon',
        2 => 'c4m_user_first_and_last_name',
        3 => 'c4m_ds_type_insert_action',
        4 => 'c4m_ds_creation_date',
        5 => 'c4m_field_og_group',
      ),
      'left' => array(
        6 => 'c4m_media',
      ),
      'right' => array(
        7 => 'c4m_body',
        8 => 'c4m_ds_content_footer_stats',
        9 => 'c4m_ds_node_highlight',
        10 => 'c4m_ds_node_promote',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'c4m_ds_content_type_icon' => 'header',
      'c4m_user_first_and_last_name' => 'header',
      'c4m_ds_type_insert_action' => 'header',
      'c4m_ds_creation_date' => 'header',
      'c4m_field_og_group' => 'header',
      'c4m_media' => 'left',
      'c4m_body' => 'right',
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
  );
  $export['node|photo|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|photo|teaser_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'photo';
  $ds_layout->view_mode = 'teaser_group';
  $ds_layout->layout = 'c4m_ds_4_8_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'c4m_ds_content_type_icon',
        2 => 'c4m_user_first_and_last_name',
        3 => 'c4m_ds_type_insert_action',
        4 => 'c4m_ds_creation_date',
      ),
      'left' => array(
        5 => 'c4m_media',
      ),
      'right' => array(
        6 => 'c4m_body',
        7 => 'c4m_ds_content_footer_stats',
        8 => 'c4m_ds_node_highlight',
        9 => 'c4m_ds_node_promote',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'c4m_ds_content_type_icon' => 'header',
      'c4m_user_first_and_last_name' => 'header',
      'c4m_ds_type_insert_action' => 'header',
      'c4m_ds_creation_date' => 'header',
      'c4m_media' => 'left',
      'c4m_body' => 'right',
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
  );
  $export['node|photo|teaser_group'] = $ds_layout;

  return $export;
}
