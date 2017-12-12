<?php

/**
 * @file
 * c4m_features_overview_groups.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_groups_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_groups';
  $context->description = 'Overview page of all Groups';
  $context->tag = 'cap4more - Groups';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_groups:page' => 'c4m_overview_groups:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f38a69c54df9a3d3692d47f18bb2c0af' => array(
          'module' => 'views',
          'delta' => 'f38a69c54df9a3d3692d47f18bb2c0af',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'c4m_search_filter-search_filter_groups_overview' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter_groups_overview',
          'region' => 'content_above',
          'weight' => '-9',
        ),
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'c4m_content_group-c4m_block_create_group' => array(
          'module' => 'c4m_content_group',
          'delta' => 'c4m_block_create_group',
          'region' => 'sidebar_first_top',
          'weight' => '-10',
        ),
        'views--exp-c4m_overview_groups-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_groups-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-yxOyG0dJbBLQDLZCpS9EuYjzha6J9TNN' => array(
          'module' => 'facetapi',
          'delta' => 'yxOyG0dJbBLQDLZCpS9EuYjzha6J9TNN',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Groups');
  t('cap4more - Groups');
  $export['c4m_overview_groups'] = $context;

  return $export;
}
