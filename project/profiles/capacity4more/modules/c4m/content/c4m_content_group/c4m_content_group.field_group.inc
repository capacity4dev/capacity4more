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
  $field_group->identifier = 'c4m_access_info|node|group|c4m_dashboard';
  $field_group->group_name = 'c4m_access_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'c4m_dashboard';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'c4m_extra_info',
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
  $field_groups['c4m_access_info|node|group|c4m_dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_extra_info|node|group|c4m_dashboard';
  $field_group->group_name = 'c4m_extra_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'c4m_dashboard';
  $field_group->parent_name = 'c4m_access_info';
  $field_group->data = array(
    'label' => '',
    'weight' => '37',
    'children' => array(
      0 => 'c4m_ds_group_access_info',
      1 => 'c4m_ds_group_administer_link',
    ),
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
  $field_groups['c4m_extra_info|node|group|c4m_dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|group|c4m_dashboard';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'c4m_dashboard';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More details',
    'weight' => '5',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_topic',
      2 => 'c4m_user_picture',
      3 => 'c4m_user_first_and_last_name',
      4 => 'c4m_ds_group_role_members_group',
      5 => 'c4m_content_group_statistics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'More details',
      'instance_settings' => array(
        'classes' => 'group-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_details|node|group|c4m_dashboard'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('More details');

  return $field_groups;
}
