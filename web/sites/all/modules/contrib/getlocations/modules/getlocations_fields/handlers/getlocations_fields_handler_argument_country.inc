<?php
// NEEDS TESTING
/**
 * @file
 * getlocations_fields_handler_argument_country.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Location country argument handler.
 */

/**
 * Argument handler to accept country code
 */
class getlocations_fields_handler_argument_country extends views_handler_argument {
  function option_definition() {
    $options = parent::option_definition();
    $options['type'] = array('default' => 'country');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['type'] = array(
      '#type' => 'value',
      '#value' => 'country'
    );

  }

  /**
   * Set up the query for this argument.
   *
   * The argument sent may be found at $this->argument.
   */
  function query($group_by = FALSE) {
    $value = FALSE;

    if ($this->options['type'] == 'country' && isset($this->argument)) {
      $value = drupal_strtolower($this->argument);
      // check this
      if (! getlocations_get_country_name($value)) {
        $value = FALSE;
      }
    }

    if ($value) {
      $alias = ($this->table_alias ? $this->table_alias : $this->table);
      $field = $alias . '.' . $this->real_field;
      $operator = '=';
      $this->query->add_where($group_by, $field, $value, $operator);
    }
  }

}
