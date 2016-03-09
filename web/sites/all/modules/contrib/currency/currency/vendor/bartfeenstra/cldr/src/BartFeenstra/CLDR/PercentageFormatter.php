<?php

/**
 * @file
 * Contains class \BartFeenstra\CLDR\Percentageformatter.
 */

namespace BartFeenstra\CLDR;

/**
 * Formats a percentage or permille according CLDR number pattern guidelines.
 */
class PercentageFormatter extends DecimalFormatter {

  /**
   * The percent symbol.
   *
   * @var string
   */
  const SYMBOL_SPECIAL_PERCENT = '%';

  /**
   * The permille symbol.
   *
   * Because there is no consistent way of writing "per mille" in English, we
   * use the Latin variant to prevent possible confusion with "million".
   *
   * @var string
   */
  const SYMBOL_SPECIAL_PERMILLE = '‰';

  /**
   * Overrides parent::replacePlaceholders()
   */
  function replacePlaceholders(array $symbols, array $replacements = array()) {
    parent::replacePlaceholders($symbols, array(self::SYMBOL_SPECIAL_PERCENT, self::SYMBOL_SPECIAL_PERMILLE));
  }
}
