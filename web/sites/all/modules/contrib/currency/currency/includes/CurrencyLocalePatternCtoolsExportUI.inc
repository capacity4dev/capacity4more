<?php

/**
 * @file
 * Contains class CurrencyLocalePatternCtoolsExportUI.
 */

/**
 * A Ctools export UI plugin for CurrencyLocalePattern.
 */
class CurrencyLocalePatternCtoolsExportUI extends ctools_export_ui {

  /**
   * Overrides parent::list_build_row().
   */
  function list_build_row($item, &$form_state, $operations) {
    require_once DRUPAL_ROOT . '/includes/iso.inc';
    require_once DRUPAL_ROOT . '/includes/locale.inc';

    $languages = _locale_get_predefined_list();
    $countries = country_get_list();

    parent::list_build_row($item, $form_state, $operations);
    $name = $item->{$this->plugin['export']['key']};
    $cells = $this->rows[$name]['data'];
    $language_code = substr($item->locale, 0, 2);
    $country_code = substr($item->locale, 3);
    // Locale information may be imported from external sources and Drupal core
    // may not be updated with the most recent languages and countries, so fall
    // back to "Unknown".
    $language_title = isset($languages[$language_code]) ? $languages[$language_code][0] : t('Unknown');
    $country_title = isset($countries[$country_code]) ? $countries[$country_code] : t('Unknown');
    $cells = array_merge(array_slice($cells, 0, 1), array($language_title), array($country_title), array_slice($cells, 1));
    $this->rows[$name]['data'] = $cells;
  }

  /**
   * Overrides parent::list_table_header().
   */
  function list_table_header() {
    $header = parent::list_table_header();
    $header = array_merge(array_slice($header, 0, 1), array(t('Language')), array(t('Country')), array_slice($header, 1));
    $header[0] = t('Locale');

    return $header;
  }

  /**
   * Override parent::list_sort_options().
   */
  function list_sort_options() {
    $options = parent::list_sort_options();
    $options['disabled'] = t('Enabled, locale');
    $options['name'] = t('Locale');

    return $options;
  }
}
