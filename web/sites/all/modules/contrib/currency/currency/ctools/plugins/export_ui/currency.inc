<?php

/**
 * @file
 * Contains the Ctools exportables UI for "currency" exportables.
 */

$plugin = array(
  'access' => 'currency.currency.administer',
  'form' => array(
    'settings' => 'currency_form_currency',
  ),
  'handler' => array(
    'class' => 'CurrencyCtoolsExportUI',
    'file' => '../../../includes/CurrencyCtoolsExportUI.inc',
    'parent' => 'ctools_export_ui',
  ),
  'menu' => array(
    'menu description' => 'Configure currencies and their metadata.',
    'menu item' => 'currency',
    'menu prefix' => 'admin/config/regional',
    'menu title' => 'Currencies',
  ),
  'schema' => 'currency',
  'title plural' => t('currencies'),
  'title plural proper' => t('Currencies'),
  'title singular' => t('currency'),
  'title singular proper' => t('Currency'),
);
