<?php
/**
 * @file
 * c4m_features_learning_space.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_learning_space_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_detail_learning';
  $context->description = 'The Learning Space Context';
  $context->tag = 'cap4more - Learning';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'learning' => 'learning',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c4m_learning_content-block' => array(
          'module' => 'views',
          'delta' => 'c4m_learning_content-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The Learning Space Context');
  t('cap4more - Learning');
  $export['c4m_detail_learning'] = $context;

  return $export;
}
