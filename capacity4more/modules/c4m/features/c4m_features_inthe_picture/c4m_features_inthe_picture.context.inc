<?php
/**
 * @file
 * c4m_features_inthe_picture.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_inthe_picture_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_inthe_picture_groups';
  $context->description = 'Overview page of Groups';
  $context->tag = 'cap4more - Groups';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '/groups' => '/groups',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-f38a69c54df9a3d3692d47f18bb2c0af' => array(
          'module' => 'views',
          'delta' => 'f38a69c54df9a3d3692d47f18bb2c0af',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of Groups');
  t('cap4more - Groups');
  $export['c4m_overview_inthe_picture_groups'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_inthe_picture_projects';
  $context->description = 'Overview page of Projects';
  $context->tag = 'cap4more - Projects';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '/projects' => '/projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-0832eb7e6f1d35503c5b3a8f77094884' => array(
          'module' => 'views',
          'delta' => '0832eb7e6f1d35503c5b3a8f77094884',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of Projects');
  t('cap4more - Projects');
  $export['c4m_overview_inthe_picture_projects'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_inthe_picture_voicesandviews';
  $context->description = 'Overview page of Voices & Views';
  $context->tag = 'cap4more - Voices & Views';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '/voicesandviews' => '/voicesandviews',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of Voices & Views');
  t('cap4more - Voices & Views');
  $export['c4m_overview_inthe_picture_voicesandviews'] = $context;

  return $export;
}
