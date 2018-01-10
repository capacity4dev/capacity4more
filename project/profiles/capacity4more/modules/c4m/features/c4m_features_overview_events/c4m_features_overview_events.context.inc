<?php

/**
 * @file
 * c4m_features_overview_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_events_landing';
  $context->description = 'Overview page of all Events';
  $context->tag = 'cap4more - Events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f50a38aa0504f420d3fc307402101fb9' => array(
          'module' => 'views',
          'delta' => 'f50a38aa0504f420d3fc307402101fb9',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'c4m_search_filter-search_filter' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter',
          'region' => 'content_above',
          'weight' => '-8',
        ),
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'c4m_features_overview_events-event_total_count' => array(
          'module' => 'c4m_features_overview_events',
          'delta' => 'event_total_count',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-7bb1ca745e57e37fa0b09b237cb1086c' => array(
          'module' => 'views',
          'delta' => '7bb1ca745e57e37fa0b09b237cb1086c',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'c4m_features_overview_events-event_views_links' => array(
          'module' => 'c4m_features_overview_events',
          'delta' => 'event_views_links',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => array(
          'module' => 'facetapi',
          'delta' => 'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => array(
          'module' => 'facetapi',
          'delta' => 'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-4Erg9yLvJMABad12YSuX81wXLf2eoV17' => array(
          'module' => 'facetapi',
          'delta' => '4Erg9yLvJMABad12YSuX81wXLf2eoV17',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Events');
  t('cap4more - Events');
  $export['c4m_overview_events_landing'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_events_past';
  $context->description = 'Overview page of all past Events';
  $context->tag = 'cap4more - Events';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_events:page_1' => 'c4m_overview_events:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f50a38aa0504f420d3fc307402101fb9' => array(
          'module' => 'views',
          'delta' => 'f50a38aa0504f420d3fc307402101fb9',
          'region' => 'content_above',
          'weight' => '-86',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-85',
        ),
        'c4m_search_filter-search_filter' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter',
          'region' => 'content_above',
          'weight' => '-84',
        ),
        'views--exp-c4m_overview_events-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_events-page_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'c4m_features_overview_events-event_views_links' => array(
          'module' => 'c4m_features_overview_events',
          'delta' => 'event_views_links',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => array(
          'module' => 'facetapi',
          'delta' => 'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => array(
          'module' => 'facetapi',
          'delta' => 'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-4Erg9yLvJMABad12YSuX81wXLf2eoV17' => array(
          'module' => 'facetapi',
          'delta' => '4Erg9yLvJMABad12YSuX81wXLf2eoV17',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all past Events');
  t('cap4more - Events');
  $export['c4m_overview_events_past'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_events_upcoming';
  $context->description = 'Overview page of all upcoming Events';
  $context->tag = 'cap4more - Events';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_events:page' => 'c4m_overview_events:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f50a38aa0504f420d3fc307402101fb9' => array(
          'module' => 'views',
          'delta' => 'f50a38aa0504f420d3fc307402101fb9',
          'region' => 'content_above',
          'weight' => '-86',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-85',
        ),
        'c4m_search_filter-search_filter' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter',
          'region' => 'content_above',
          'weight' => '-84',
        ),
        'views--exp-c4m_overview_events-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_events-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'c4m_features_overview_events-event_views_links' => array(
          'module' => 'c4m_features_overview_events',
          'delta' => 'event_views_links',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => array(
          'module' => 'facetapi',
          'delta' => 'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => array(
          'module' => 'facetapi',
          'delta' => 'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'facetapi-4Erg9yLvJMABad12YSuX81wXLf2eoV17' => array(
          'module' => 'facetapi',
          'delta' => '4Erg9yLvJMABad12YSuX81wXLf2eoV17',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all upcoming Events');
  t('cap4more - Events');
  $export['c4m_overview_events_upcoming'] = $context;

  return $export;
}
