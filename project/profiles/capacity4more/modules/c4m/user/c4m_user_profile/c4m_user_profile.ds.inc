<?php

/**
 * @file
 * c4m_user_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function c4m_user_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|full';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'c4m_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'c4m_user_author_thumb_image',
    ),
    'c4m_user_first_and_last_name' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'user_with_icon',
    ),
    'c4m_user_country' => array(
      'weight' => '5',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Based in',
        ),
      ),
    ),
    'c4m_user_organisation_full' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_user_contact_link' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_article_notable_contribution' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_user_my_groups' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_ds_user_my_projects' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'c4m_vocab_geo' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Regions',
        ),
      ),
    ),
    'c4m_vocab_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topics',
        ),
      ),
    ),
    'c4m_vocab_topic_expertise' => array(
      'formatter_settings' => array(
        'ft' => array(
          'lb' => 'Topics & subtopics',
        ),
      ),
    ),
  );
  $export['user|user|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function c4m_user_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|full';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'c4m_ds_8_4_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'c4m_user_picture',
        1 => 'group_user_meta',
        2 => 'group_user_interests',
        3 => 'group_user_expertise',
        4 => 'group_user_data',
        5 => 'c4m_vocab_topic',
        6 => 'c4m_user_first_and_last_name',
        7 => 'c4m_vocab_geo',
        8 => 'group_user_about',
        9 => 'c4m_user_organisation_full',
        10 => 'c4m_job_title',
        11 => 'c4m_vocab_topic_expertise',
        12 => 'c4m_ds_article_notable_contribution',
        13 => 'group_user_contributions',
        15 => 'c4m_user_country',
        16 => 'c4m_body',
        17 => 'c4m_user_contact_link',
        19 => 'masquerade',
      ),
      'right' => array(
        14 => 'c4m_ds_user_my_groups',
        18 => 'c4m_ds_user_my_projects',
      ),
    ),
    'fields' => array(
      'c4m_user_picture' => 'left',
      'group_user_meta' => 'left',
      'group_user_interests' => 'left',
      'group_user_expertise' => 'left',
      'group_user_data' => 'left',
      'c4m_vocab_topic' => 'left',
      'c4m_user_first_and_last_name' => 'left',
      'c4m_vocab_geo' => 'left',
      'group_user_about' => 'left',
      'c4m_user_organisation_full' => 'left',
      'c4m_job_title' => 'left',
      'c4m_vocab_topic_expertise' => 'left',
      'c4m_ds_article_notable_contribution' => 'left',
      'group_user_contributions' => 'left',
      'c4m_ds_user_my_groups' => 'right',
      'c4m_user_country' => 'left',
      'c4m_body' => 'left',
      'c4m_user_contact_link' => 'left',
      'c4m_ds_user_my_projects' => 'right',
      'masquerade' => 'left',
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
  $export['user|user|full'] = $ds_layout;

  return $export;
}
