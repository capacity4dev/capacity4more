<?php

/**
 * @file
 * getlocations_fields_handler_field_latitude.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Latitude field handler.
 */

class getlocations_fields_handler_field_latitude extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['style'] = array('default' => 'dd');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['style'] = array(
      '#title' => t('Display style'),
      '#type' => 'select',
      '#options' => array(
        'dd' => t('Decimal degrees'),
        'dms' => t('Degrees, minutes, seconds'),
      ),
      '#default_value' => $this->options['style'],
    );
  }

  function render($values) {

    if ($this->options['style'] == 'dd') {
    return parent::render($values);
      return check_plain($values->{$this->field_alias});
    }
    else {
      return theme('getlocations_latitude_dms', array('latitude' => $values->{$this->field_alias}));
    }
  }
}
