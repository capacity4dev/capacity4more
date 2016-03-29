<?php
/**
 * @file
 * c4m_features_homepage_banner.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_homepage_banner_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_homepage_intro_banner';
  $context->description = 'Adds the capacity4more intro banner to the header of the homepage for logged in users.';
  $context->tag = 'cap4more - Homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_features_homepage_intro-banner' => array(
          'module' => 'c4m_features_homepage_intro',
          'delta' => 'banner',
          'region' => 'header',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the capacity4more intro banner to the header of the homepage for logged in users.');
  t('cap4more - Homepage');
  $export['c4m_homepage_intro_banner'] = $context;

  return $export;
}
