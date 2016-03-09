<?php

/**
 * @file
 * getlocations_fields_handler_sort_distance.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Distance sort handler.
 */

class getlocations_fields_handler_sort_distance extends views_handler_sort {

  function option_definition() {
    $options = parent::option_definition();
    $options['origin'] = array('default' => 'nid_arg');
    $options['latitude'] = array('default' => '');
    $options['longitude'] = array('default' => '');
#    $options['postal_code'] = array('default' => '');
#    $options['country'] = array('default' => '');
    $options['php_code'] = array('default' => '');
    $options['nid_arg'] = array('default' => '');
    $options['nid_loc_field'] = array('default' => 'node');
    $options['uid_arg'] = array('default' => '');
    $options['uid_loc_field'] = array('default' => 'user');
    $options['tid_arg'] = array('default' => '');
    $options['tid_loc_field'] = array('default' => 'taxonomy_term');
    $options['cid_arg'] = array('default' => '');
    $options['cid_loc_field'] = array('default' => 'comment');
    $options['distance_arg'] = array('default' => '');
    return $options;
  }

  function has_extra_options() {
    return TRUE;
  }

  function extra_options_form(&$form, &$form_state) {

    $form['origin'] = getlocations_fields_element_origin($this->options['origin'], TRUE);

    $form['latitude'] = getlocations_fields_element_latitude($this->options['latitude']);

    $form['longitude'] = getlocations_fields_element_longitude($this->options['longitude']);

#    $form['postal_code'] = getlocations_fields_element_postal_code($this->options['postal_code']);

#    $form['country'] = getlocations_fields_element_country($this->options['country']);

    $form['php_code'] = getlocations_fields_element_php_code($this->options['php_code']);

    list($nid_argument_options, $uid_argument_options, $tid_argument_options, $cid_argument_options) = getlocations_fields_views_proximity_get_argument_options($this->view);
    $loc_field_options = getlocations_fields_views_proximity_get_location_field_options();
    if ($nid_argument_options) {
      $form['nid_arg'] = getlocations_fields_element_nid_arg($this->options['nid_arg'], $nid_argument_options);
      $form['nid_loc_field'] = getlocations_fields_element_nid_loc_field($this->options['nid_loc_field'], $loc_field_options);
    }
    if ($uid_argument_options) {
      $form['uid_arg'] = getlocations_fields_element_uid_arg($this->options['uid_arg'], $uid_argument_options);
      $form['uid_loc_field'] = getlocations_fields_element_uid_loc_field($this->options['uid_loc_field'], $loc_field_options);
    }
    ### TESTING
    if ($tid_argument_options) {
      $form['tid_arg'] = getlocations_fields_element_tid_arg($this->options['tid_arg'], $tid_argument_options);
      $form['tid_loc_field'] = getlocations_fields_element_tid_loc_field($this->options['tid_loc_field'], $loc_field_options);
    }
    if ($cid_argument_options) {
      $form['cid_arg'] = getlocations_fields_element_cid_arg($this->options['cid_arg'], $cid_argument_options);
      $form['cid_loc_field'] = getlocations_fields_element_cid_loc_field($this->options['cid_loc_field'], $loc_field_options);
    }

  }

  function query() {

    // Google Autocomplete data needs to be transferred to options
    if ($this->options['origin'] == 'search' && isset($this->view->exposed_data['distance']) && $this->view->exposed_data['distance']['latitude'] && $this->view->exposed_data['distance']['longitude']) {
      $this->options['latitude'] = $this->view->exposed_data['distance']['latitude'];
      $this->options['longitude'] = $this->view->exposed_data['distance']['longitude'];
    }

    $coordinates = getlocations_fields_views_proximity_get_reference_location($this->view, $this->options);

    $this->ensure_my_table();

    // OK, so this part will need a little explanation.
    // Since the distance calculation is so icky, we try quite hard
    // to save some work for the database.
    // If someone has added a field that matches the sort, we just sort on that column!
    $alias = $this->table_alias . '_' . $this->field . '_sort';

    foreach ($this->view->field as $filter) {
      if ($filter->table == 'getlocations_fields' && $filter->field == 'distance' && $filter->options['relationship'] == $this->options['relationship']) {

        if ($filter->options['origin'] == $this->options['origin']
            && $filter->options['latitude'] == $this->options['latitude']
            && $filter->options['longitude'] == $this->options['longitude']) {
          // We have a match! Sync aliases to make it easier on the database.
          $alias = $filter->field_alias;
          #$distance = $filter->options['search_distance'];
        }
      }
    }

    if (! empty($coordinates) && $coordinates['latitude'] && $coordinates['longitude']) {
      //  // This is done exactly the same as the field version.
      //  // Views is ok with us redefining the formula for a field.
      //  // If ANYTHING differs in the configuration, we will use a new alias.
      $this->query->add_orderby(NULL, getlocations_earth_distance_sql($coordinates['latitude'], $coordinates['longitude'], $this->table_alias), $this->options['order'], $alias);
    }

  }
}
