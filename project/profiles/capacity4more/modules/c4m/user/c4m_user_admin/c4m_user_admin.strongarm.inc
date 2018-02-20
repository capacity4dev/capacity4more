<?php

/**
 * @file
 * c4m_user_admin.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_user_admin_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_notify';
  $strongarm->value = 0;
  $export['user_mail_status_blocked_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_notify';
  $strongarm->value = 1;
  $export['user_mail_status_canceled_notify'] = $strongarm;

  return $export;
}
