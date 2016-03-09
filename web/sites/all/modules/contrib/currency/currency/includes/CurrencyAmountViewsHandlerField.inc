<?php

/**
 * @file
 * Contains class CurrencyAmountViewsHandlerField.
 */

/**
 * A Views field handler for currency amounts.
 *
 * This handler has two definition properties, that function identically to and
 * provide default values for the handler's options:
 * - currency_code
 * - currency_code_field
 * - currency_code_table
 *   See $this->option_definition() for a detailed explanation.
 */
class CurrencyAmountViewsHandlerField extends views_handler_field {

  /**
   * Implements the undocumented views_object::definition property.
   *
   * @var array
   */
  public $definition = array(
    // A default currency code to use for the amounts.
    'currency_code' => 'XXX',
    // The name of the database field the currency code is in.
    'currency_code_field' => NULL,
    // The name of the database table currency_field is in. Defaults to the
    // same table this handler is used on.
    'currency_code_table' => NULL,
  );

  /**
   * Overrides parent::set_definition().
   */
  function set_definition($definition) {
    $this->definition = array_merge($this->definition, $definition);
    if (isset($definition['field'])) {
      $this->real_field = $definition['field'];
    }
  }

  /**
   * Overrides parent::query().
   */
  function query() {
    $this->ensure_my_table();
    if ($this->definition['currency_code_field']) {
      $this->additional_fields['currency_code_field'] = array(
        'field' => $this->definition['currency_code_field'],
        'table' => $this->definition['currency_code_table'] ? $this->definition['currency_code_table'] : $this->table_alias,
      );
    }
    parent::query();
  }

  /**
   * Overrides parent::option_definition().
   *
   * @var array
   */
  function option_definition() {
    $options = parent::option_definition();

    // Whether to round amounts.
    $options['currency_round'] = array(
      'default' => FALSE,
    );

    return $options;
  }

  /**
   * Overrides parent::options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['currency_round'] = array(
      '#type' => 'checkbox',
      '#title' => t('Round amounts based on their currencies'),
      '#default_value' => $this->options['currency_round'],
    );
  }

  /**
   * Overrides parent::render().
   *
   * @throws RuntimeException
   */
  function render($values) {
    $currency = $this->getCurrency($values);
    $amount = $this->getAmount($values);
    if ($this->options['currency_round']) {
      $amount = $currency->roundAmount($amount);
    }

    return $currency->format($amount);
  }

  /**
   * Loads the Currency for this field.
   *
   * @throws RuntimeException
   *
   * @param stdClass $values
   *   A values object as received by $this->render().
   *
   * @return Currency
   */
  function getCurrency(stdClass $values) {
    $currency = NULL;

    if ($this->definition['currency_code_field']) {
      $currency_code = $this->get_value($values, 'currency_code_field');
      if ($currency_code) {
        $currency = currency_load($currency_code);
      }
    }
    if (!$currency) {
      $currency = currency_load($this->definition['currency_code']);
    }
    if (!$currency) {
      $currency = currency_load('XXX');
    }
    if (!$currency) {
      throw new RuntimeException(t('Could not load currency with ISO 4217 code XXX.'));
    }

    return $currency;
  }

  /**
   * Gets this field's.
   *
   * If the amount cannot be fetched from your implementation's database field
   * as a numeric string, you should override this method so it returns a
   * numeric/decimal representation of the amount.
   *
   * @param stdClass $values
   *   A values object as received by $this->render().
   *
   * @return string
   *   A numeric string.
   */
  function getAmount(stdClass $values) {
    return $this->get_value($values);
  }
}
