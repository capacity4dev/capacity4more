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
  $context->name = 'c4m_detail_og_media';
  $context->description = 'The media detail page';
  $context->tag = 'cap4more - Media';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'photo' => 'photo',
        'photoalbum' => 'photoalbum',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'media',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('The media detail page');
  t('cap4more - Media');
  $export['c4m_detail_og_media'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_media';
  $context->description = 'Overview page of all Group Photos and Photo albums.';
  $context->tag = 'cap4more - Media';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_og_media:page' => 'c4m_overview_og_media:page',
        'c4m_overview_og_media:page_1' => 'c4m_overview_og_media:page_1',
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
          'weight' => '-10',
        ),
        'facetapi-2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH' => array(
          'module' => 'facetapi',
          'delta' => '2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
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
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
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
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group Photos and Photo albums.');
  t('cap4more - Media');
  $export['c4m_overview_og_media'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_media_overlay';
  $context->description = 'Overview page of all Group Photos and Photo albums in overlay mode.';
  $context->tag = 'cap4more - Media';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_og_media:page_2' => 'c4m_overview_og_media:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c7659bb4865380f683243f9405e54cec' => array(
          'module' => 'views',
          'delta' => 'c7659bb4865380f683243f9405e54cec',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH' => array(
          'module' => 'facetapi',
          'delta' => '2qrTnbxWr0rI2lmcQR6mBDryPwkuS1PH',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
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
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
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
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group Photos and Photo albums in overlay mode.');
  t('cap4more - Media');
  $export['c4m_overview_og_media_overlay'] = $context;

  return $export;
}
