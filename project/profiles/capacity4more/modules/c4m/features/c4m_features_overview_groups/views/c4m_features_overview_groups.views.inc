<?php
/**
 * @file
 * integration with the views module.
 */
/**
 * Implements hook_views_data().
 */
function c4m_features_overview_groups_views_data() {
  $data['node']['members_count'] = array(
    'title' => 'Group members count',
    'help' => 'Number of members in a group.',
    'field' => array(
      'handler' => 'c4m_overview_groups_handler_members_count',
    ),
  );
  return $data;
}
