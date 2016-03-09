<?php
// NEEDS TESTING
/**
 * @file
 * getlocations_fields_handler_argument_distance.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Location proximity argument handler.
 */

/**
 * Argument handler to accept proximity
 */

class getlocations_fields_handler_argument_distance extends views_handler_argument {
  function option_definition() {
    $options = parent::option_definition();
    $options['search_units'] = array('default' => 'km');
    $options['search_method'] = array('default' => 'mbr');
    $options['type'] = array('default' => 'latlon');
    return $options;
  }

  /**
   * Add a form elements to select options for this argument.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['type'] = array(
      '#title' => t('Coordinate Type'),
      '#type' => 'select',
      '#options' => array(
        'latlon' => t('Decimal Latitude and Longitude coordinates, comma delimited'),
      ),
      '#default_value' => $this->options['type'],
      '#description' => t('Type of center point.') . '<br />' . t('Lat/Lon argument format: lat,lon_distance') . '<br />' . t('where distance is either a number or a comma delimited pair of decimal degrees'),
    );

    // Units used.
    $form['search_units'] = getlocations_element_distance_unit(
      $this->options['search_units'],
      t('Distance unit'),
      t('Select the unit of distance. Decimal degrees should be comma delimited.')
    );

    $form['search_method'] = array(
      '#title' => t('Method'),
      '#type' => 'select',
      '#options' => array(
        'mbr' => t('Rectangular Proximity'),
        'dist' => t('Circular Proximity'),
      ),
      '#default_value' => $this->options['search_method'],
      '#description' => t('Method of determining proximity. Please note that Circular Proximity does not work with Decimal degrees.'),
    );
  }

  function calculate_coords() {
    if (!empty($this->value['latitude']) && !empty($this->value['longitude'])) {
      // If there are already coordinates, there's no work for us.
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Set up the query for this argument.
   *
   * The argument sent may be found at $this->argument.
   */
  function query($group_by = FALSE) {
    // Get and process argument.
    if ($this->options['type'] == 'latlon') {
      foreach ($this->view->argument as $argument) {
        if ($argument->field == 'distance') {
          $a = explode('_', $this->view->args[$argument->position]);
          if (count($a) == 2) {
            $this->value['search_distance'] = $a[1];
            $aa = explode(',', $a[0]);
            if (count($aa) == 2 && is_numeric($aa[0]) && is_numeric($aa[1])) {
              $this->value['latitude'] = $aa[0];
              $this->value['longitude'] = $aa[1];
            }
          }
          break;
        }
      }
    }

    // Coordinates available?
    if (!$this->calculate_coords()) {
      // Distance set?
      if (!empty($this->value['search_distance'])) {
        // Hmm, distance set but unable to resolve coordinates.
        // Force nothing to match.
        $this->query->add_where(0, "1 = 0");
      }
      return;
    }

    $this->ensure_my_table();

    $lat = $this->value['latitude'];
    $lon = $this->value['longitude'];

    // search_distance
    if ($this->options['search_units'] == 'dd') {
      list($lat_distance, $lon_distance) = explode(',', $this->value['search_distance']);

      $latrange[0] = floatval($lat - $lat_distance);
      $latrange[1] = floatval($lat + $lat_distance);
      $lonrange[0] = floatval($lon - $lon_distance);
      $lonrange[1] = floatval($lon + $lon_distance);
    }
    else {
      $distance_meters = getlocations_convert_distance_to_meters($this->value['search_distance'], $this->options['search_units']);
      $latrange = getlocations_earth_latitude_range($lat, $lon, $distance_meters);
      $lonrange = getlocations_earth_longitude_range($lat, $lon, $distance_meters);
    }

    // If the table alias is specified, add on the separator.
    $table_alias = (empty($this->table_alias) ? '' : $this->table_alias . '.');

    // Add MBR check (always).
    // In case we go past the 180/-180 mark for longitude.
    if ($lonrange[0] > $lonrange[1]) {
      $where = $table_alias . "latitude > :minlat
      AND " . $table_alias . "latitude < :maxlat
      AND ((" . $table_alias . "longitude < 180
      AND " . $table_alias . "longitude > :minlon)
      OR (" . $table_alias . "longitude < :maxlon
      AND " . $table_alias . "longitude > -180))";
    }
    else {
      $where = $table_alias . "latitude > :minlat
      AND " . $table_alias . "latitude < :maxlat
      AND " . $table_alias . "longitude > :minlon
      AND " . $table_alias . "longitude < :maxlon";
    }
    $this->query->add_where_expression(0, $where, array(':minlat' => $latrange[0], ':maxlat' => $latrange[1], ':minlon' => $lonrange[0], ':maxlon' => $lonrange[1]));

    if ($this->options['search_method'] == 'dist' && $this->options['search_units'] != 'dd') {
      // Add radius check.
      $this->query->add_where_expression(0, getlocations_earth_distance_sql($lat, $lon, $this->table_alias) . ' < :distance', array(':distance' => $distance_meters));
    }
  }
}
