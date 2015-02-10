<?php
/**
 * @file
 * c4m_features_og_discussions.context.inc
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
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overview page of all Group members.');
  t('cap4more - Members');
  $export['c4m_overview_og_members'] = $context;

  return $export;
}
