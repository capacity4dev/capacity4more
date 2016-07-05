<?php
/**
 * @file
 * c4m_features_responsive.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_responsive_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_responsive';
  $context->description = 'Behavior for responsive design';
  $context->tag = 'cap4more - Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'off_canvas',
          'weight' => '-10',
        ),
        'c4m_features_header-c4m_header_menu' => array(
          'module' => 'c4m_features_header',
          'delta' => 'c4m_header_menu',
          'region' => 'off_canvas',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Behavior for responsive design');
  t('cap4more - Sitewide');
  $export['c4m_context_responsive'] = $context;

  return $export;
}
