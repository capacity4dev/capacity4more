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
        'views-22e892cecdd19333a8cbdbce3f0955a9' => array(
          'module' => 'views',
          'delta' => '22e892cecdd19333a8cbdbce3f0955a9',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-a293ba715040ddc0f8c58e830b5a412d' => array(
          'module' => 'views',
          'delta' => 'a293ba715040ddc0f8c58e830b5a412d',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-fafb99d29b872f81d88c61ac133d6050' => array(
          'module' => 'views',
          'delta' => 'fafb99d29b872f81d88c61ac133d6050',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-7bb1ca745e57e37fa0b09b237cb1086c' => array(
          'module' => 'views',
          'delta' => '7bb1ca745e57e37fa0b09b237cb1086c',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-U2RdpobygmZU7ZqgOAKBurq0NTgFuZ10' => array(
          'module' => 'facetapi',
          'delta' => 'U2RdpobygmZU7ZqgOAKBurq0NTgFuZ10',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => array(
          'module' => 'facetapi',
          'delta' => 'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'facetapi-ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => array(
          'module' => 'facetapi',
          'delta' => 'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3',
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
        'facetapi-w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => array(
          'module' => 'facetapi',
          'delta' => 'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx',
          'region' => 'sidebar_first',
          'weight' => '-1',
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
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => array(
          'module' => 'facetapi',
          'delta' => 'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
        'facetapi-w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => array(
          'module' => 'facetapi',
          'delta' => 'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx',
          'region' => 'sidebar_first',
          'weight' => '-2',
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
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => array(
          'module' => 'facetapi',
          'delta' => 'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3',
          'region' => 'sidebar_first',
          'weight' => '-6',
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
        'facetapi-w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => array(
          'module' => 'facetapi',
          'delta' => 'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx',
          'region' => 'sidebar_first',
          'weight' => '-2',
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
