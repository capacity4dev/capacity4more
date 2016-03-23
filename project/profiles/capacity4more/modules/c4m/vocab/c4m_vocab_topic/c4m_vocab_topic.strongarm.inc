<?php
/**
 * @file
 * c4m_vocab_topic.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_vocab_topic_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_c4m_vocab_topic_pattern';
  $strongarm->value = 'topic/term/[term:name]';
  $export['pathauto_taxonomy_term_c4m_vocab_topic_pattern'] = $strongarm;

  return $export;
}
