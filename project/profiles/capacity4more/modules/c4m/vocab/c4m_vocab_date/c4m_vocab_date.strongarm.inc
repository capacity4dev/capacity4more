<?php
/**
 * @file
 * c4m_vocab_date.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_vocab_date_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_c4m_vocab_date_pattern';
  $strongarm->value = 'content-date/[term:name]';
  $export['pathauto_taxonomy_term_c4m_vocab_date_pattern'] = $strongarm;

  return $export;
}
