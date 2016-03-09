<?php

/**
 * @file
 * Contains class \BartFeenstra\Tests\Currency\CurrencyTest.
 */

namespace BartFeenstra\Tests\Currency;

use BartFeenstra\Currency\Currency;
use BartFeenstra\Currency\Usage;

require_once __DIR__ . '/../../../../vendor/autoload.php';

/**
 * Tests \BartFeenstra\Currency\Currency
 */
class CurrencyTest extends \PHPUnit_Framework_TestCase {

  /**
   * Test listing .
   */
  function testResourceList() {
    $list = Currency::resourceListAll();
    foreach ($list as $iso_4217_code) {
      $this->assertSame(strlen($iso_4217_code), 3, 'Currency::getList() returns an array with three-letter strings (ISO 4217 codes).');
    }
  }

  /**
   * Returns YAML for a Currency object.
   *
   * @return string
   */
  function yaml() {
    return <<<'EOD'
alternativeSigns: {  }
exchangeRates: {  }
ISO4217Code: EUR
ISO4217Number: '978'
sign: ¤
subunits: 100
title: Euro
usage:
    - { ISO8601From: '2003-02-04', ISO8601To: '2006-06-03', ISO3166Code: CS }

EOD;
  }

  /**
   * Returns a Currency object.
   *
   * @return Currency
   */
  function currency() {
    $usage = new Usage();
    $usage->ISO8601From = '2003-02-04';
    $usage->ISO8601To = '2006-06-03';
    $usage->ISO3166Code = 'CS';
    $currency = new Currency();
    $currency->ISO4217Code = 'EUR';
    $currency->ISO4217Number = '978';
    $currency->sign = '¤';
    $currency->subunits = 100;
    $currency->title = 'Euro';
    $currency->usage = array($usage);

    return $currency;
  }

  /**
   * Test YAML parsing.
   */
  function testResourceParse() {
    $yaml = $this->yaml();
    $currency_parsed = new Currency();
    $currency_parsed->resourceParse($yaml);
    $this->assertInstanceOf('BartFeenstra\Currency\Currency', $currency_parsed);
    $this->assertInstanceOf('BartFeenstra\Currency\Usage', $currency_parsed->usage[0], 'Currency::parse() parses YAML code to a Usage object.');
    $currency = $this->currency();
    $this->assertSame(get_object_vars($currency->usage[0]), get_object_vars($currency_parsed->usage[0]), 'Currency::parse() parses YAML code to an identical Usage object.');
    unset($currency->usage);
    unset($currency_parsed->usage);
    $this->assertSame(get_object_vars($currency), get_object_vars($currency_parsed), 'Currency::parse() parses YAML code to an identical currency object.');
  }

  /**
   * Test dumping to YAML.
   */
  function testResourceDump() {
    $currency = $this->currency();
    $yaml = $this->yaml();
    $yaml_dumped = $currency->resourceDump();
    $this->assertSame($yaml, $yaml_dumped);
  }

  /**
   * Tests loading a single currency.
   */
  function testResourceLoad() {
    $currency = new Currency();
    $currency->resourceLoad('EUR');
    $this->assertInstanceOf('BartFeenstra\Currency\Currency', $currency, 'Currency::load() loads a single currency from file.');
    $error = FALSE;
    try {
      $currency->resourceLoad('123');
    }
    catch (\RuntimeException $e) {
      $error = TRUE;
    }
    $this->assertTrue($error);
  }

  /**
   * Tests getDecimals().
   */
  function testGetDecimals() {
    $currencies = array(
      'MGA' => 1,
      'EUR' => 2,
      'JPY' => 3,
    );
    foreach ($currencies as $currency_code => $decimals) {
      $currency = new Currency();
      $currency->resourceLoad($currency_code);
      $this->assertSame($currency->getDecimals(), $decimals);
    }
  }
}
