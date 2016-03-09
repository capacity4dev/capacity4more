<?php

/**
 * @file
 * Contains class \BartFeenstra\CLDR\TestIntegerFormatter.
 */

namespace BartFeenstra\Tests\CLDR;

use BartFeenstra\CLDR\IntegerFormatter;

/**
 * A testing version of IntegerFormatter.
 */
class TestIntegerFormatter extends IntegerFormatter {

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
