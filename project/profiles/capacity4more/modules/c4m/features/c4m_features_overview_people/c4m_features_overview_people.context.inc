<?php

/**
 * @file
 * c4m_features_overview_people.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_people_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_people_list';
  $context->description = 'Overview page of all People, list display';
  $context->tag = 'cap4more - People';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_people:page' => 'c4m_overview_people:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-3ea5d2361b53bfac9a8a2c7de319e7ad' => array(
          'module' => 'views',
          'delta' => '3ea5d2361b53bfac9a8a2c7de319e7ad',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'c4m_views-views_page_title' => array(
          'module' => 'c4m_views',
          'delta' => 'views_page_title',
          'region' => 'content_above',
          'weight' => '-10',
        ),
        'current_search-c4m_current_search_users' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_users',
          'region' => 'content',
          'weight' => '-10',
        ),
        'c4m_user-c4m_block_contact_members' => array(
          'module' => 'c4m_user',
          'delta' => 'c4m_block_contact_members',
          'region' => 'sidebar_first_top',
          'weight' => '-10',
        ),
        'views--exp-c4m_overview_people-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_overview_people-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1nI1X13vjFOCoDtPbNHnLS8h5giilscl' => array(
          'module' => 'facetapi',
          'delta' => '1nI1X13vjFOCoDtPbNHnLS8h5giilscl',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-oHYTG4NDPjy81MJOgXQKa27VMI6koQlI' => array(
          'module' => 'facetapi',
          'delta' => 'oHYTG4NDPjy81MJOgXQKa27VMI6koQlI',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-okbRObcVrcftlQAKnMx7ns16BYwkgQpC' => array(
          'module' => 'facetapi',
          'delta' => 'okbRObcVrcftlQAKnMx7ns16BYwkgQpC',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-W0DMisaKwCfTLdactv0tMtbP8g1Lyz26' => array(
          'module' => 'facetapi',
          'delta' => 'W0DMisaKwCfTLdactv0tMtbP8g1Lyz26',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all People, list display');
  t('cap4more - People');
  $export['c4m_overview_people_list'] = $context;

  return $export;
}
