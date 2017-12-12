<?php

/**
 * @file
 * c4m_features_og_discussions.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_og_discussions_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_detail_og_discussions';
  $context->description = 'The discussion detail page';
  $context->tag = 'cap4more - Discussions';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'discussion' => 'discussion',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'discussions',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('The discussion detail page');
  t('cap4more - Discussions');
  $export['c4m_detail_og_discussions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_discussions';
  $context->description = 'Overview page of all Group discussions.';
  $context->tag = 'cap4more - Discussions';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_og_discussions' => 'c4m_overview_og_discussions',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-335198393aafdd0f0f94e4359fccdd84' => array(
          'module' => 'views',
          'delta' => '335198393aafdd0f0f94e4359fccdd84',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-RA7qZWw02okb78IuBysWTadEIVCrCL1b' => array(
          'module' => 'facetapi',
          'delta' => 'RA7qZWw02okb78IuBysWTadEIVCrCL1b',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => array(
          'module' => 'facetapi',
          'delta' => 'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => array(
          'module' => 'facetapi',
          'delta' => 'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-4Erg9yLvJMABad12YSuX81wXLf2eoV17' => array(
          'module' => 'facetapi',
          'delta' => '4Erg9yLvJMABad12YSuX81wXLf2eoV17',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => array(
          'module' => 'facetapi',
          'delta' => 'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group discussions.');
  t('cap4more - Discussions');
  $export['c4m_overview_og_discussions'] = $context;

  return $export;
}
