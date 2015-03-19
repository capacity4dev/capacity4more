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
        'views--exp-c4m_overview_groups-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_groups-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1nI1X13vjFOCoDtPbNHnLS8h5giilscl' => array(
          'module' => 'facetapi',
          'delta' => '1nI1X13vjFOCoDtPbNHnLS8h5giilscl',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0' => array(
          'module' => 'facetapi',
          'delta' => 'O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0',
          'region' => 'sidebar_first',
          'weight' => '-7',
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
