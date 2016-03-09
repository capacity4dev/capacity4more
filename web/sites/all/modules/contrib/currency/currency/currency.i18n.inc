<?php

/**
 * @file
 * Contains implementations of Internationalization hooks.
 */

/**
 * Implements hook_i18n_string_info().
 */
function currency_i18n_string_info() {
  $groups['currency'] = array(
    'title' => t('Currencies'),
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function currency_i18n_object_info() {
  $objects['currency'] = array(
    'edit path' => 'admin/config/regional/currency/list/%currency/edit',
    'key' => 'ISO4217Code',
    'list callback' => 'currency_load_all',
    'placeholders' => array(
      '%currency' => 'ISO4217Code',
    ),
    'string translation' => array(
      'properties' => array(
        'title' => t('Currency name'),
      ),
      'textgroup' => 'currency',
      'translate path' => 'admin/config/regional/currency/list/%currency/translate/%i18n_language',
      'type' => 'currency',
    ),
    'title' => t('Currency'),
    'translate tab' => 'admin/config/regional/currency/list/%currency/translate',
  );

  return $objects;
}
