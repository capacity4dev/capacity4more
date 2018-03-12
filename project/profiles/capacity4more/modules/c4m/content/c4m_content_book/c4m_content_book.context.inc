<?php

/**
 * @file
 * c4m_content_book.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_content_book_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'help_and_guidance';
  $context->description = '';
  $context->tag = 'cap4more - Help';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'help-guidance' => 'help-guidance',
        'help-guidance/*' => 'help-guidance/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_content_book-help_book_navigation' => array(
          'module' => 'c4m_content_book',
          'delta' => 'help_book_navigation',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('cap4more - Help');
  $export['help_and_guidance'] = $context;

  return $export;
}
