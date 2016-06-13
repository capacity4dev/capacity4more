<?php
/**
 * @file
 * c4m_content_group.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_content_group_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|group|block_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'group';
  $ds_fieldsetting->view_mode = 'block_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_og_dashboard',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Owned by',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'text-muted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_group_members_count' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="group-members-count">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'c4m_ds_group_membership_type' => array(
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
  $export['node|group|block_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|group|group_dashboard';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'group';
  $ds_fieldsetting->view_mode = 'group_dashboard';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '5',
      'label' => 'above',
      'format' => 'author',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Group Owner',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Group created on',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'c4m-created-on-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'c4m_ds_group_administer_link' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_content_group_statistics' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_content_actions' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_vocab_geo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Reigens',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'c4m_vocab_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|group|group_dashboard'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|group|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'group';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => 'purl_og_dashboard',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'linked_user',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
          'lb' => 'Owned by',
          'lb-col' => TRUE,
          'prefix' => '<span class="owner">',
          'suffix' => '</span>',
        ),
      ),
    ),
    'c4m_ds_creation_date' => array(
      'weight' => '5',
      'label' => 'inline',
      'format' => 'j F Y',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
          'lb' => 'Created',
        ),
      ),
    ),
    'c4m_ds_group_access_info' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
          'prefix' => '<span class="group-access">',
          'suffix' => '</span>',
        ),
      ),
    ),
    'c4m_ds_group_members_count' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
          'prefix' => '<span class="group-members-count">',
          'suffix' => '</span>',
        ),
      ),
    ),
    'c4m_ds_group_posts_count' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_group_type_icon' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_ds_group_membership_type' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'c4m_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'c4m_media' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['node|group|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_content_group_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|group|block_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'group';
  $ds_layout->view_mode = 'block_list';
  $ds_layout->layout = 'c4m_ds_3_9_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_media',
      ),
      'right' => array(
        1 => 'c4m_ds_group_membership_type',
        2 => 'title',
        3 => 'c4m_user_first_and_last_name',
        4 => 'c4m_ds_group_members_count',
      ),
    ),
    'fields' => array(
      'c4m_media' => 'left',
      'c4m_ds_group_membership_type' => 'right',
      'title' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_ds_group_members_count' => 'right',
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
  $export['node|group|block_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|group|group_dashboard';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'group';
  $ds_layout->view_mode = 'group_dashboard';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'c4m_body',
        1 => 'c4m_ds_creation_date',
        2 => 'group_access_info',
        3 => 'c4m_content_group_statistics',
        4 => 'group_admins',
        5 => 'author',
        6 => 'c4m_vocab_topic',
        7 => 'c4m_vocab_geo',
        8 => 'c4m_ds_content_actions',
        9 => 'c4m_ds_group_administer_link',
        10 => 'group_extra_info',
      ),
    ),
    'fields' => array(
      'c4m_body' => 'ds_content',
      'c4m_ds_creation_date' => 'ds_content',
      'group_access_info' => 'ds_content',
      'c4m_content_group_statistics' => 'ds_content',
      'group_admins' => 'ds_content',
      'author' => 'ds_content',
      'c4m_vocab_topic' => 'ds_content',
      'c4m_vocab_geo' => 'ds_content',
      'c4m_ds_content_actions' => 'ds_content',
      'c4m_ds_group_administer_link' => 'ds_content',
      'group_extra_info' => 'ds_content',
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
  $export['node|group|group_dashboard'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|group|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'group';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'c4m_ds_3_9_fluid_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'group_teaser_header_inline',
        2 => 'c4m_ds_group_type_icon',
        4 => 'title',
        7 => 'c4m_ds_group_membership_type',
      ),
      'left' => array(
        1 => 'c4m_media',
      ),
      'right' => array(
        3 => 'group_teaser_author_information',
        5 => 'c4m_body',
        6 => 'c4m_ds_group_access_info',
        8 => 'group_iconbar_comments_views',
        9 => 'c4m_user_first_and_last_name',
        10 => 'c4m_ds_creation_date',
        11 => 'c4m_ds_group_members_count',
        12 => 'c4m_ds_group_posts_count',
      ),
    ),
    'fields' => array(
      'group_teaser_header_inline' => 'header',
      'c4m_media' => 'left',
      'c4m_ds_group_type_icon' => 'header',
      'group_teaser_author_information' => 'right',
      'title' => 'header',
      'c4m_body' => 'right',
      'c4m_ds_group_access_info' => 'right',
      'c4m_ds_group_membership_type' => 'header',
      'group_iconbar_comments_views' => 'right',
      'c4m_user_first_and_last_name' => 'right',
      'c4m_ds_creation_date' => 'right',
      'c4m_ds_group_members_count' => 'right',
      'c4m_ds_group_posts_count' => 'right',
    ),
    'classes' => array(),
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
  $export['node|group|teaser'] = $ds_layout;

  return $export;
}
