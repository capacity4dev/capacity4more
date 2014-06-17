<?php
/**
 * @file
 * c4m_og_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_og_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_global';
  $context->description = 'Global context for inside OG';
  $context->tag = 'cap4more - OG';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-group-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-group-menu',
          'region' => 'featured',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global context for inside OG');
  t('cap4more - OG');
  $export['c4m_context_og_global'] = $context;

  return $export;
}
