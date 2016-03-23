<?php
/**
 * @file
 * c4m_features_og_overview_tasks.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_features_og_overview_tasks_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_tasklist_pattern';
  $strongarm->value = 'task-list/[node:title]';
  $export['pathauto_node_tasklist_pattern'] = $strongarm;

  return $export;
}
