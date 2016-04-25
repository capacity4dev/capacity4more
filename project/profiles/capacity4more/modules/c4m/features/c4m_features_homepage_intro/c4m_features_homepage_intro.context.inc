<?php
/**
 * @file
 * c4m_features_homepage_intro.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_homepage_intro_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_homepage_intro_video';
  $context->description = 'Adds the capacity4more intro video to the header of the homepage for anonymous users.';
  $context->tag = 'cap4more - Homepage';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_none_' => '_none_',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
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
        'c4m_features_homepage_intro-video' => array(
          'module' => 'c4m_features_homepage_intro',
          'delta' => 'video',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the capacity4more intro video to the header of the homepage for anonymous users.');
  t('cap4more - Homepage');
  $export['c4m_homepage_intro_video'] = $context;

  return $export;
}
