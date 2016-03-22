<?php
/**
 * @file
 * c4m_features_homepage_intro_block.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_homepage_intro_block_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_homepage_intro_block';
  $context->description = 'Adds the capacity4more intro block to the header of the homepage.';
  $context->tag = 'cap4more - Homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-intro_block-block_1' => array(
          'module' => 'views',
          'delta' => 'intro_block-block_1',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the capacity4more intro block to the header of the homepage.');
  t('cap4more - Homepage');
  $export['c4m_homepage_intro_block'] = $context;

  return $export;
}
