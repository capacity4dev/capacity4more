<?php

/**
 * @file
 * c4m_content_group.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_group_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_info|node|group|group_dashboard';
  $field_group->group_name = 'group_access_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'group_dashboard';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'group_extra_info',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'c4m-access-info',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_access_info|node|group|group_dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|group|group_dashboard';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'group_dashboard';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More details',
    'weight' => '35',
    'children' => array(
      0 => 'c4m_user_picture',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_details|node|group|group_dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extra_info|node|group|group_dashboard';
  $field_group->group_name = 'group_extra_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'group_dashboard';
  $field_group->parent_name = 'group_access_info';
  $field_group->data = array(
    'label' => '',
    'weight' => '20',
    'children' => array(),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'row',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_extra_info|node|group|group_dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_iconbar_comments_views|node|group|teaser';
  $field_group->group_name = 'group_iconbar_comments_views';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Icons',
    'weight' => '4',
    'children' => array(
      0 => 'c4m_ds_group_members_count',
      1 => 'c4m_ds_group_posts_count',
      2 => 'c4m_ds_group_recommendation_count',
      3 => 'c4m_ds_node_highlight',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Icons',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-iconbar-comments-views field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_iconbar_comments_views|node|group|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser_author_information|node|group|teaser';
  $field_group->group_name = 'group_teaser_author_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author information',
    'weight' => '2',
    'children' => array(
      0 => 'c4m_user_first_and_last_name',
      1 => 'c4m_ds_creation_date',
      2 => 'c4m_ds_group_access_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Author information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-teaser-author-information field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_teaser_author_information|node|group|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser_header_inline|node|group|teaser';
  $field_group->group_name = 'group_teaser_header_inline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header inline',
    'weight' => '0',
    'children' => array(
      0 => 'c4m_og_status',
      1 => 'title',
      2 => 'c4m_ds_group_type_icon',
      3 => 'c4m_ds_group_membership_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Header inline',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-teaser-header-inline field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_teaser_header_inline|node|group|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author information');
  t('Header inline');
  t('Icons');
  t('More details');

  return $field_groups;
}
