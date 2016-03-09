<?php

/**
 * @file
 * getlocations_location_taxonomize.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Some useful functions for Location taxonomize
 */

define('LT_GETLOC_MODULE_ID', 'getlocations_location_taxonomize');
define('LT_GETLOC_MODULE_NAME', 'Location Taxonomize Getlocations fields');

/**
 * Keeps a list of all the variables maintained by this module, with their
 * default values.
 */
function _getlocations_location_taxonomize_variables() {
  $fields = getlocations_location_taxonomize_get_fields();
  // set field defaults
  foreach ($fields as $key => $value) {
    if ($key != 'country' && $key != 'province' && $key != 'city') {
      $fields[$key] = 0;
    }
  }
  return array(
    'getlocations_location_taxonomize_settings' => array(
      'fields'  => $fields,
    ),
  );
}

/**
 * Returns the Getlocations Fields fields that can be used for the Location Vocabulary
 * @param $assoc - whether to return an associative array (TRUE) or just an
 *                 indexed array (FALSE)
 * @param $labels - whether to return the labels of fields as array values
 */
function getlocations_location_taxonomize_get_fields($assoc = TRUE, $labels = FALSE) {
  // get fields from getlocations_fields table
  $defaults = array(
    'columns' => array(
      'glid'        => t('Glid'),
      'name'        => t('Name'),
      'street'      => t('Street'),
      'additional'  => t('Additional'),
      'city'        => t('City'),
      'province'    => t('Province'),
      'postal_code' => t('Post code'),
      'country'     => t('Country'),
      'latitude'    => t('Latitude'),
      'longitude'   => t('Longitude'),
    ),
  );
  $getlocations_fields_defaults = variable_get('getlocations_fields_defaults', $defaults);
  if (function_exists('getlocations_fields_defaults')) {
    $getlocations_fields_defaults = getlocations_fields_defaults();
  }
  $fields = $getlocations_fields_defaults['columns'];
  foreach ($fields as $key => $value) {
    $fields[$key] = $value;
  }
  // define the fields we support and their order
  $supported = array(
    'name',
    'street',
    'city',
    'province',
    'postal_code',
    'country',
  );

  $return = array();
  // remove unsupported fields
  foreach ($supported as $field) {
    if ($assoc) {
      if ($labels) {
        $return[$field] = $fields[$field];
      }
      else {
        $return[$field] = $field;
      }
    }
    else {
      $return[] = $field;
    }
  }
  return array_reverse($return);
}


/**
 * Sets all this module's variables to their default values
 */
function _getlocations_location_taxonomize_set_defaults() {
  $defaults = _getlocations_location_taxonomize_variables();
  foreach ($defaults as $key => $value) {
    if ($value) variable_set($key, $value);
    else variable_del($key);
  }
}

/**
 * Deletes all variables set by this module
 */
function _getlocations_location_taxonomize_del_variables() {
  $vars = _getlocations_location_taxonomize_variables();
  foreach ($vars as $key => $value) {
    variable_del($key);
  }
}

/**
 * Fixup the country name and province name fields
 */
function getlocations_location_taxonomize_fixup($location) {
  if (isset($location['country']) && ! empty($location['country'])) {
    if (drupal_strlen($location['country']) == 2) {
      // got code, get full name
      $location['country_name'] = getlocations_get_country_name($location['country']);
    }
    else {
      // got full name, get code if possible
      $location['country_name'] = $location['country'];
      $location['country'] = getlocations_get_country_id($location['country_name']);
    }
  }
  else {
    $location['country'] = '';
    $location['country_name'] = '';
  }
  // getlocations does not use codes for provinces
  if (isset($location['province'])) {
    $location['province_name'] = $location['province'];
  }
  else {
    $location['province'] = '';
    $location['province_name'] = '';
  }
  return $location;
}

/**
 * Tells Location Taxonomize the names used in this module for the 'Primary
 * Fields' Country, State/Province, City
 */
function getlocations_location_taxonomize_primary_field_names() {
  return array(
    'country',
    'country_name',
    'province',
    'province_name',
    'city',
  );
}
