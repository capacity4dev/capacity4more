<?php

/**
 * @file
 * Contains class \BartFeenstra\Tests\CLDR\CurrencyFormatterTest.
 */

namespace BartFeenstra\Tests\CLDR;

use BartFeenstra\CLDR\CurrencyFormatter;

require_once __DIR__ . '/../../../../vendor/autoload.php';

/**
 * Tests \BartFeenstra\CLDR\CurrencyFormatter
 */
class CurrencyFormatterTest extends \PHPUnit_Framework_TestCase {

  /**
   * Test amount formatting.
   */
  function testFormat() {
    $formatter = new CurrencyFormatter('¤0.00');
    $currency_sign = '€';
    $number = 123456.789;
    $result_expected = $currency_sign . '123456.789';
    $result = $formatter->format($number, $currency_sign);
    $this->assertSame($result, $result_expected, 'BartFeenstra\CLDR\CurrencyFormatter::format() formats amount ' . $number . ' as ' . $result_expected . ' using pattern ' . $formatter->pattern . ' (result was ' . $result . ').');
  }
}
