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
  $context->name = 'c4m_overview_og_members_list';
  $context->description = 'Overview page of all Group members, list display';
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
        'current_search-c4m_current_search_users' => array(
          'module' => 'current_search',
          'delta' => 'c4m_current_search_users',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-19b677fbcbbec75280a91661ff86b178' => array(
          'module' => 'views',
          'delta' => '19b677fbcbbec75280a91661ff86b178',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-oPJrsj5t5dR0ObxkordoLaKTO9qn01ha' => array(
          'module' => 'facetapi',
          'delta' => 'oPJrsj5t5dR0ObxkordoLaKTO9qn01ha',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-1nI1X13vjFOCoDtPbNHnLS8h5giilscl' => array(
          'module' => 'facetapi',
          'delta' => '1nI1X13vjFOCoDtPbNHnLS8h5giilscl',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-okbRObcVrcftlQAKnMx7ns16BYwkgQpC' => array(
          'module' => 'facetapi',
          'delta' => 'okbRObcVrcftlQAKnMx7ns16BYwkgQpC',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-W0DMisaKwCfTLdactv0tMtbP8g1Lyz26' => array(
          'module' => 'facetapi',
          'delta' => 'W0DMisaKwCfTLdactv0tMtbP8g1Lyz26',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group members, list display');
  t('cap4more - Members');
  $export['c4m_overview_og_members_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_overview_og_members_table';
  $context->description = 'Overview page of all Group members, table display';
  $context->tag = 'cap4more - Members';
  $context->conditions = array(
    'no_form' => array(
      'values' => array(
        'views_form_c4m_overview_og_members_page_1|Contact user' => 'views_form_c4m_overview_og_members_page_1|Contact user',
        'views_form_c4m_overview_og_members_page_1|Next' => 'views_form_c4m_overview_og_members_page_1|Next',
      ),
    ),
    'views' => array(
      'values' => array(
        'c4m_overview_og_members:page_1' => 'c4m_overview_og_members:page_1',
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
        'facetapi-oPJrsj5t5dR0ObxkordoLaKTO9qn01ha' => array(
          'module' => 'facetapi',
          'delta' => 'oPJrsj5t5dR0ObxkordoLaKTO9qn01ha',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-1nI1X13vjFOCoDtPbNHnLS8h5giilscl' => array(
          'module' => 'facetapi',
          'delta' => '1nI1X13vjFOCoDtPbNHnLS8h5giilscl',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-okbRObcVrcftlQAKnMx7ns16BYwkgQpC' => array(
          'module' => 'facetapi',
          'delta' => 'okbRObcVrcftlQAKnMx7ns16BYwkgQpC',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'facetapi-W0DMisaKwCfTLdactv0tMtbP8g1Lyz26' => array(
          'module' => 'facetapi',
          'delta' => 'W0DMisaKwCfTLdactv0tMtbP8g1Lyz26',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group members, table display');
  t('cap4more - Members');
  $export['c4m_overview_og_members_table'] = $context;

  return $export;
}
