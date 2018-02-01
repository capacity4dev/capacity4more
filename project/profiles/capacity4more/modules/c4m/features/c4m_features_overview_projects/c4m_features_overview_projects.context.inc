<?php

/**
 * @file
 * c4m_features_overview_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_projects';
  $context->description = 'Overview page of all Projects';
  $context->tag = 'cap4more - Projects';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_projects:page' => 'c4m_overview_projects:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-0832eb7e6f1d35503c5b3a8f77094884' => array(
          'module' => 'views',
          'delta' => '0832eb7e6f1d35503c5b3a8f77094884',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'c4m_search_filter-search_filter_projects_overview' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter_projects_overview',
          'region' => 'content_above',
          'weight' => '-8',
        ),
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'c4m_content_project-c4m_block_create_project' => array(
          'module' => 'c4m_content_project',
          'delta' => 'c4m_block_create_project',
          'region' => 'sidebar_first_top',
          'weight' => '-10',
        ),
        'views--exp-c4m_overview_projects-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_projects-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-S9qne31IKDd1jhPm8FHFcpVq9mtX65DM' => array(
          'module' => 'facetapi',
          'delta' => 'S9qne31IKDd1jhPm8FHFcpVq9mtX65DM',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-OK4Vyc0ny8QpANDSYVhonW7ExFGaGeb5' => array(
          'module' => 'facetapi',
          'delta' => 'OK4Vyc0ny8QpANDSYVhonW7ExFGaGeb5',
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
        'facetapi-OK4Vyc0ny8QpANDSYVhonW7ExFGaGeb5' => array(
          'module' => 'facetapi',
          'delta' => 'OK4Vyc0ny8QpANDSYVhonW7ExFGaGeb5',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Projects');
  t('cap4more - Projects');
  $export['c4m_overview_projects'] = $context;

  return $export;
}
