<?php
/**
 * @file
 * c4m_features_og_overview_tasks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_features_og_overview_tasks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_context_og_tasklist_detail';
  $context->description = 'Node detail page of a task list';
  $context->tag = 'cap4more - Tasklist';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'tasklist' => 'tasklist',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c4m_overview_og_tasks-block_1' => array(
          'module' => 'views',
          'delta' => 'c4m_overview_og_tasks-block_1',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node detail page of a task list');
  t('cap4more - Tasklist');
  $export['c4m_context_og_tasklist_detail'] = $context;

  return $export;
}
