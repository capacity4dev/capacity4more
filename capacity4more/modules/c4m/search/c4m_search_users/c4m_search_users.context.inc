<?php
/**
 * @file
 * c4m_search_users.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_search_users_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_search_users';
  $context->description = 'Global search page to search trough all users.';
  $context->tag = 'cap4more - Search Users';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_search_users' => 'c4m_search_users',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-c4m_search_users-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_search_users-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1nI1X13vjFOCoDtPbNHnLS8h5giilscl' => array(
          'module' => 'facetapi',
          'delta' => '1nI1X13vjFOCoDtPbNHnLS8h5giilscl',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-W0DMisaKwCfTLdactv0tMtbP8g1Lyz26' => array(
          'module' => 'facetapi',
          'delta' => 'W0DMisaKwCfTLdactv0tMtbP8g1Lyz26',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-iQ26gccTLht1A9qD9c7qFfumTFyaMvX5' => array(
          'module' => 'facetapi',
          'delta' => 'iQ26gccTLht1A9qD9c7qFfumTFyaMvX5',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0' => array(
          'module' => 'facetapi',
          'delta' => 'O8mTVZgvB4vQXVOP4FQE0yR9tc0ehTp0',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global search page to search trough all users.');
  t('cap4more - Search Users');
  $export['c4m_search_users'] = $context;

  return $export;
}
