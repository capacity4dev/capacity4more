<?php
/**
 * @file
 * c4m_features_og_discussions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_features_og_discussions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_discussion_pattern';
  $strongarm->value = 'discussions/[node:title]';
  $export['pathauto_node_discussion_pattern'] = $strongarm;

  return $export;
}
