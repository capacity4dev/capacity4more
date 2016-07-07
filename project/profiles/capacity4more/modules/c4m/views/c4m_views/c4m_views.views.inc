<?php

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_data().
 */
function c4m_views_views_data() {
  $data = array();

  $data['views']['c4m_views_custom_link'] = array(
    'title' => t('Add a custom link'),
    'help' => t('Show a custom link.'),
    'area' => array(
      'handler' => 'c4m_views_handler_area_custom_link',
    ),
  );

  $data['views']['c4m_views_node_add'] = array(
    'title' => t('Add new Node link'),
    'help' => t('Shows a link to a node creation form. The link will only be shown if the user has the permission to create new content of the given node type.'),
    'area' => array(
      'handler' => 'c4m_views_handler_area_node_add',
    ),
  );

  $data['views']['c4m_views_result'] = array(
    'title' => t('Result summary (with optional classes)'),
    'help' => t('Custom configurable result summary.'),
    'area' => array(
      'handler' => 'c4m_views_handler_area_result',
    ),
  );

  $data['views']['c4m_views_search_api_sorts'] = array(
    'title' => t('Add Search API Sorts'),
    'help' => t('Add the sorts for the view using the block provided by the Search API Sort module.'),
    'area' => array(
      'handler' => 'c4m_views_handler_area_search_api_sorts',
    ),
  );

  $data['views']['c4m_views_switch_page'] = array(
    'title' => t('Add view pages links'),
    'help' => t('Add a link to switch between view pages (showing content in a different layout).'),
    'area' => array(
      'handler' => 'c4m_views_handler_area_switch_page',
    ),
  );

  return $data;
}
