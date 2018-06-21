<?php

/**
 * @file
 * c4m_features_overview_feeds.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_feeds_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_feeds';
  $context->description = 'Overview page of all Feeds';
  $context->tag = 'cap4more - Feeds';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_feeds:page' => 'c4m_overview_feeds:page',
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
        'views--exp-c4m_overview_feeds-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_feeds-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Feeds');
  t('cap4more - Feeds');
  $export['c4m_overview_feeds'] = $context;

  return $export;
}
