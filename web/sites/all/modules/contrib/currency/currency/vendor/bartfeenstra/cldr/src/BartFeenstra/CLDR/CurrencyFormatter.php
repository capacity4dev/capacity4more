<?php

/**
 * @file
 * Contains class \BartFeenstra\CLDR\CurrencyFormatter.
 */

namespace BartFeenstra\CLDR;

/**
 * Formats a currency according CLDR number pattern guidelines.
 */
class CurrencyFormatter extends DecimalFormatter {

  /**
   * The currency's symbol.
   *
   * @var string
   */
  const SYMBOL_SPECIAL_CURRENCY = '¤';

  /**
   * Overrides parent::replacePlaceholders()
   */
  function replacePlaceholders(array $symbols, array $replacements = array()) {
    parent::replacePlaceholders($symbols, array(self::SYMBOL_SPECIAL_CURRENCY));
  }

  /**
   * Overrides parent::format().
   *
   * @param float|string $number
   * @param string $currency_sign
   *   An ISO 4217 code or currency sign.
   */
  public function format($number, $currency_sign = NULL) {
    $this->symbol_replacements[self::SYMBOL_SPECIAL_CURRENCY] = $currency_sign;

    return parent::format($number);
  }
}
