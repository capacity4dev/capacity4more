<?php

/**
 * @file
 * Contains class CurrencyViewsHandlerField.
 */

/**
 * A Views field handler for fields that contain ISO 4217 currency codes.
 *
 * This handler has one definition property:
 * - currency_property: the name of the Currency class property of which to
 *   display the value, which must be a scalar.
 */
class CurrencyViewsHandlerField extends views_handler_field {

  /**
   * Overrides parent::render().
   *
   * @throws RuntimeException
   */
  function render($values) {
    $property = !empty($this->definition['currency_property']) ? $this->definition['currency_property'] : NULL;
    if ($property && property_exists('Currency', $property)) {
      $currency_code = $this->get_value($values);
      $currency = currency_load($currency_code);
      if ($currency) {
        if ($property == 'title') {
          return $currency->translateTitle();
        }
        else {
          return $currency->$property;
        }
      }
      else {
        return t('Unknuwn currency %currency_code', array(
          '%currency_code' => $currency_code,
        ));
      }
    }
    throw new RuntimeException(t('CurrencyViewsHandlerField requires a set-up currency property handler definition.'));
  }
}
