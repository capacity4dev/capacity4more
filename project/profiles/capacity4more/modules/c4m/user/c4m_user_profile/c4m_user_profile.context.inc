<?php

/**
 * @file
 * c4m_user_profile.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function c4m_user_profile_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_user_profile_confirm_email';
  $context->description = '';
  $context->tag = 'cap4more - User';
  $context->conditions = array(
    'c4m_user' => array(
      'values' => array(
        'confirm_email' => 'confirm_email',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_user_profile-user_confirm_email' => array(
          'module' => 'c4m_user_profile',
          'delta' => 'user_confirm_email',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('cap4more - User');
  $export['c4m_user_profile_confirm_email'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'c4m_user_profile_is_invalid_email';
  $context->description = '';
  $context->tag = 'cap4more - User';
  $context->conditions = array(
    'c4m_user' => array(
      'values' => array(
        'is_invalid_email' => 'is_invalid_email',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'form' => 'form',
      ),
      'options' => array(
        'mode' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'c4m_user_profile-user_is_invalid_email' => array(
          'module' => 'c4m_user_profile',
          'delta' => 'user_is_invalid_email',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('cap4more - User');
  $export['c4m_user_profile_is_invalid_email'] = $context;

  return $export;
}
