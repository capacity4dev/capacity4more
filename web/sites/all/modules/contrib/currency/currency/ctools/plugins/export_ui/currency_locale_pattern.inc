<?php

/**
 * @file
 * Contains the Ctools exportables UI for "currency_locale_pattern"
 * exportables.
 */

$plugin = array(
  'access' => 'currency.currency_locale_pattern.administer',
  'form' => array(
    'settings' => 'currency_form_currency_locale_pattern',
  ),
  'handler' => array(
    'class' => 'CurrencyLocalePatternCtoolsExportUI',
    'file' => '../../../includes/CurrencyLocalePatternCtoolsExportUI.inc',
    'parent' => 'ctools_export_ui',
  ),
  'menu' => array(
    'menu description' => 'Configure how amounts of money should be displayed.',
    'menu item' => 'currency_locale_pattern',
    'menu prefix' => 'admin/config/regional',
    'menu title' => 'Currency localization',
  ),
  'schema' => 'currency_locale_pattern',
  'title plural' => t('locale patterns'),
  'title plural proper' => t('Locale patterns'),
  'title singular' => t('locale pattern'),
  'title singular proper' => t('Locale pattern'),
);