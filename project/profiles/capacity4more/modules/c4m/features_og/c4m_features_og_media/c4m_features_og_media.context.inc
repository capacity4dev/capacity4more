<?php

/**
 * @file
 * c4m_features_og_media.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_og_media_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_media';
  $context->description = 'Overview page of all Group Photos and Photo albums.';
  $context->tag = 'cap4more - Media';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'overview_og_media:page' => 'overview_og_media:page',
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
        'views--exp-overview_og_media-page' => array(
          'module' => 'views',
          'delta' => '-exp-overview_og_media-page',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'facetapi-4Erg9yLvJMABad12YSuX81wXLf2eoV17' => array(
          'module' => 'facetapi',
          'delta' => '4Erg9yLvJMABad12YSuX81wXLf2eoV17',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'facetapi-C1uZlhNqghipCSyxxgucWQMdVsq4ppY5' => array(
          'module' => 'facetapi',
          'delta' => 'C1uZlhNqghipCSyxxgucWQMdVsq4ppY5',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'facetapi-w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx' => array(
          'module' => 'facetapi',
          'delta' => 'w6asLvBjgGIFWmRHVJbMQJLQjE6uslPx',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'facetapi-ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3' => array(
          'module' => 'facetapi',
          'delta' => 'ZOrDSi3aBn5Scpx14PeuQryeYEcBDDJ3',
          'region' => 'sidebar_first',
          'weight' => '4',
        ),
        'facetapi-Bg1WyXIiqObnRZN1Exkukcw9Arm3On07' => array(
          'module' => 'facetapi',
          'delta' => 'Bg1WyXIiqObnRZN1Exkukcw9Arm3On07',
          'region' => 'sidebar_first',
          'weight' => '5',
        ),
        'facetapi-O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0' => array(
          'module' => 'facetapi',
          'delta' => 'O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0',
          'region' => 'sidebar_first',
          'weight' => '6',
        ),
        'facetapi-QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS' => array(
          'module' => 'facetapi',
          'delta' => 'QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS',
          'region' => 'sidebar_first',
          'weight' => '7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group Photos and Photo albums.');
  t('cap4more - Media');
  $export['c4m_overview_og_media'] = $context;

  return $export;
}
