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
      'label' => 'Your account',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-account-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
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
      2 => 'c4m_job_title',
      3 => 'c4m_last_name',
      4 => 'c4m_organisation',
      5 => 'c4m_organisation_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Your personal info',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-personal-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
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
      0 => 'c4m_body',
      1 => 'c4m_media',
      2 => 'group_your_expertise',
      3 => 'group_your_interests',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Your public profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-public-profile field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_public_profile|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_about|user|user|full';
  $field_group->group_name = 'group_user_about';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About',
    'weight' => '3',
    'children' => array(
      0 => 'c4m_body',
      1 => 'c4m_job_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'About',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-about',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_about|user|user|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contributions|user|user|full';
  $field_group->group_name = 'group_user_contributions';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notable Contributions',
    'weight' => '4',
    'children' => array(
      0 => 'c4m_ds_article_notable_contribution',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Notable Contributions',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-contributions',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_contributions|user|user|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_data|user|user|full';
  $field_group->group_name = 'group_user_data';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_user_meta';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'masquerade',
      1 => 'c4m_user_first_and_last_name',
      2 => 'c4m_user_country',
      3 => 'c4m_user_organisation_full',
      4 => 'c4m_user_contact_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-data field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_data|user|user|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_expertise|user|user|full';
  $field_group->group_name = 'group_user_expertise';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expertise',
    'weight' => '2',
    'children' => array(
      0 => 'c4m_vocab_topic_expertise',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Expertise',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-expertise',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_expertise|user|user|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_interests|user|user|full';
  $field_group->group_name = 'group_user_interests';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Professional Interests',
    'weight' => '1',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_topic',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Professional Interests',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-interests',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_interests|user|user|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_meta|user|user|full';
  $field_group->group_name = 'group_user_meta';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'c4m_user_picture',
      1 => 'group_user_data',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-user-meta clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_meta|user|user|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_your_expertise|user|user|form';
  $field_group->group_name = 'group_your_expertise';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_public_profile';
  $field_group->data = array(
    'label' => 'Your expertise',
    'weight' => '10',
    'children' => array(
      0 => 'c4m_vocab_topic_expertise',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your expertise',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_your_expertise|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_your_interests|user|user|form';
  $field_group->group_name = 'group_your_interests';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_public_profile';
  $field_group->data = array(
    'label' => 'Your interests',
    'weight' => '11',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_topic',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your interests',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_your_interests|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Expertise');
  t('Notable Contributions');
  t('Professional Interests');
  t('Your account');
  t('Your expertise');
  t('Your interests');
  t('Your personal info');
  t('Your public profile');

  return $field_groups;
}
