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
  $strongarm->name = 'field_bundle_settings_message__c4m_insert__node__discussion';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_message__c4m_insert__node__discussion'] = $strongarm;

  return $export;
}
