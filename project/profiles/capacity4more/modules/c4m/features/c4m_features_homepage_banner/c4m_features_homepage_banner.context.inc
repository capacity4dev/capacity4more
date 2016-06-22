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
    'context' => array(
      'values' => array(
        '~c4m_overview_groups' => '~c4m_overview_groups',
        '~c4m_search_og' => '~c4m_search_og',
      ),
    ),
    'context_og_condition_group_type' => array(
      'values' => array(
        '_none_' => '_none_',
      ),
      'options' => array(
        'node_form' => 0,
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
    'theme_html' => array(
      'class' => 'intro-banner',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the capacity4more intro banner to the header of the homepage for logged in users.');
  t('cap4more - Homepage');
  $export['c4m_homepage_intro_banner'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_homepage_intro_banner_bis';
  $context->description = 'Adds the capacity4more intro banner to the header to all pages except the homepage for anonymous users';
  $context->tag = 'cap4more - Homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
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
    'theme_html' => array(
      'class' => 'intro-banner',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the capacity4more intro banner to the header to all pages except the homepage for anonymous users');
  t('cap4more - Homepage');
  $export['c4m_homepage_intro_banner_bis'] = $context;

  return $export;
}
