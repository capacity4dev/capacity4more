<?php

/**
 * @file
 * c4m_message.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_message_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_access_change';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_access_change'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_admin_demoted';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_admin_demoted'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_archived';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_archived'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_content_updated';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_content_updated'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_published';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_published'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_republished';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_republished'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_requested';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_requested'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_request_approved';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_request_approved'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_request_submitted';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_request_submitted'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_soft_deleted';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_soft_deleted'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_group_unpublished';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_group_unpublished'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__comment';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__discussion';
  $strongarm->value = array(
    'view_modes' => array(
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__discussion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__document';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__event';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__news';
  $strongarm->value = array(
    'view_modes' => array(
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__photo';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__photo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__photoalbum';
  $strongarm->value = array(
    'view_modes' => array(
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__share';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__share'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__wiki_page';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__wiki_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_log_group_state_change';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_log_group_state_change'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_membership_request_rejected';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_membership_request_rejected'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_member_welcome_mesage';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_member_welcome_mesage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_new_content_published';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_new_content_published'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_new_content_share_published';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_new_content_share_published'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_new_membership_request';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_new_membership_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_new_member_joined';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_new_member_joined'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_admins_membership_approved';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_admins_membership_approved'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_content_followers_new_comment';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_content_followers_new_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_content_recommendation';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_content_recommendation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_editors_group_content_updated';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_editors_group_content_updated'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_promoted_member';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_promoted_member'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_subscribers_new_comment';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_subscribers_new_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_subscribe_content_of_interest';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_monthly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__2' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_header__0' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_footer__0' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'message_notify_monthly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_subscribe_content_of_interest'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_notify_user_membership_pending';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_notify_user_membership_pending'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__c4m_welcome_to_group';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_monthly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_daily_digest' => array(
        'custom_settings' => FALSE,
      ),
      'message_notify_weekly_digest' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__c4m_welcome_to_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_delete_on_entity_delete';
  $strongarm->value = array(
    'comment' => 'comment',
    'flagging' => 'flagging',
    'message_type' => 'message_type',
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'taxonomy_vocabulary' => 'taxonomy_vocabulary',
    'user' => 'user',
  );
  $export['message_delete_on_entity_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_flag_prefix';
  $strongarm->value = 'subscribe';
  $export['message_subscribe_flag_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'message_subscribe_use_queue';
  $strongarm->value = 1;
  $export['message_subscribe_use_queue'] = $strongarm;

  return $export;
}
