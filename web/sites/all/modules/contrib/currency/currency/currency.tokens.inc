<?php

/**
 * @file
 * Contains Token API hook implementations.
 */

/**
 * Implements hook_token_info().
 */
function currency_token_info() {
  // Token groups.
  $types['currency'] = array(
    'description' => t('ISO 4217 currencies.'),
    'name' => t('Currencies'),
    'needs-data' => 'currency',
  );

  // Tokens.
  $tokens['currency']['code'] = array(
    'description' => t('The ISO 4217 currency code.'),
    'name' => t('Currency code'),
    'type' => 'text',
  );
  $tokens['currency']['number'] = array(
    'description' => t('The ISO 4217 currency number.'),
    'name' => t('Currency number'),
    'type' => 'text',
  );
  $tokens['currency']['subunits'] = array(
    'description' => t('The number of subunits.'),
    'name' => t('Subunits'),
    'type' => 'text',
  );
  $tokens['currency']['sign'] = array(
    'description' => '',
    'name' => t('Sign'),
    'type' => 'text',
  );
  $tokens['currency']['title'] = array(
    'description' => '',
    'name' => t('Name'),
    'type' => 'text',
  );

  return array(
    'tokens' => $tokens,
    'types' => $types,
  );
}

/**
 * Implements hook_tokens().
 */
function currency_tokens($type, array $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'currency' && isset($data['currency'])) {
    $currency_code = $data['currency'];
    if (isset($tokens['code'])) {
      $replacements[$tokens['code']] = $data['currency'];
      unset($tokens['code']);
    }
    if ($tokens) {
      ctools_include('export');
      $currency = currency_load($data['currency']);
      $map = array(
        'number' => 'ISO4217Number',
        'subunits' => 'subunits',
        'sign' => 'sign',
        'title' => 'title',
      );
      foreach ($tokens as $token => $original) {
        if (isset($map[$token])) {
          $replacements[$original] = $currency->{$map[$token]};
        }
      }
    }
  }

  return $replacements;
}
