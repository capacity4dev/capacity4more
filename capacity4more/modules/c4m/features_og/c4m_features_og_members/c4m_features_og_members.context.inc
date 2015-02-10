<?php
/**
 * @file
 * c4m_features_og_members.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_og_members_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_members';
  $context->description = 'Overview page of all Group members.';
  $context->tag = 'cap4more - Members';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'c4m_overview_og_members:page' => 'c4m_overview_og_members:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-19b677fbcbbec75280a91661ff86b178' => array(
          'module' => 'views',
          'delta' => '19b677fbcbbec75280a91661ff86b178',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-1nI1X13vjFOCoDtPbNHnLS8h5giilscl' => array(
          'module' => 'facetapi',
          'delta' => '1nI1X13vjFOCoDtPbNHnLS8h5giilscl',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-iQ26gccTLht1A9qD9c7qFfumTFyaMvX5' => array(
          'module' => 'facetapi',
          'delta' => 'iQ26gccTLht1A9qD9c7qFfumTFyaMvX5',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-W0DMisaKwCfTLdactv0tMtbP8g1Lyz26' => array(
          'module' => 'facetapi',
          'delta' => 'W0DMisaKwCfTLdactv0tMtbP8g1Lyz26',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group members.');
  t('cap4more - Members');
  $export['c4m_overview_og_members'] = $context;

  return $export;
}
