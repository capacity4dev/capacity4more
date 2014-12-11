<?php
/**
 * @file
 * c4m_content_group.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_content_group_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_header';
  $context->description = 'Context for setting the header inside OG';
  $context->tag = 'cap4more - OG';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_content_group-header_name_banner' => array(
          'module' => 'c4m_content_group',
          'delta' => 'header_name_banner',
          'region' => 'content_top',
          'weight' => '-26',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for setting the header inside OG');
  t('cap4more - OG');
  $export['c4m_context_og_header'] = $context;

  return $export;
}
