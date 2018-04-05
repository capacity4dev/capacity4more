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
  $context->name = 'c4m_context_og_header_group';
  $context->description = 'Context for setting the header inside OG Group CT';
  $context->tag = 'cap4more - OG Group';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'group' => 'group',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_content_group-header_name_banner_group' => array(
          'module' => 'c4m_content_group',
          'delta' => 'header_name_banner_group',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for setting the header inside OG Group CT');
  t('cap4more - OG Group');
  $export['c4m_context_og_header_group'] = $context;

  return $export;
}
