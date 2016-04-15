<?php
/**
 * @file
 * c4m_user_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_user_profile_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_info|user|user|form';
  $field_group->group_name = 'group_account_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your account',
    'weight' => '1',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_account_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_info|user|user|form';
  $field_group->group_name = 'group_personal_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your personal info',
    'weight' => '0',
    'children' => array(
      0 => 'c4m_country',
      1 => 'c4m_first_name',
      2 => 'c4m_last_name',
      3 => 'c4m_organisation',
      4 => 'c4m_organisation_type',
      5 => 'c4m_job_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personal-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_personal_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_public_profile|user|user|form';
  $field_group->group_name = 'group_public_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your public profile',
    'weight' => '2',
    'children' => array(
      0 => 'c4m_media',
      1 => 'c4m_vocab_geo',
      2 => 'c4m_about_you',
      3 => 'c4m_vocab_topic',
      4 => 'c4m_vocab_topic_expertise',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-public-profile field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_public_profile|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Your account');
  t('Your personal info');
  t('Your public profile');

  return $field_groups;
}
