<?php
/**
 * @file
 * c4m_search_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_search_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_search_nodes';
  $context->description = 'Global search page to search trough all content (nodes).';
  $context->tag = 'cap4more - Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_search_content' => 'c4m_search_content',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-c4m_search_content-page' => array(
          'module' => 'views',
          'delta' => '-exp-c4m_search_content-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS' => array(
          'module' => 'facetapi',
          'delta' => 'QjdXjCmQyf1I4MYpAXp20tgcG7rR8PKS',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW' => array(
          'module' => 'facetapi',
          'delta' => 'fzBPY1BAj0MTas5AQbIbJMNKqcb06xVW',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-JQeEQzhfJJBhHcXpX4531H7GTXL1viNU' => array(
          'module' => 'facetapi',
          'delta' => 'JQeEQzhfJJBhHcXpX4531H7GTXL1viNU',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global search page to search trough all content (nodes).');
  t('cap4more - Search');
  $export['c4m_search_nodes'] = $context;

  return $export;
}
