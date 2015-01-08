<?php
/**
 * @file
 * c4m_features_og_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_og_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_events';
  $context->description = 'Overview page of all Group Events';
  $context->tag = 'cap4more - Events';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_og_events:page' => 'c4m_overview_og_events:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-1c4f4c3eaf1f8bde7197f2a715ff4ee4' => array(
          'module' => 'views',
          'delta' => '1c4f4c3eaf1f8bde7197f2a715ff4ee4',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-ajPbeoCHay77liOuYn2HrFBMw0VZUgCz' => array(
          'module' => 'facetapi',
          'delta' => 'ajPbeoCHay77liOuYn2HrFBMw0VZUgCz',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
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
        'facetapi-O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0' => array(
          'module' => 'facetapi',
          'delta' => 'O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0',
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
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group Events');
  t('cap4more - Events');
  $export['c4m_overview_og_events'] = $context;

  return $export;
}
