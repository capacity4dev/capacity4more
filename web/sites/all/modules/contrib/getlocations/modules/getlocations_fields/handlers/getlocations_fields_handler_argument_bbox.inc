<?php

/**
 * @file
 * getlocations_fields_handler_argument_bbox.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Location bbox argument handler.
 * code derived from https://www.drupal.org/project/views_geofield_bbox.
 *
 */

/**
 * Argument handler to accept bbox
 */
class getlocations_fields_handler_argument_bbox extends views_handler_argument {

  /**
   * Filter options definition.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function default_argument_form(&$form, &$form_state) {
    parent::default_argument_form($form, $form_state);
    // Clarify this, since we're treating pulling from the query string as
    // different than a normal arg.
    $form['no_argument']['#title'] = 'When the filter value is NOT in the URL <em>as a normal Drupal argument</em>';
  }

  /**
   * Split BBOX string into {left, bottom, right, top}
   */
  function _convert_bbox_coords($bbox_coords_str) {
    $bbox_coords = explode(',', $bbox_coords_str);
    $bbox = array();
    if (count($bbox_coords) == 4) {
      $left   = $bbox_coords[0];
      $bottom = $bbox_coords[1];
      $right  = $bbox_coords[2];
      $top    = $bbox_coords[3];
      $left   = trim($left);
      $bottom = trim($bottom);
      $right  = trim($right);
      $top    = trim($top);
      if (is_numeric($left) && is_numeric($bottom) && is_numeric($right) && is_numeric($top)) {
        $bbox['left']   = floatval(getlocations_normalizelng($left));
        $bbox['bottom'] = floatval(getlocations_normalizelat($bottom));
        $bbox['right']  = floatval(getlocations_normalizelng($right));
        $bbox['top']    = floatval(getlocations_normalizelat($top));
        return $bbox;
      }
    }
    return FALSE;
  }

  /**
   * Use the filter to modify the query.
   */
  function query($group_by = FALSE) {
    $this->ensure_my_table();
    if ((empty($this->argument)) || ($this->view->base_field == 'search_api_id')) {
      return;
    }
    if (! $bbox = $this->_convert_bbox_coords($this->argument)) {
      return;
    }

    $table_alias = (empty($this->table_alias) ? '' : $this->table_alias . '.');
    $this->query->ensure_table($table_alias);
    if ($bbox['right'] > $bbox['left']) {
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
    $group = $this->query->set_where_group('AND');
    $this->query->add_where_expression($group, $where, array(':minlat' => $bbox['bottom'], ':maxlat' => $bbox['top'], ':minlon' => $bbox['right'], ':maxlon' => $bbox['left']));

  }

}
