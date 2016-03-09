<?php

/**
 * @file
 * Contains class \BartFeenstra\Currency\Input.
 */

namespace BartFeenstra\Currency;

/**
 * Helpers for parsing user input.
 */
class Input {

  public static $decimalSeparators = array(
    // A comma.
    ',',
    // A period (full stop).
    '.',
    // Arabic decimal separator.
    '٫',
    // A Persian Momayyez (forward slash).
    '/');

  /**
   * Parses an amount.
   *
   * @throws AmountNotNumericException
   *
   * @param string|int|float $amount
   *   Any optionally localized numeric value.
   *
   * @return string
   *   A numeric string.
   */
  public static function parseAmount($amount) {
    if (!is_numeric($amount)) {
      $amount = self::parseAmountDecimalSeparator($amount);
      $amount = self::parseAmountNegativeFormat($amount);
    }
    if (!is_numeric($amount)) {
      throw new AmountNotNumericException('The amount could not be interpreted as a numeric string.');
    }

    return (string) $amount;
  }

  /**
   * Parses an amount's decimal separator.
   *
   * @throws AmountInvalidDecimalSeparatorException
   *
   * @param string $amount
   *   Any optionally localized numeric value.
   *
   * @return string
   *   The amount with its decimal separator replaced by a period.
   */
  public static function parseAmountDecimalSeparator($amount) {
    $decimal_separator_counts = array();
    foreach (self::$decimalSeparators as $decimal_separator) {
      $decimal_separator_counts[$decimal_separator] = \mb_substr_count($amount, $decimal_separator);
    }
    $decimal_separator_counts_filtered = array_filter($decimal_separator_counts);
    if (count($decimal_separator_counts_filtered) > 1 || reset($decimal_separator_counts_filtered) !== FALSE && reset($decimal_separator_counts_filtered) != 1) {
      throw new AmountInvalidDecimalSeparatorException(strtr('The amount can only have no or one decimal separator and it must be one of "decimalSeparators".', array(
       'decimalSeparators' => implode(self::$decimalSeparators),
      )));
    }
    $amount = str_replace(self::$decimalSeparators, '.', $amount);

    return $amount;
  }

  /**
   * Parses a negative amount.
   *
   * @param string $amount
   *
   * @return string
   *   The amount with negative formatting replaced by a minus sign prefix.
   */
  public static function parseAmountNegativeFormat($amount) {
    // An amount wrapped in parentheses.
    $amount = preg_replace('/^\((.*?)\)$/', '-\\1', $amount);
    // An amount suffixed by a minus sign.
    $amount = preg_replace('/^(.*?)-$/', '-\\1', $amount);
    // Double minus signs.
    $amount = preg_replace('/--/', '', $amount);

    return $amount;
  }
}
