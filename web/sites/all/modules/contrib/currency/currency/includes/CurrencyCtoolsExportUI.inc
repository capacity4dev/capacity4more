<?php

/**
 * @file
 * Contains class CurrencyCtoolsExportUI.
 */

/**
 * A Ctools export UI plugin for Currency.
 */
class CurrencyCtoolsExportUI extends ctools_export_ui {

  /**
   * Overrides parent::list_build_row().
   */
  function list_build_row($item, &$form_state, $operations) {
    parent::list_build_row($item, $form_state, $operations);
    $name = $item->{$this->plugin['export']['key']};
    $cells = $this->rows[$name]['data'];
    $cells = array_merge(array_slice($cells, 0, 1), array($item->translateTitle()), array_slice($cells, 1));
    $this->rows[$name]['data'] = $cells;
  }

  /**
   * Overrides parent::list_table_header().
   */
  function list_table_header() {
    $header = parent::list_table_header();
    $header = array_merge(array_slice($header, 0, 1), array(t('Name')), array_slice($header, 1));
    $header[0] = t('Currency code');

    return $header;
  }

  /**
   * Override parent::list_sort_options().
   */
  function list_sort_options() {
    $options = parent::list_sort_options();
    $options['disabled'] = t('Enabled, currency code');
    $options['name'] = t('Currency code');

    return $options;
  }
}
