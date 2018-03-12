<?php

/**
 * @file
 * c4m_features_overview_articles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_articles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_detail_articles';
  $context->description = 'Detail page of Voices & Views';
  $context->tag = 'cap4more - Voices & Views';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => array(
      0 => 'main-menu:articles',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Detail page of Voices & Views');
  t('cap4more - Voices & Views');
  $export['c4m_detail_articles'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_articles';
  $context->description = 'Overview page of all Voices & Views';
  $context->tag = 'cap4more - Voices & Views';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_articles' => 'c4m_overview_articles',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-2c363d334c50dc9097114985e613ef22' => array(
          'module' => 'views',
          'delta' => '2c363d334c50dc9097114985e613ef22',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'c4m_search_filter-search_filter_interests' => array(
          'module' => 'c4m_search_filter',
          'delta' => 'search_filter_interests',
          'region' => 'content_above',
          'weight' => '-8',
        ),
        'current_search-c4m_current_search_nodes' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_nodes',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-c4m_overview_articles-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_articles-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Voices & Views');
  t('cap4more - Voices & Views');
  $export['c4m_overview_articles'] = $context;

  return $export;
}
