<?php

/**
 * @file
 * c4m_user.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_user_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_user_comments';
  $context->description = '"my comments" page';
  $context->tag = 'cap4more - User comments';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'my_comments' => 'my_comments',
        'my_comments:page' => 'my_comments:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-c4m_current_search_comments' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_comments',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-my_comments-page' => array(
          'module' => 'views',
          'delta' => '-exp-my_comments-page',
          'region' => 'sidebar_first',
          'weight' => '-85',
        ),
        'c4m_user-c4m_back_to_my_content_link' => array(
          'module' => 'c4m_user',
          'delta' => 'c4m_back_to_my_content_link',
          'region' => 'sidebar_first',
          'weight' => '-84',
        ),
        'facetapi-z0ZWdgkZbPLU1TJrbGrvIMR0OoqyvXRa' => array(
          'module' => 'facetapi',
          'delta' => 'z0ZWdgkZbPLU1TJrbGrvIMR0OoqyvXRa',
          'region' => 'sidebar_first',
          'weight' => '-83',
        ),
        'facetapi-LCbhPBaJpwKclgI7jHQ9adTa9YUbXAO1' => array(
          'module' => 'facetapi',
          'delta' => 'LCbhPBaJpwKclgI7jHQ9adTa9YUbXAO1',
          'region' => 'sidebar_first',
          'weight' => '-82',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('"my comments" page');
  t('cap4more - User comments');
  $export['c4m_user_comments'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_user_content';
  $context->description = '"my content" page';
  $context->tag = 'cap4more - User';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'my_content' => 'my_content',
        'my_content:page' => 'my_content:page',
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
        'views--exp-my_content-page' => array(
          'module' => 'views',
          'delta' => '-exp-my_content-page',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'c4m_user-c4m_my_comments_link' => array(
          'module' => 'c4m_user',
          'delta' => 'c4m_my_comments_link',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-0fu22cwdXHTX0SCpBBcEbOR77Jm1IfBp' => array(
          'module' => 'facetapi',
          'delta' => '0fu22cwdXHTX0SCpBBcEbOR77Jm1IfBp',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-q300p1xON0icJkyRehKpatIQn7Zfnugr' => array(
          'module' => 'facetapi',
          'delta' => 'q300p1xON0icJkyRehKpatIQn7Zfnugr',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E' => array(
          'module' => 'facetapi',
          'delta' => 'SpfB5FmHUHWhgc7eyjZ86g8LsNjQHx8E',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('"my content" page');
  t('cap4more - User');
  $export['c4m_user_content'] = $context;

  return $export;
}
