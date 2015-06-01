<?php
/**
 * @file
 * c4m_user.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_user_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|c4m_user_picture';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'c4m_user_picture';
  $ds_fieldsetting->settings = array(
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'linked_media_thumbnail',
    ),
  );
  $export['user|user|c4m_user_picture'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|c4m_user_teaser_list';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'c4m_user_teaser_list';
  $ds_fieldsetting->settings = array(
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'linked_media_thumbnail',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'linked_user_with_icon',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_user_country' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Based in',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_features_og_members_admin_actions' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'membership_level',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_features_og_members_since' => array(
      'weight' => '6',
      'label' => 'inline',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Member since',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_features_og_members_activity_summary' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_vocab_topic_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Expertise',
          'lb-el' => 'span',
          'fis' => TRUE,
          'fis-el' => 'span',
          'fis-cl' => 'expertises',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'expertise',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|c4m_user_teaser_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|c4m_user_teaser_list_global';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'c4m_user_teaser_list_global';
  $ds_fieldsetting->settings = array(
    'c4m_user_member_since' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Member since',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_user_activity_summary' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'linked_media_thumbnail',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'linked_user_with_icon',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_user_country' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Based in',
          'lb-el' => 'span',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_vocab_topic_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Expertise',
          'lb-el' => 'span',
          'fis' => TRUE,
          'fis-el' => 'span',
          'fis-cl' => 'expertises',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'expertise',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|c4m_user_teaser_list_global'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|c4m_user_teaser_table';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'c4m_user_teaser_table';
  $ds_fieldsetting->settings = array(
    'c4m_user_first_and_last_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'linked_user_with_icon',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_features_og_members_admin_actions' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_features_og_members_role' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_features_og_members_since' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'j F Y',
    ),
    'c4m_features_og_members_activity_posts' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_features_og_members_activity_comments' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['user|user|c4m_user_teaser_table'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|c4m_user_teaser_table_global';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'c4m_user_teaser_table_global';
  $ds_fieldsetting->settings = array(
    'c4m_user_member_since' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_activity_posts' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_activity_comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'linked_user_with_icon',
    ),
  );
  $export['user|user|c4m_user_teaser_table_global'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_user_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|c4m_user_picture';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'c4m_user_picture';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_user_picture',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'ds_content',
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
  $export['user|user|c4m_user_picture'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|c4m_user_teaser_list';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'c4m_user_teaser_list';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
      ),
      'right' => array(
        1 => 'c4m_user_first_and_last_name',
        2 => 'c4m_features_og_members_admin_actions',
        3 => 'c4m_organisation',
        4 => 'c4m_user_country',
        5 => 'c4m_features_og_members_since',
        6 => 'c4m_features_og_members_activity_summary',
        7 => 'c4m_vocab_topic_expertise',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_features_og_members_admin_actions' => 'right',
      'c4m_organisation' => 'right',
      'c4m_user_country' => 'right',
      'c4m_features_og_members_since' => 'right',
      'c4m_features_og_members_activity_summary' => 'right',
      'c4m_vocab_topic_expertise' => 'right',
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
  $export['user|user|c4m_user_teaser_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|c4m_user_teaser_list_global';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'c4m_user_teaser_list_global';
  $ds_layout->layout = 'c4m_ds_2col_icon_left';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
      ),
      'right' => array(
        1 => 'c4m_user_first_and_last_name',
        2 => 'c4m_organisation',
        3 => 'c4m_user_country',
        4 => 'c4m_user_member_since',
        5 => 'c4m_user_activity_summary',
        6 => 'c4m_vocab_topic_expertise',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_organisation' => 'right',
      'c4m_user_country' => 'right',
      'c4m_user_member_since' => 'right',
      'c4m_user_activity_summary' => 'right',
      'c4m_vocab_topic_expertise' => 'right',
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
  $export['user|user|c4m_user_teaser_list_global'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|c4m_user_teaser_table';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'c4m_user_teaser_table';
  $ds_layout->layout = 'c4m_ds_4col_table_vbo';
  $ds_layout->settings = array(
    'regions' => array(
      'first' => array(
        0 => 'c4m_user_first_and_last_name',
      ),
      'second' => array(
        1 => 'c4m_features_og_members_since',
        2 => 'c4m_features_og_members_role',
      ),
      'third' => array(
        3 => 'c4m_features_og_members_activity_posts',
        4 => 'c4m_features_og_members_activity_comments',
      ),
      'fourth' => array(
        5 => 'c4m_features_og_members_admin_actions',
      ),
    ),
    'fields' => array(
      'c4m_user_first_and_last_name' => 'first',
      'c4m_features_og_members_since' => 'second',
      'c4m_features_og_members_role' => 'second',
      'c4m_features_og_members_activity_posts' => 'third',
      'c4m_features_og_members_activity_comments' => 'third',
      'c4m_features_og_members_admin_actions' => 'fourth',
    ),
    'classes' => array(),
    'wrappers' => array(
      'first' => 'div',
      'second' => 'div',
      'third' => 'div',
      'fourth' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['user|user|c4m_user_teaser_table'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|c4m_user_teaser_table_global';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'c4m_user_teaser_table_global';
  $ds_layout->layout = 'c4m_ds_4col_table_vbo';
  $ds_layout->settings = array(
    'regions' => array(
      'first' => array(
        0 => 'c4m_user_first_and_last_name',
      ),
      'second' => array(
        1 => 'c4m_user_member_since',
      ),
      'third' => array(
        2 => 'c4m_user_activity_posts',
        3 => 'c4m_user_activity_comments',
      ),
    ),
    'fields' => array(
      'c4m_user_first_and_last_name' => 'first',
      'c4m_user_member_since' => 'second',
      'c4m_user_activity_posts' => 'third',
      'c4m_user_activity_comments' => 'third',
    ),
    'classes' => array(),
    'wrappers' => array(
      'first' => 'div',
      'second' => 'div',
      'third' => 'div',
      'fourth' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['user|user|c4m_user_teaser_table_global'] = $ds_layout;

  return $export;
}
