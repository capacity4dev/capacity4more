<?php
/**
 * @file
 * c4m_features_og_documents.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_og_documents_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_documents';
  $context->description = 'Overview page of all Group Documents and Photo albums.';
  $context->tag = 'cap4more - Documents';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_og_documents' => 'c4m_overview_og_documents',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7372782a23f49e1db577016cb840d3bb' => array(
          'module' => 'views',
          'delta' => '7372782a23f49e1db577016cb840d3bb',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH' => array(
          'module' => 'facetapi',
          'delta' => '2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH',
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
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group Documents and Photo albums.');
  t('cap4more - Documents');
  $export['c4m_overview_og_documents'] = $context;

  return $export;
}
