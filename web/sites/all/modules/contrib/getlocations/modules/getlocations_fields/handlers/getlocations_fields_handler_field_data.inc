<?php

/**
 * @file
 * getlocations_fields_handler_field_data.inc
 * Definition of views_handler_field_serialized.
 */

/**
 * Field handler to show data of serialized fields.
 *
 * @ingroup views_field_handlers
 */
class getlocations_fields_handler_field_data extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['key'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $opts = getlocations_fields_data_keys();
    $form['key'] = array(
      '#type' => 'select',
      '#title' => t('Which key should be displayed'),
      '#default_value' => $this->options['key'],
      '#options' => $opts,
    );
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    $value = (array) unserialize($value);
    if (! isset($value['data'][$this->options['key']])) {
      // default values
      $dvals = getlocations_fields_data_keys('d');
      $value['data'][$this->options['key']] = $dvals[$this->options['key']];
    }
    return check_plain($value['data'][$this->options['key']]);
  }

}
