<?php
/**
 * @file
 * c4m_og.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_og_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_hide_main_navigation';
  $context->description = 'Hide the main navigation menu when inside OG context';
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
    'unset_variables' => 'main_menu
secondary_menu',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Hide the main navigation menu when inside OG context');
  t('cap4more - OG');
  $export['c4m_context_og_hide_main_navigation'] = $context;

  return $export;
}
