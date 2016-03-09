<?php

/**
 * @file
 * Contains class Currency.
 */

/**
 * Describes a currency.
 */
class Currency extends BartFeenstra\Currency\Currency {

  /**
   * Implements Ctools' exportables "export_module" property.
   *
   * @var string
   */
  public $export_module = 'currency';

  /**
   * Implements Ctools' exportables "export_type" property.
   *
   * @var string
   */
  public $export_type = 0;

  /**
   * The number of subunits to round amounts in this currency to.
   *
   * @see Currency::getRoundingStep()
   *
   * @var integer
   */
  public $rounding_step = NULL;

  /**
   * Implements Ctools' exportables "table" property.
   *
   * @var string
   */
  public $table = 'currency';

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
   * Format an amount using this currency and the environment's default locale
   * pattern.
   *
   * This is a wrapper for CurrencyLocalePattern::format() in situations where
   * the environment's default locale pattern should be used.
   *
   * @param string $amount
   *   A numeric string.
   *
   * @return string
   */
  function format($amount) {
    return CurrencyLocalePattern::loadFromEnv()->format($this, $amount);
  }

  /**
   * Returns the rounding step.
   *
   * @return string|false
   *   The rounding step as a numeric string, or FALSE if unavailable.
   */
  function getRoundingStep() {
    if (is_numeric($this->rounding_step)) {
      return $this->rounding_step;
    }
    // If a rounding step was not set explicitely, the rounding step is equal
    // to one subunit.
    elseif (is_numeric($this->subunits)) {
      return $this->subunits > 0 ? currency_divide(1, $this->subunits) : 1;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Rounds an amount.
   *
   * @param string $amount
   *   A numeric string.
   *
   * @return string
   *   A numeric string.
   */
  function roundAmount($amount) {
    return currency_round($amount, $this->getRoundingStep());
  }

  /**
   * Translates the human-readable currency title.
   *
   * @param string|null $language_code
   *   The ISO 639-1 code of the language to translate the title to, or NULL to
   *   use the default language.
   *
   * @return string
   */
  function translateTitle($language_code = NULL) {
    if (module_exists('i18n_string')) {
      return i18n_string('currency:currency:' . $this->ISO4217Code . ':title', $this->title, array(
        'langcode' => $language_code,
      ));
    }
    return $this->title;
  }
}
