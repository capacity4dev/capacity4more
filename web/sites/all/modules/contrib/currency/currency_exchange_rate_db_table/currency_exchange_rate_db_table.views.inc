<?php

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_data().
 */
function currency_exchange_rate_db_table_views_data() {
  // Table configuration.
  $data['currency_exchange_rate_db_table']['table'] = array(
    'base' => array(
      'title' => t('Currency exchange rates'),
    ),
    'group' => t('Currency'),
  );

  // Field configuration.
  $properties = array(
    'currency_code_from' => array(
      'ISO4217Code' => t('Source currency code'),
      'ISO4217Number' => t('Source currency number'),
      'subunits' => t('Source currency number subunits'),
      'sign' => t('Source currency sign'),
      'title' => t('Source currency name'),
    ),
    'currency_code_to' => array(
      'ISO4217Code' => t('Destination currency code'),
      'ISO4217Number' => t('Destination currency number'),
      'subunits' => t('Destination currency number of subunits'),
      'sign' => t('Destination currency sign'),
      'title' => t('Destination currency name'),
    ),
  );
  foreach ($properties as $field => $field_properties) {
    foreach ($field_properties as $property => $title) {
      // Don't alias the currency code.
      $suffix = $property == 'ISO4217Code' ? '' : '_' . $property;
      $data['currency_exchange_rate_db_table'][$field . $suffix] = array(
        'title' => $title,
        'real field' => $field,
        'field' => array(
          'handler' => 'CurrencyViewsHandlerField',
          'currency_property' => $property,
        ),
        'filter' => array(
          'handler' => 'CurrencyViewsHandlerFilter',
        ),
      );
    }
  }
  $data['currency_exchange_rate_db_table']['rate'] = array(
    'title' => t('Conversion rate'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'float' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['currency_exchange_rate_db_table']['rate_amount'] = array(
    'title' => t('Conversion rate (as an amount)'),
    'real field' => 'rate',
    'field' => array(
      'handler' => 'CurrencyAmountViewsHandlerField',
      'currency_code_field' => 'currency_code_to',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  return $data;
}
