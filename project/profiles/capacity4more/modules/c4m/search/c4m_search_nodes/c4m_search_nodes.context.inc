<?php

/**
 * @file
 * c4m_search_nodes.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_search_nodes_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_group_draft_content';
  $context->description = 'Group search page to search trough all group draft content (nodes).';
  $context->tag = 'cap4more - Group Content';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_group_draft_content:page' => 'c4m_group_draft_content:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-37b80e5eac1003e66f4c562a2ac9b400' => array(
          'module' => 'views',
          'delta' => '37b80e5eac1003e66f4c562a2ac9b400',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS' => array(
          'module' => 'facetapi',
          'delta' => 'QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Group search page to search trough all group draft content (nodes).');
  t('cap4more - Group Content');
  $export['c4m_group_draft_content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_search_nodes';
  $context->description = 'Global search page to search trough all content (nodes).';
  $context->tag = 'cap4more - Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_search_nodes' => 'c4m_search_nodes',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'c4m_search_filter-search_filter' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter',
          'region' => 'content_above',
          'weight' => '-9',
        ),
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-c4m_search_nodes-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_search_nodes-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS' => array(
          'module' => 'facetapi',
          'delta' => 'QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => array(
          'module' => 'facetapi',
          'delta' => 'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-4Erg9yLvJMABad12YSuX81wXLf2eoV17' => array(
          'module' => 'facetapi',
          'delta' => '4Erg9yLvJMABad12YSuX81wXLf2eoV17',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global search page to search trough all content (nodes).');
  t('cap4more - Search');
  $export['c4m_search_nodes'] = $context;

  return $export;
}
