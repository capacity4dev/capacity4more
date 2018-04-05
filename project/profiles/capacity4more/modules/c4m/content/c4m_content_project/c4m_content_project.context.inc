<?php

/**
 * @file
 * c4m_content_project.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_content_project_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_header_project';
  $context->description = 'Context for setting the header inside OG Project CT';
  $context->tag = 'cap4more - OG Project';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_content_project-header_name_banner_project' => array(
          'module' => 'c4m_content_project',
          'delta' => 'header_name_banner_project',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for setting the header inside OG Project CT');
  t('cap4more - OG Project');
  $export['c4m_context_og_header_project'] = $context;

  return $export;
}
