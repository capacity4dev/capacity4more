<?php
/**
 * @file
 * c4m_user_bar.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_user_bar_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_sitewide';
  $context->description = 'Sitewide context (always active)';
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
        'c4m_user_profile-user_welcome' => array(
          'module' => 'c4m_user_profile',
          'delta' => 'user_welcome',
          'region' => 'user_bar',
          'weight' => '-10',
        ),
        'c4m_features_footer-c4m_footer' => array(
          'module' => 'c4m_features_footer',
          'delta' => 'c4m_footer',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide context (always active)');
  t('cap4more - Sitewide');
  $export['c4m_context_sitewide'] = $context;

  return $export;
}
