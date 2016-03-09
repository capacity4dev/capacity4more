<?php

/**
 * @file
 * Contains class CurrencyLocalePattern.
 */

use BartFeenstra\CLDR\CurrencyFormatter;

/**
 * A currency pattern for a locale.
 */
class CurrencyLocalePattern {

  /**
   * The locale as a combination of an ISO 639-1 language code and a country
   * code, separated by an underscore.
   *
   * @var string
   */
  public $locale = '';

  /**
   * Implements Chaos tools' exportable object "export_module" property.
   */
  public $export_module = 'currency';

  /**
   * Implements Chaos tools' exportable object "export_type" property.
   */
  public $export_type = 0;

  /**
   * The Unicode CLDR number pattern.
   *
   * @var string
   */
  public $pattern = NULL;

  /**
   * The decimal separator's replacement.
   *
   * @var string
   */
  public $symbol_decimal_separator = NULL;

  /**
   * The grouping separator's replacement.
   *
   * @var string
   */
  public $symbol_grouping_separator = NULL;

  /**
   * Implements Chaos tools' exportable object "table" property.
   */
  public $table = 'currency_locale_pattern';

  /**
   * Implements Ctools' exportables "type" property.
   *
   * @var string
   */
  public $type = 'Local';

  /**
   * Implements __construct().
   */
  function __construct(array $properties = array()) {
    foreach ($properties as $property => $value) {
      $this->$property = $value;
    }
  }

  /**
   * Formats an amount using this pattern.
   *
   * @param Currency $currency
   * @param string $amount
   *   A numeric string.
   *
   * @return string
   */
  function format(Currency $currency, $amount) {
    static $formatter = NULL;

    if (is_null($formatter) || $formatter->pattern != $this->pattern) {
      $formatter = new CurrencyFormatter($this->pattern, array(
        CurrencyFormatter::SYMBOL_SPECIAL_DECIMAL_SEPARATOR => $this->symbol_decimal_separator,
        CurrencyFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => $this->symbol_grouping_separator,
      ));
    }

    $formatted = $formatter->format($amount, $currency->sign);
    $formatted = str_replace(array('[XXX]', '[999]'), array($currency->ISO4217Code, $currency->ISO4217Number), $formatted);

    return $formatted;
  }

  /**
   * Loads a single CurrencyLocalePattern based on environment variables.
   *
   * If no country code is set in $language->currency_country_code, the
   * "site_default_country" system variable will be used instead. If a
   * CurrencyLocalePattern could not be loaded using these country sources and
   * $language->language, the locale pattern for en_US will be loaded. This is
   * consistent with Drupal's default language, which is US English.
   *
   * @throws RuntimeException
   *
   * @return CurrencyLocalePattern
   */
  static function loadFromEnv() {
    global $language;

    $locale_pattern = &drupal_static('currency_env_locale_pattern');

    if (is_null($locale_pattern)) {
      // Try this request's country code.
      if (self::getCountryCode()) {
        $locale_pattern = ctools_export_crud_load('currency_locale_pattern', $language->language . '_' . self::getCountryCode());
      }
      // Try the global default country code.
      if (!$locale_pattern && $country_code = variable_get('site_default_country', '')) {
        $locale_pattern = ctools_export_crud_load('currency_locale_pattern', $language->language . '_' . $country_code);
      }
      // Try the Currency default.
      if (!$locale_pattern) {
        $locale_pattern = ctools_export_crud_load('currency_locale_pattern', CURRENCY_DEFAULT_LOCALE);
      }
      if (!$locale_pattern) {
        throw new RuntimeException(t('The CurrencyLocalePattern en_US could not be loaded.'));
      }
    }

    return $locale_pattern;
  }

  /**
   * Sets the currency locale's country.
   *
   * @param string $country_code_new
   *   Any code that is also returned by country_get_list().
   *
   * @return null
   */
  static function setCountryCode($country_code_new) {
    $country_code = &drupal_static(__CLASS__ . '_country_code');
    $country_code = $country_code_new;
  }

  /**
   * Gets the currency locale's country.
   *
   * @return null|string
   */
  static function getCountryCode() {
    return drupal_static(__CLASS__ . '_country_code');
  }

  /**
   * Resets the currency locale's country.
   *
   * @return null
   */
  static function resetCountryCode() {
    drupal_static_reset(__CLASS__ . '_country_code');
  }
}
