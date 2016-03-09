<?php

/**
 * @file
 * Contains class \BartFeenstra\Tests\CLDR\PercentageFormatterTest.
 */

namespace BartFeenstra\Tests\CLDR;

use BartFeenstra\CLDR\PercentageFormatter;

require_once __DIR__ . '/../../../../vendor/autoload.php';

/**
 * Tests \BartFeenstra\CLDR\PercentageFormatter
 */
class PercentageFormatterTest extends \PHPUnit_Framework_TestCase {

  /**
   * Test amount formatting.
   */
  function testFormat() {
    $formatter = new PercentageFormatter('0.00%‰');
    $number = 123456.789;
    $result_expected = '123456.789%‰';
    $result = $formatter->format($number);
    $this->assertSame($result, $result_expected, 'BartFeenstra\CLDR\PercentageFormatter::format() formats amount ' . $number . ' as ' . $result_expected . ' using pattern ' . $formatter->pattern . ' (result was ' . $result . ').');
  }
}
