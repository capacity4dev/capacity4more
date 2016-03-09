<?php

/**
 * @file
 * Contains class CurrencyExchanger.
 */

/**
 * A currency exchanger that uses other available currency exchangers to load
 * exchange rates.
 */
class CurrencyExchanger implements CurrencyExchangerInterface {

  /**
   * Loads the configuration.
   *
   * @return array
   *   Keys are currency_exchanger plugin names. Values are booleans that
   *   describe whether the plugins are enabled. Items are ordered by weight.
   */
  public static function loadConfiguration() {
    ctools_include('plugins');
    $plugins = ctools_get_plugins('currency', 'currency_exchanger');
    $configuration = variable_get('currency_exchanger', array()) + array_fill_keys(array_keys($plugins), TRUE);
    // Skip CurrencyExchanger, because it is a utility/service and not a
    // regular plugin. It should never be part of the configuration anyway.
    // This unset() is just a fail-safe.
    unset($configuration['CurrencyExchanger']);

    return $configuration;
  }

  /**
   * Saves the configuration.
   *
   * @param array $configuration
   *   Keys are currency_exchanger plugin names. Values are booleans that
   *   describe whether the plugins are enabled. Items are ordered by weight.
   *
   * @return NULL
   */
  public static function saveConfiguration(array $configuration) {
    variable_set('currency_exchanger', $configuration);
  }

  /**
   * Returns the names of enabled currency exchanger classes, sorted by weight.
   *
   * @return array
   */
  static function loadExchangers() {
    ctools_include('plugins');
    $plugins = ctools_get_plugins('currency', 'currency_exchanger');

    $names = array_keys(array_filter(self::loadConfiguration()));
    $classes = array();
    foreach ($names as $name) {
      $classes[] = $plugins[$name]['exchanger']['class'];
    }

    return $classes;
  }

  /**
   * Implements CurrencyExchangerInterface::load().
   */
  static function load($currency_code_from, $currency_code_to) {
    if ($currency_code_from == $currency_code_to) {
      return 1;
    }
    foreach (self::loadExchangers() as $exchanger) {
      if ($rate = $exchanger::load($currency_code_from, $currency_code_to)) {
        return $rate;
      }
    }
    return FALSE;
  }

  /**
   * Implements CurrencyExchangerInterface::loadMultiple().
   */
  static function loadMultiple(array $currency_codes) {
    $rates = array();

    // Set rates for identical source and destination currencies.
    foreach ($currency_codes as $currency_code_from => $currency_codes_to) {
      foreach ($currency_codes_to as $index => $currency_code_to) {
        if ($currency_code_from == $currency_code_to) {
          $rates[$currency_code_from][$currency_code_to] = 1;
          unset($currency_codes[$currency_code_from][$index]);
        }
      }
    }

    foreach (self::loadExchangers() as $exchanger) {
      foreach ($exchanger::loadMultiple($currency_codes) as $currency_code_from => $currency_codes_to) {
        foreach ($currency_codes_to as $currency_code_to => $rate) {
          $rates[$currency_code_from][$currency_code_to] = $rate;
          // If we found a rate, prevent it from being looked up by the next exchanger.
          if ($rate) {
            $index = array_search($currency_code_to, $currency_codes[$currency_code_from]);
            unset($currency_codes[$currency_code_from][$index]);
          }
        }
      }
    }

    return $rates;
  }

  /**
   * Implements CurrencyExchangerInterface::operationsLinks().
   */
  static function operationsLinks() {
    return array(array(
      'title' => t('configure'),
      'href' => 'admin/config/regional/currency-exchange',
    ));
  }
}
