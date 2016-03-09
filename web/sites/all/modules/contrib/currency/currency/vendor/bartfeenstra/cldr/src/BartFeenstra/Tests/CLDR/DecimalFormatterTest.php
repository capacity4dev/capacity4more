<?php

/**
 * @file
 * Contains class \BartFeenstra\Tests\CLDR\DecimalFormatterTest.
 */

namespace BartFeenstra\Tests\CLDR;

use BartFeenstra\CLDR\DecimalFormatter;

require_once __DIR__ . '/../../../../vendor/autoload.php';

/**
 * Tests \BartFeenstra\CLDR\DecimalFormatter
 */
class DecimalFormatterTest extends \PHPUnit_Framework_TestCase {

  /**
   * Test cloning.
   */
  function testClone() {
    $formatter = new TestDecimalFormatter('#,##0.00;#,##0.00-', array(
      DecimalFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => '.',
    ));
    $formatter_clone = clone $formatter;
    $symbols = $formatter->get('symbols');
    $symbols[DecimalFormatter::POSITIVE][DecimalFormatter::MAJOR][0]->symbol = 'AAA';
    $symbols_clone = $formatter_clone->get('symbols');
    $this->assertNotSame($symbols[DecimalFormatter::POSITIVE][DecimalFormatter::MAJOR][0]->symbol, $symbols_clone[DecimalFormatter::POSITIVE][DecimalFormatter::MAJOR][0]->symbol, 'When a DecimalFormatter is cloned, so are its NumberPatternSymbol elements.');
  }

  /**
   * Tests number pattern validation.
   */
  function testPatternValidation() {
    // Test validating valid number patterns.
    $patterns_valid = array(
      'foo.00;bar.00',
    );
    foreach ($patterns_valid as $pattern) {
      try {
        new DecimalFormatter($pattern);
        $valid = TRUE;
      }
      catch (\Exception $e) {
        $valid = FALSE;
      }
      $this->assertTrue($valid, 'BartFeenstra\CLDR\DecimalFormatter::__construct() does not throw an exception for valid pattern ' . $pattern . '.');
    }

    // Test validating invalid number patterns.
    $patterns_invalid = array(
      // An empty pattern.
      '',
      // No decimal separator.
      'foo',
      'foo:bar',
      // Empty negative pattern.
      'foo.00;',
      // Empty positive pattern.
      ';bar.00',
    );
    foreach ($patterns_invalid as $pattern) {
      try {
        new DecimalFormatter($pattern);
        $valid = TRUE;
      }
      catch (\Exception $e) {
        $valid = FALSE;
      }
      $this->assertFalse($valid, 'BartFeenstra\CLDR\DecimalFormatter::__construct() throws an exception for invalid pattern ' . $pattern . '.');
    }
  }

  /**
   * Test amount formatting.
   *
   * @depends testPatternValidation
   */
  function testFormat() {
    $numbers = array(123456789, -12345678.9, 1234567.89, -123456.789);
    $patterns = array(
      // Test inconsistent group sizes and a custom negative pattern.
      array(
        'formatter' => new DecimalFormatter('#,##0.00;#,##0.00-', array(
          DecimalFormatter::SYMBOL_SPECIAL_DECIMAL_SEPARATOR => ',',
          DecimalFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => '.',
        )),
        'results' => array(
          '123.456.789,00',
          '12.345.678,90-',
          '1.234.567,89',
          '123.456,789-',
        ),
      ),
      // Test without grouping separators, a default negative pattern, no
      // decimals, and a pattern that is shorter than the numbers.
      array(
        'formatter' => new DecimalFormatter('#0.', array(
          DecimalFormatter::SYMBOL_SPECIAL_DECIMAL_SEPARATOR => ',',
          DecimalFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => '',
        )),
        'results' => array(
          '123456789,',
          '-12345678,',
          '1234567,',
          '-123456,',
        ),
      ),
      // Test identical decimal and grouping separators, identical positive
      // and negative patterns, and redundant hashes and grouping separators.
      array(
        'formatter' => new DecimalFormatter('###,###,###,##0.00;###,###,###,##0.00', array(
          DecimalFormatter::SYMBOL_SPECIAL_DECIMAL_SEPARATOR => '.',
          DecimalFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => '.',
        )),
        'results' => array(
          '123.456.789.00',
          '12.345.678.90',
          '1.234.567.89',
          '123.456.789',
        ),
      ),
      // Test some unusual character combinations and positions, and an
      // empty decimal separator.
      array(
        'formatter' => new DecimalFormatter("####000/@##0.<span style=\"text-transform: uppercase';'\">00</span>--;-####000/@##0.<span style=\"text-transform: uppercase';'\">00</span>--", array(
          DecimalFormatter::SYMBOL_SPECIAL_DECIMAL_SEPARATOR => '',
          DecimalFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => '.',
        )),
        'results' => array(
          '123456/@789<span style="text-transform: uppercase;">00</span>--',
          '-12345/@678<span style="text-transform: uppercase;">90</span>--',
          '1234/@567<span style="text-transform: uppercase;">89</span>--',
          '-123/@456<span style="text-transform: uppercase;">789</span>--',
        ),
      ),
      // Test character escaping.
      array(
        'formatter' => new DecimalFormatter("##'#'.00", array(
          DecimalFormatter::SYMBOL_SPECIAL_DECIMAL_SEPARATOR => ',',
          DecimalFormatter::SYMBOL_SPECIAL_GROUPING_SEPARATOR => '.',
        )),
        'results' => array(
          '123456789#,00',
          '-12345678#,90',
          '1234567#,89',
          '-123456#,789',
        ),
      ),
    );
    foreach ($patterns as $pattern_info) {
      foreach ($numbers as $i => $number) {
        $formatter = $pattern_info['formatter'];
        $result_expected = $pattern_info['results'][$i];
        $result = $formatter->format($number);
        $this->assertSame($result, $result_expected, 'BartFeenstra\CLDR\DecimalFormatter::format() formats amount ' . $number . ' as ' . $result_expected . ' using pattern ' . $formatter->pattern . ' (result was ' . $result . ').');
      }
    }
  }
}
