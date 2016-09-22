<?php

/**
 * @file
 * c4m_user.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function c4m_user_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass();
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'c4m_user_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/5 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['c4m_user_cron'] = $cron_rule;

  return $cron_rules;

}
