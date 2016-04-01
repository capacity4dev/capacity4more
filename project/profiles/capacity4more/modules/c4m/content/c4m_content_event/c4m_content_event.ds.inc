<?php
/**
 * @file
 * c4m_content_event.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_event_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_event|activity_stream';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_event';
  $ds_fieldsetting->view_mode = 'activity_stream';
  $ds_fieldsetting->settings = array(
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
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_event|activity_stream'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_event|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_day',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-name-post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'c4m_user_author_thumb_image',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-name-c4m-user-first-and-last-name',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_related_document' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Documents',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'field-label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-name-c4m-related-document',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['comment|comment_node_event|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|activity_global';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'activity_global';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'div',
        'class' => 'message-title',
        'ft' => array(),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '2',
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
  $export['node|event|activity_global'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|activity_group';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'activity_group';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_auto',
        'wrapper' => 'div',
        'class' => 'message-title',
        'ft' => array(),
      ),
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|activity_group'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|c4m_related';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'c4m_related';
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
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'og_group_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Group',
          'lb-el' => 'span',
          'prefix' => '<span class="group-ref">',
          'suffix' => '</span>',
        ),
      ),
    ),
  );
  $export['node|event|c4m_related'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'default',
    ),
    'c4m_field_location_city_country' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => '@name (@country)',
    ),
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_event_link_to_gmap' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_actions' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_datetime_end' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'From',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_document_agenda' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_document_presentation' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'facebook-page',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'event-website',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_location' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_related_document' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_twitter' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'twitter-page',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_geo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_vocab_language' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_vocab_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Topics',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'og_vocabulary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|event|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
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
    'c4m_field_og_group' => array(
      'weight' => '2',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Group',
          'lb-el' => 'span',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'group',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_field_location_city_country' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'in @city (@country)',
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
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_footer_stats' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_datetime_end' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'From',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_organised_by' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Organised by',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'organiser',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|event|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|upcoming_event';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'upcoming_event';
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
    'c4m_ds_content_type_icon' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'og_group_ref' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'group',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'prefix' => '<span class="group-ref">',
          'suffix' => '</span>',
        ),
      ),
    ),
  );
  $export['node|event|upcoming_event'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_event_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_event|activity_stream';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_event';
  $ds_layout->view_mode = 'activity_stream';
  $ds_layout->layout = 'ds_1col';
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
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_event|activity_stream'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_event|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
      ),
      'right' => array(
        1 => 'comment_body',
        2 => 'c4m_user_first_and_last_name',
        3 => 'post_date',
        4 => 'links',
        5 => 'c4m_related_document',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'comment_body' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'post_date' => 'right',
      'links' => 'right',
      'c4m_related_document' => 'right',
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
  );
  $export['comment|comment_node_event|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|activity_global';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'activity_global';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_body',
        2 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_ds_content_footer_stats' => 'ds_content',
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
  $export['node|event|activity_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|activity_group';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'activity_group';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'c4m_body',
        2 => 'c4m_ds_content_footer_stats',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'c4m_body' => 'ds_content',
      'c4m_ds_content_footer_stats' => 'ds_content',
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
  $export['node|event|activity_group'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|c4m_related';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'c4m_related';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_ds_content_type_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_datetime_end',
        3 => 'og_group_ref',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_icon' => 'left',
      'title' => 'right',
      'c4m_datetime_end' => 'right',
      'og_group_ref' => 'right',
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
  );
  $export['node|event|c4m_related'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'c4m_vocab_topic',
        1 => 'c4m_field_location_city_country',
        3 => 'c4m_location',
        6 => 'c4m_organised_by',
        7 => 'c4m_content_event_link_to_gmap',
        12 => 'group_organiser',
        13 => 'group_node_actions',
        14 => 'group_location',
        15 => 'group_details',
        16 => 'c4m_ds_content_actions',
        17 => 'c4m_link',
        18 => 'c4m_facebook',
        19 => 'c4m_twitter',
        20 => 'og_vocabulary',
        21 => 'c4m_vocab_language',
        24 => 'c4m_vocab_geo',
      ),
      'left' => array(
        2 => 'c4m_ds_content_type_icon',
        4 => 'title',
        5 => 'links',
        8 => 'c4m_datetime_end',
        9 => 'c4m_body',
        10 => 'group_documents',
        11 => 'comments',
        22 => 'c4m_document_agenda',
        23 => 'c4m_document_presentation',
        25 => 'c4m_related_document',
      ),
    ),
    'fields' => array(
      'c4m_vocab_topic' => 'right',
      'c4m_field_location_city_country' => 'right',
      'c4m_ds_content_type_icon' => 'left',
      'c4m_location' => 'right',
      'title' => 'left',
      'links' => 'left',
      'c4m_organised_by' => 'right',
      'c4m_content_event_link_to_gmap' => 'right',
      'c4m_datetime_end' => 'left',
      'c4m_body' => 'left',
      'group_documents' => 'left',
      'comments' => 'left',
      'group_organiser' => 'right',
      'group_node_actions' => 'right',
      'group_location' => 'right',
      'group_details' => 'right',
      'c4m_ds_content_actions' => 'right',
      'c4m_link' => 'right',
      'c4m_facebook' => 'right',
      'c4m_twitter' => 'right',
      'og_vocabulary' => 'right',
      'c4m_vocab_language' => 'right',
      'c4m_document_agenda' => 'left',
      'c4m_document_presentation' => 'left',
      'c4m_vocab_geo' => 'right',
      'c4m_related_document' => 'left',
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
  $export['node|event|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'c4m_ds_3_9_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_ds_content_type_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_field_og_group',
        3 => 'c4m_organised_by',
        4 => 'c4m_datetime_end',
        5 => 'c4m_field_location_city_country',
        6 => 'c4m_body',
        7 => 'c4m_ds_content_footer_stats',
        8 => 'flag_c4m_og_content_highlight',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_icon' => 'left',
      'title' => 'right',
      'c4m_field_og_group' => 'right',
      'c4m_organised_by' => 'right',
      'c4m_datetime_end' => 'right',
      'c4m_field_location_city_country' => 'right',
      'c4m_body' => 'right',
      'c4m_ds_content_footer_stats' => 'right',
      'flag_c4m_og_content_highlight' => 'right',
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
  );
  $export['node|event|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|upcoming_event';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'upcoming_event';
  $ds_layout->layout = 'c4m_ds_3_9_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_ds_content_type_icon',
      ),
      'right' => array(
        1 => 'title',
        2 => 'c4m_datetime_end',
        3 => 'og_group_ref',
      ),
    ),
    'fields' => array(
      'c4m_ds_content_type_icon' => 'left',
      'title' => 'right',
      'c4m_datetime_end' => 'right',
      'og_group_ref' => 'right',
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
  );
  $export['node|event|upcoming_event'] = $ds_layout;

  return $export;
}
