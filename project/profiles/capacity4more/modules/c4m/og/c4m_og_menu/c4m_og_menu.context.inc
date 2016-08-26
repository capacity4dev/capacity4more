<?php
/**
 * @file
 * c4m_og_menu.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_og_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_menu';
  $context->description = 'Context for setting the sub menu inside OG';
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
        'menu-c4m-og-menu' => array(
          'module' => 'menu',
          'delta' => 'c4m-og-menu',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for setting the sub menu inside OG');
  t('cap4more - OG');
  $export['c4m_context_og_menu'] = $context;

  return $export;
}
