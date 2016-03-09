<?php

/**
 * @file
 * getlocations_search.admin.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * getlocations_search module administration functions.
 */

/**
 * Function to display the getlocations_search admin settings form
 * @return
 *   Returns the form.
 */
function getlocations_search_settings_form() {

  $getlocations_search_defaults = getlocations_search_defaults();
  $form = array();
  $pagetitle = '<div><h4>' . t('Getlocations Search') . '</h4></div>';
  $form['pagetitle'] = array('#markup' => $pagetitle);

  $form += _getlocations_search_settings_form($getlocations_search_defaults, 'admin');

  $form['getlocations_search_paths'] = array(
    '#type' => 'fieldset',
    '#title' => t('Javascript paths'),
    '#description' => t('For advanced users who want to supply their own javascript.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    // This will store all the defaults in one variable.
    '#tree' => TRUE,
  );
  $getlocations_search_paths = getlocations_search_paths_get();
  $form['getlocations_search_paths']['getlocations_search_path'] = getlocations_element_path(
    t('Path to getlocations_search javascript file'),
    $getlocations_search_paths['getlocations_search_path'],
    70,
    128,
    t('Where the getlocations_search javascript file is located.')
  );
  $form['getlocations_search_paths']['getlocations_search_admin_path'] = getlocations_element_path(
    t('Path to getlocations_search admin javascript file'),
    $getlocations_search_paths['getlocations_search_admin_path'],
    70,
    128,
    t('Where the getlocations_search admin javascript file is located.')
  );

  $form['getlocations_search_paths']['reset'] = getlocations_element_dd(
    t('Reset'),
    0,
    array(0 => t('No'), 1 => t('Reset'), 2 => t('Reset to minified')),
    t('Reset the paths to the defaults.')
  );

  $form = system_settings_form($form);
  unset($form['#theme']);
  $form['#theme'] = 'getlocations_search_settings_form';
  $form['#validate'][] = 'getlocations_search_settings_validate';
  return $form;

}

// form shared between admin config and block config
function _getlocations_search_settings_form($defaults, $which = 'admin') {
  $getlocations_search_paths = getlocations_search_paths_get();
  drupal_add_js($getlocations_search_paths['getlocations_search_admin_path']);

  $getlocations_defaults = getlocations_defaults();
  $defaults['jquery_colorpicker_enabled'] = $getlocations_defaults['jquery_colorpicker_enabled'];

  $form = array();
  $varname = 'getlocations_search_defaults';
  $title = t('Getlocations Search Default settings');
  $desc = t('The settings here will provide the defaults for Getlocations Search.');
  if ($which == 'block') {
    $varname = 'getlocations_search_block_defaults';
    $title = t('Getlocations Search Block settings');
    $desc = t('The settings here will provide the defaults for Getlocations Search Block.');
  }

  // pass on to theme
  $form['varname'] = array('#type' => 'value', '#value' => $varname);

  $form[$varname] = array(
    '#type' => 'fieldset',
    '#title' => $title,
    '#description' => $desc,
    // This will store all the defaults in one variable.
    '#tree' => TRUE,
  );

  $options = array('google_ac' => t('Google Places Autocomplete'), 'text' => t('Textfield'));
  $vocab_list = FALSE;
  if (module_exists('taxonomy')) {
    $options['vocab'] = t('Vocabulary');
    $vocab_list = getlocations_search_get_vocabularies();
  }
  $form[$varname]['method'] = getlocations_element_dd(
    t('Input type'),
    $defaults['method'],
    $options
  );
  $form[$varname]['searchbox_size'] = getlocations_element_map_tf(
    t('Search box size'),
    $defaults['searchbox_size'],
    t('The width of the search box.'),
    5,
    5,
    TRUE
  );

  $form[$varname]['autocomplete_bias'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Viewport bias'),
    '#description' => t('Bias the Google Autocomplete results to the area on the map.'),
    '#default_value' => ($defaults['autocomplete_bias'] ? $defaults['autocomplete_bias'] : 0),
    '#return_value' => 1,
  );

  // country restriction
  $form[$varname]['restrict_by_country'] = getlocations_element_map_checkbox(
    t('Restrict by country'),
    $defaults['restrict_by_country'],
    t('Restrict searches to the country set below. Works with Google Autocomplete.')
  );
  $form[$varname]['restrict_by_country']['#suffix'] = '<div id="getlocations_search_country">';
  $countries = getlocations_get_countries_list();
  $form[$varname]['country'] = getlocations_element_dd(
    t('Search country'),
    $defaults['country'],
    $countries
  );
  $form[$varname]['country']['#suffix'] = '</div>';

  $form[$varname]['use_geolocation_button'] = getlocations_element_map_checkbox(
    t('Provide Browser based geocoding option'),
    $defaults['use_geolocation_button'],
    t('Use the browser to find a location. For gps enabled mobile devices and wireless networks.')
  );

  // taxonomy support
  if ($vocab_list) {
    $form[$varname]['vocab'] = getlocations_element_dd(
      t('Vocabulary'),
      $defaults['vocab'],
      $vocab_list
    );
    $vocab_opts = array('dropdown' => t('Dropdown'), 'autocomplete' => t('Autocomplete'));
    $form[$varname]['vocab_element'] = getlocations_element_dd(
      t('Vocabulary Selection method'),
      $defaults['vocab_element'],
      $vocab_opts
    );
  }

  $form[$varname]['search_distance'] = getlocations_element_search_distance(
    $defaults['search_distance'],
    t('Search distance'),
    t('The distance away from the center to search for locations.')
  );

  //     'search_distance_type' => 'mbr',
  $form[$varname]['search_distance_type'] = getlocations_element_dd(
    t('Proximity Search type'),
    $defaults['search_distance_type'],
    array('mbr' => t('Rectangular'), 'dist' => t('Circular')),
    t('"Rectangular" is faster, "Circular" is more accurate.')
  );

  $form[$varname]['search_units'] = getlocations_element_distance_unit(
    $defaults['search_units']
  );

  // search area shape
  $form[$varname]['search_radshape_enable'] = getlocations_element_map_checkbox(
    t('Enable Show search area'),
    $defaults['search_radshape_enable'],
    t('Show Search area as a rectangle or circle.')
  );
  $form[$varname]['search_radshape_enable']['#suffix'] = '<div id="wrap-getlocations-search-radshape">';

  // jquery_colorpicker
  if (module_exists('jquery_colorpicker') && $getlocations_defaults['jquery_colorpicker_enabled']) {
    $form[$varname]['search_radshape_strokecolor'] = array(
      '#type' => 'jquery_colorpicker',
      '#title' => t('Search area line color'),
      '#default_value' => preg_replace("/^#/", '', $defaults['search_radshape_strokecolor']),
      '#description' => t('Click on the Colorpicker icon to select a color'),
    );
  }
  else {
    $form[$varname]['search_radshape_strokecolor'] = getlocations_element_map_tf(
      t('Search area line color'),
      $defaults['search_radshape_strokecolor'],
      t('HTML hex, eg #FF0000.'),
      10,
      10,
      TRUE
    );
  }

  $form[$varname]['search_radshape_strokeopacity'] = getlocations_element_map_tf(
    t('Search area line opacity'),
    $defaults['search_radshape_strokeopacity'],
    t('Must be between 0 and 1.'),
    10,
    10,
    TRUE
  );
  $form[$varname]['search_radshape_strokeweight'] = getlocations_element_map_tf(
    t('Search area line thickness'),
    $defaults['search_radshape_strokeweight'],
    t('Must be an integer.'),
    10,
    10,
    TRUE
  );

  // jquery_colorpicker
  if (module_exists('jquery_colorpicker') && $getlocations_defaults['jquery_colorpicker_enabled']) {
    $form[$varname]['search_radshape_fillcolor'] = array(
      '#type' => 'jquery_colorpicker',
      '#title' => t('Search area fill color'),
      '#default_value' => preg_replace("/^#/", '', $defaults['search_radshape_fillcolor']),
      '#description' => t('Click on the Colorpicker icon to select a color'),
    );
  }
  else {
    $form[$varname]['search_radshape_fillcolor'] = getlocations_element_map_tf(
      t('Search area fill color'),
      $defaults['search_radshape_fillcolor'],
      t('HTML hex, eg #FF0000.'),
      10,
      10,
      TRUE
    );
  }

  $form[$varname]['search_radshape_fillopacity'] = getlocations_element_map_tf(
    t('Search area fill opacity'),
    $defaults['search_radshape_fillopacity'],
    t('Must be between 0 and 1.'),
    10,
    10,
    TRUE
  );
  $form[$varname]['search_radshape_toggle'] = getlocations_element_map_checkbox(
    t('Enable Search area toggle button'),
    $defaults['search_radshape_toggle'],
    t('Show a button to switch visibility on or off.')
  );
  $form[$varname]['search_radshape_toggle_active'] = getlocations_element_map_checkbox(
    t('Initial state of Search area'),
    $defaults['search_radshape_toggle_active'],
    t('Set initial visibility on.')
  );
  $form[$varname]['search_radshape_toggle_active']['#suffix'] = '</div>';

  // are there any modules providing locations?
  if (getlocations_search_do_types()) {

    $form[$varname]['search_limits'] = getlocations_element_map_limits(
      $defaults['search_limits']
    );

    $opts = array('all' => t('Show All'), 'node' => t('Nodes'));
    $opts['user'] = t('Users');
    if (module_exists('taxonomy')) {
      $opts['term'] = t('Terms');
    }
    if (module_exists('comment')) {
      $opts['comment'] = t('Comments');
    }
    $form[$varname]['search_type'] = getlocations_element_dd(
      t('Restrict the search'),
      $defaults['search_type'],
      $opts,
      t('The default for the type of content location.')
    );
  }
  else {
    $form[$varname]['search_limits'] = array(
      '#type' => 'value',
      '#value' => 0,
    );
    $form[$varname]['search_type'] = array(
      '#type' => 'value',
      '#value' => 'all',
    );
  }

  $form[$varname]['display_search_distance'] = getlocations_element_map_checkbox(
    t('Display Search distance box'),
    $defaults['display_search_distance'],
    t('Allow users to modify the search distance.')
  );
  $form[$varname]['display_search_units'] = getlocations_element_map_checkbox(
    t('Display Search units dropdown'),
    $defaults['display_search_units'],
    t('Allow users to modify the search units.')
  );

  if (getlocations_search_do_types()) {
    $form[$varname]['display_search_limits'] = getlocations_element_map_checkbox(
      t('Display Search limits dropdown'),
      $defaults['display_search_limits'],
      t('Allow users to modify the search limits.')
    );

    $form[$varname]['display_search_type'] = getlocations_element_map_checkbox(
      t('Display Search type dropdown'),
      $defaults['display_search_type'],
      t('Allow users to modify the search type.')
    );
  }
  else {
    $form[$varname]['display_search_limits'] =  array(
      '#type' => 'value',
      '#value' => 0,
    );
    $form[$varname]['display_search_type'] = array(
      '#type' => 'value',
      '#value' => 0,
    );
  }
  $form[$varname]['display_latlon'] = getlocations_element_map_checkbox(
    t('Show Latitude/Longitude'),
    $defaults['display_latlon'],
    ''
  );
  $form[$varname]['display_dms'] = getlocations_element_map_checkbox(
    t('Show Latitude/Longitude in Degrees, minutes, seconds'),
    $defaults['display_dms'],
    ''
  );

  $form[$varname]['display_geo_microformat'] = getlocations_element_dd(
    t('Show Latitude/Longitude in accordance with Geo Microformat or Microdata markup'),
    $defaults['display_geo_microformat'],
    array( 0 => t('None'), 1 => t('Microformat'), 2 => t('Microdata')),
    t('See the <a href="@a" target="_blank">Microformats wiki</a> or <a href="@b" target="_blank">Microdata standards</a> for more information', array('@a' => url('http://microformats.org/wiki/geo'), '@b' => url('http://www.w3.org/TR/microdata/')))
  );

  $form[$varname]['display_accuracy'] = getlocations_element_map_checkbox(
    t('Show accuracy results'),
    $defaults['display_accuracy'],
    ''
  );
  $form[$varname]['show_distance'] = getlocations_element_map_checkbox(
    t('Show Distance in InfoBubble/InfoWindow'),
    $defaults['show_distance'],
    ''
  );
  $form[$varname]['do_search_marker'] = getlocations_element_map_checkbox(
    t('Mark the search center on the map'),
    $defaults['do_search_marker'],
    ''
  );
  $markers = getlocations_get_marker_titles();
  $form[$varname]['search_marker'] = getlocations_element_map_marker(
    t('Search Map marker'),
    $markers,
    $defaults['search_marker'],
    ''
  );

  $form[$varname]['search_marker_toggle'] = getlocations_element_map_checkbox(
    t('Enable Search Marker toggle button'),
    $defaults['search_marker_toggle'],
    t('Show a button to switch visibility on or off.')
  );
  $form[$varname]['search_marker_toggle_active'] = getlocations_element_map_checkbox(
    t('Initial state of Search Marker'),
    $defaults['search_marker_toggle_active'],
    t('Set initial visibility on.')
  );

  $form[$varname]['showall'] = getlocations_element_map_checkbox(
    t('Show all markers'),
    $defaults['showall'],
    t('Show all the available locations on the map.')
  );

  $form[$varname]['geocode_button_enable'] = getlocations_element_map_checkbox(
    t('Enable Geocode button'),
    $defaults['geocode_button_enable'],
    t('Works with Google Autocomplete.')
  );
  $form[$varname]['reset_button_enable'] = getlocations_element_map_checkbox(
    t('Enable Reset button'),
    $defaults['reset_button_enable']
  );

  $form[$varname] += getlocations_map_display_basics_form($defaults);

  $form[$varname] += getlocations_map_display_options_form($defaults, FALSE, TRUE, 'getlocations_search');

  $form[$varname]['markeractiontype'] = getlocations_element_map_markeractiontype(
    $defaults['markeractiontype']
  );
  $form[$varname]['markeraction'] = getlocations_element_map_markeraction(
    $defaults['markeraction']
  );

  if (module_exists('getdirections')) {
    $form[$varname]['getdirections_link'] = getlocations_element_map_checkbox(
      t('Link to Getdirections in bubble'),
      $defaults['getdirections_link'],
      t('Include a link to the Getdirections page in InfoBubble/InfoWindow.')
    );
  }

  $form[$varname]['zoom_on_single_use'] = getlocations_element_map_checkbox(
    t('Apply Default Zoom for Single location'),
    $defaults['zoom_on_single_use'],
    t('Apply a Default zoom level for a single marker.')
  );
  $form[$varname]['zoom_on_single_use']['#suffix'] = '<div id="wrap-zoom-on-single-use">';
  $form[$varname]['nodezoom'] = getlocations_element_map_zoom(
    t('Default Zoom for Single location'),
    $defaults['nodezoom'],
    t('The Default zoom level for a single marker.')
  );
  $form[$varname]['nodezoom']['#suffix'] = '</div>';

  // marker managers
  $form[$varname]['markermanagertype'] = getlocations_element_markermanagertype($defaults['markermanagertype']);

  // markermanager
  $form[$varname] += getlocations_markermanager_form($defaults);

  // markerclusterer
  $form[$varname] += getlocations_markercluster_form($defaults);

  return $form;

}

function getlocations_search_settings_validate($form, &$form_state) {
  // jquery_colorpicker munge
  if (isset($form_state['values']['getlocations_search_defaults'])) {
    if (! preg_match("/^#/", $form_state['values']['getlocations_search_defaults']['search_radshape_strokecolor'])) {
      $form_state['values']['getlocations_search_defaults']['search_radshape_strokecolor'] = '#' . $form_state['values']['getlocations_search_defaults']['search_radshape_strokecolor'];
    }
    if (! preg_match("/^#/", $form_state['values']['getlocations_search_defaults']['search_radshape_fillcolor'])) {
      $form_state['values']['getlocations_search_defaults']['search_radshape_fillcolor'] = '#' . $form_state['values']['getlocations_search_defaults']['search_radshape_fillcolor'];
    }

    if ($latlon = getlocations_latlon_check($form_state['values']['getlocations_search_defaults']['latlong'])) {
      $form_state['values']['getlocations_search_defaults']['latlong'] = $latlon;
    }
    else {
      form_set_error('getlocations_search_defaults][latlong', t('Map coordinates must be expressed as a decimal latitude and longitude, separated by a comma.'));
    }
    // css check
    if (isset($form_state['values']['getlocations_search_defaults']['width'])) {
      if ($check = getlocations_dim_check($form_state['values']['getlocations_search_defaults']['width'])) {
        $form_state['values']['getlocations_search_defaults']['width'] = $check;
      }
      else {
        form_set_error('getlocations_search_defaults][width', t('Width must be valid css'));
      }
    }
    if (isset($form_state['values']['getlocations_search_defaults']['height'])) {
      if ($check = getlocations_dim_check($form_state['values']['getlocations_search_defaults']['height'])) {
        $form_state['values']['getlocations_search_defaults']['height'] = $check;
      }
      else {
        form_set_error('getlocations_search_defaults][height', t('Height must be valid css'));
      }
    }

  }
  elseif (isset($form_state['values']['getlocations_search_block_defaults'])) {
    if (! preg_match("/^#/", $form_state['values']['getlocations_search_block_defaults']['search_radshape_strokecolor'])) {
      $form_state['values']['getlocations_search_block_defaults']['search_radshape_strokecolor'] = '#' . $form_state['values']['getlocations_search_block_defaults']['search_radshape_strokecolor'];
    }
    if (! preg_match("/^#/", $form_state['values']['getlocations_search_block_defaults']['search_radshape_fillcolor'])) {
      $form_state['values']['getlocations_search_block_defaults']['search_radshape_fillcolor'] = '#' . $form_state['values']['getlocations_search_block_defaults']['search_radshape_fillcolor'];
    }

    if ($latlon = getlocations_latlon_check($form_state['values']['getlocations_search_block_defaults']['latlong'])) {
      $form_state['values']['getlocations_search_block_defaults']['latlong'] = $latlon;
    }
    else {
      form_set_error('getlocations_search_block_defaults][latlong', t('Map coordinates must be expressed as a decimal latitude and longitude, separated by a comma.'));
    }
    // css check
    if (isset($form_state['values']['getlocations_search_block_defaults']['width'])) {
      if ($check = getlocations_dim_check($form_state['values']['getlocations_search_block_defaults']['width'])) {
        $form_state['values']['getlocations_search_block_defaults']['width'] = $check;
      }
      else {
        form_set_error('getlocations_search_block_defaults][width', t('Width must be valid css'));
      }
    }
    if (isset($form_state['values']['getlocations_search_block_defaults']['height'])) {
      if ($check = getlocations_dim_check($form_state['values']['getlocations_search_block_defaults']['height'])) {
        $form_state['values']['getlocations_search_block_defaults']['height'] = $check;
      }
      else {
        form_set_error('getlocations_search_block_defaults][height', t('Height must be valid css'));
      }
    }
  }

  $reset = $form_state['values']['getlocations_search_paths']['reset'];
  unset($form_state['values']['getlocations_search_paths']['reset']);
  if ($reset == 1) {
    $form_state['values']['getlocations_search_paths'] = getlocations_search_paths_get(TRUE);
  }
  elseif ($reset == 2) {
    $form_state['values']['getlocations_search_paths'] = getlocations_search_paths_get(FALSE, TRUE);
  }

}
