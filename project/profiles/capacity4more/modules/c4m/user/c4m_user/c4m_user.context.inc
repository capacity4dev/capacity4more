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
        'views--exp-my_content-page' => array(
          'module' => 'views',
          'delta' => '-exp-my_content-page',
          'region' => 'sidebar_first',
          'weight' => '-58',
        ),
        'facetapi-q300p1xON0icJkyRehKpatIQn7Zfnugr' => array(
          'module' => 'facetapi',
          'delta' => 'q300p1xON0icJkyRehKpatIQn7Zfnugr',
          'region' => 'sidebar_first',
          'weight' => '-57',
        ),
        'facetapi-dGKhc10y2QJpsM5ad2fQ7SS0YaaUVZXg' => array(
          'module' => 'facetapi',
          'delta' => 'dGKhc10y2QJpsM5ad2fQ7SS0YaaUVZXg',
          'region' => 'sidebar_first',
          'weight' => '-56',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('"my content" page');
  t('cap4more - User');

  return $export;
}
