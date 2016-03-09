<?php

/**
 * @file
 * getlocations_fields_handler_field_coordinates.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Coordinates field handler.
 */

class getlocations_fields_handler_field_coordinates extends getlocations_fields_handler_field_latitude {

  function construct() {
    parent::construct();
    $this->additional_fields['longitude'] = 'longitude';
  }

  function render($values) {
    if ($this->options['style'] == 'dms') {
      return theme('getlocations_latitude_dms', array('latitude' => $values->{$this->field_alias})) . ', ' . theme('getlocations_longitude_dms', array('longitude' => $values->{$this->aliases['longitude']}));
    }
    else {
      return check_plain($values->{$this->field_alias}) . ', ' . check_plain($values->{$this->aliases['longitude']});
    }
  }
}
