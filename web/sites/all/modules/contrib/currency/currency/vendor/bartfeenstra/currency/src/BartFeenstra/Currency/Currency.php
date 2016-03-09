<?php

/**
 * @file
 * Contains class \BartFeenstra\Currency\Currency.
 */

namespace BartFeenstra\Currency;

use Symfony\Component\Yaml\Yaml;

/**
 * Describes a currency.
 */
class Currency {

  /**
   * Alternative (non-official) currency signs.
   *
   * @var array
   *   An array of strings that are similar to Currency::sign.
   */
  public $alternativeSigns = array();

  /**
   * Exchange rates to other currencies.
   *
   * @var array
   *   Keys are ISO 4217 codes, values are numeric strings.
   */
  public $exchangeRates = array();

  /**
   * ISO 4217 currency code.
   *
   * @var string
   */
  public $ISO4217Code = NULL;

  /**
   * ISO 4217 currency number.
   *
   * @var string
   */
  public $ISO4217Number = NULL;

  /**
   * The currency's official sign, such as '€' or '$'.
   *
   * @var string
   */
  public $sign = '¤';

  /**
   * The number of subunits this currency has.
   *
   * @var integer|null
   */
  public $subunits = NULL;

  /**
   * Human-readable title in US English.
   *
   * @var string
   */
  public $title = NULL;

  /**
   * This currency's usage.
   *
   * @var array
   *   An array of \BartFeenstra\Currency\Usage objects.
   */
  public $usage = array();

  /**
   * The path to the resources directory.
   */
  public static $resourcePath = '/../../../resources/';

  /**
   * A list of the ISO 4217 codes of all known currency resources.
   */
  public static $resourceISO4217Codes = array();

  /**
   * Returns the directory that contains the currency resources.
   *
   * @return string
   */
  public static function resourceDir() {
    return __DIR__ . self::$resourcePath;
  }

  /**
   * Lists all currency resources in the library.
   *
   * @return array
   *   An array with ISO 4217 currency codes.
   */
  public static function resourceListAll() {
    if (!self::$resourceISO4217Codes) {
      $directory = new \RecursiveDirectoryIterator(self::resourceDir());
      foreach ($directory as $item) {
        if (preg_match('#^...\.yml$#', $item->getFilename())) {
          self::$resourceISO4217Codes[] = substr($item->getFilename(), 0, 3);
        }
      }
    }

    return self::$resourceISO4217Codes;
  }

  /**
   * Loads a currency resource into this object.
   *
   * @param string $iso_4217_code
   */
  public function resourceLoad($iso_4217_code) {
    $filepath = self::resourceDir() . "$iso_4217_code.yml";
    if (is_readable($filepath)) {
      $this->resourceParse(file_get_contents($filepath));
    }
    else {
      throw new \RuntimeException(sprintf('The currency resource file %s does not exist or is not readable.', $filepath));
    }
  }

  /**
   * Parses a YAML file into this object.
   *
   * @param string $yaml
   */
  public function resourceParse($yaml) {
    $currency_data = Yaml::parse($yaml);
    $usages_data = $currency_data['usage'];
    $currency_data['usage'] = array();
    foreach ($currency_data as $property => $value) {
      $this->$property = $value;
    }
    foreach ($usages_data as $usage_data) {
      $usage = new Usage;
      foreach ($usage_data as $property => $value) {
        $usage->$property = $value;
      }
      $this->usage[] = $usage;
    }
    unset($currency_data);
  }

  /**
   * Dumps this object to YAML code.
   *
   * @return string
   */
  public function resourceDump() {
    $currency_data = get_object_vars($this);
    $currency_data['usage'] = array();
    foreach ($this->usage as $usage) {
      $currency_data['usage'][] = get_object_vars($usage);
    }

    return Yaml::dump($currency_data);
  }

  /**
   * Returns the number of decimals.
   *
   * @return int
   */
  function getDecimals() {
    $decimals = 0;
    if ($this->subunits > 0) {
      $decimals = 1;
      while (pow(10, $decimals) < $this->subunits) {
        $decimals++;
      }
    }

    return $decimals;
  }
}
