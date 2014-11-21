<?php
/**
 * @file
 * Views integration.
 */

/**
 * Implementation of hook_views_data()
 */
function c4m_views_views_data() {
  $data = array();

  $data['views']['c4m_views_node_add'] = array(
    'title' => t('Add new Node link'),
    'help' => t('Shows a link to a node creation form. The link will only be shown if the user has the permission to create new content of the given node type.'),
    'area' => array(
      'handler' => 'c4m_views_handler_area_node_add',
    ),
  );

  return $data;
}
