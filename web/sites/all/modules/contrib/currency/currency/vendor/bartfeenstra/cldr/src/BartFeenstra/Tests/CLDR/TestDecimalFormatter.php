<?php

/**
 * @file
 * Contains class \BartFeenstra\CLDR\TestDecimalFormatter.
 */

namespace BartFeenstra\Tests\CLDR;

use BartFeenstra\CLDR\DecimalFormatter;

/**
 * A testing version of IntegerFormatter.
 */
class TestDecimalFormatter extends DecimalFormatter {

  /**
   * Gets a class property.
   *
   * @param string $name
   *
   * @return mixed
   */
  function get($name) {
    return $this->$name;
  }
}
