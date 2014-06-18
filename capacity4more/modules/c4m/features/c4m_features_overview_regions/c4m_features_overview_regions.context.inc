<?php
/**
 * @file
 * c4m_features_overview_regions.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_overview_regions_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_region_detail';
  $context->description = 'Add list of countries that are referenced from this region';
  $context->tag = 'cap4more - Region';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'region' => 'region',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-3c639f3d0d55b7bced203782338d6cce' => array(
          'module' => 'views',
          'delta' => '3c639f3d0d55b7bced203782338d6cce',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add list of countries that are referenced from this region');
  t('cap4more - Region');
  $export['c4m_context_region_detail'] = $context;

  return $export;
}
