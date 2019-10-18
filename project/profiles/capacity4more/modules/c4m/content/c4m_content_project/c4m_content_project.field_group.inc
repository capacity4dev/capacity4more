<?php

/**
 * @file
 * c4m_content_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_project_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_metadata|node|project|form';
  $field_group->group_name = 'c4m_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '12',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_topic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4m-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_metadata|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_project_cris|node|project|form';
  $field_group->group_name = 'c4m_project_cris';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'EC Info',
    'weight' => '11',
    'children' => array(
      0 => 'c4m_cris_contract_number',
      1 => 'c4m_cris_decision_number',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'EC Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4m-project-cris field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_project_cris|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_project_details|node|project|form';
  $field_group->group_name = 'c4m_project_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '10',
    'children' => array(
      0 => 'c4m_date_end',
      1 => 'c4m_money',
      2 => 'c4m_project_geodata',
      3 => 'c4m_project_stakeholders',
      4 => 'c4m_project_url',
      5 => 'c4m_source_of_funding',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4m-project-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_project_details|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_related_content|node|project|form';
  $field_group->group_name = 'c4m_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '13',
    'children' => array(
      0 => 'c4m_related_projects_unlimited',
      1 => 'c4m_related_group',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'c4d-related-content field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_related_content|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_iconbar_project_views|node|project|teaser';
  $field_group->group_name = 'group_iconbar_project_views';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
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
  $field_groups['group_iconbar_project_views|node|project|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_content|node|project|form';
  $field_group->group_name = 'group_page_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page content',
    'weight' => '14',
    'children' => array(
      0 => 'c4m_left_column',
      1 => 'c4m_right_column',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'label' => 'Page content',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-content field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_page_content|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser_author_information|node|project|teaser';
  $field_group->group_name = 'group_teaser_author_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author information',
    'weight' => '2',
    'children' => array(
      0 => 'c4m_user_first_and_last_name',
      1 => 'c4m_ds_creation_date',
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
  $field_groups['group_teaser_author_information|node|project|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser_header_inline|node|project|teaser';
  $field_group->group_name = 'group_teaser_header_inline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header inline',
    'weight' => '0',
    'children' => array(
      0 => 'c4m_project_stage',
      1 => 'title',
      2 => 'c4m_ds_project_type_icon',
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
  $field_groups['group_teaser_header_inline|node|project|teaser'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author information');
  t('Details');
  t('EC Info');
  t('Header inline');
  t('Icons');
  t('Metadata');
  t('Page content');
  t('Related content');

  return $field_groups;
}
