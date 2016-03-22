<?php
/**
 * @file
 * c4m_helper_date.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_helper_date_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_c4m_long_without_time';
  $strongarm->value = 'j F Y';
  $export['date_format_c4m_long_without_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_c4m_long_with_time';
  $strongarm->value = 'j F Y, G:i';
  $export['date_format_c4m_long_with_time'] = $strongarm;

  return $export;
}
