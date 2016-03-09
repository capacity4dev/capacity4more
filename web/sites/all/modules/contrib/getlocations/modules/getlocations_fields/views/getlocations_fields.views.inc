<?php

/**
 * @file
 * getlocations_fields.views.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Views 3 support for getlocations_fields.
 */

/**
 * Implements hook_views_data().
 */
function getlocations_fields_views_data() {

  // ----------------------------------------------------------------
  // getlocations_fields table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.

  $data['getlocations_fields']['table']['group'] = t('Getlocations Fields');

  // Advertise this table as a possible base table
  $data['getlocations_fields']['table']['base'] = array(
    'field' => 'glid',
    'title' => t('Getlocations'),
    'help' => t('Locations are addresses and map coordinates.'),
    'weight' => -10,
  );

  $data['getlocations_fields']['table']['join'] = array(
    // getlocations_fields links to node through getlocations_fields_entities via glid.
    'node' => array(
      'left_table' => 'getlocations_fields_entities',
      'left_field' => 'glid',
      'field' => 'glid',
    ),
    // getlocations_fields links to node_revision through getlocations_fields_entities via glid.
    'node_revision' => array(
      'left_table' => 'getlocations_fields_entities',
      'left_field' => 'glid',
      'field' => 'glid',
    ),
    // getlocations_fields links to users through getlocations_fields_entities via glid.
    'users' => array(
      'left_table' => 'getlocations_fields_entities',
      'left_field' => 'glid',
      'field' => 'glid',
    ),
    // getlocations_fields links to taxonomy terms through getlocations_fields_entities via glid.
    'taxonomy_term_data' => array(
      'left_table' => 'getlocations_fields_entities',
      'left_field' => 'glid',
      'field' => 'glid',
    ),
    // getlocations_fields links to comment through getlocations_fields_entities via glid.
    'comment' => array(
      'left_table' => 'getlocations_fields_entities',
      'left_field' => 'glid',
      'field' => 'glid',
    ),

  );

  // ----------------------------------------------------------------
  // getlocations_fields table -- fields


  // glid
  $data['getlocations_fields']['glid'] = array(
    'title' => t('Glid'),
    'help' => t('The getlocations ID of the location.'), // The help that appears on the UI,
    // Information for displaying the glid
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    // Information for accepting a glid as an argument. Also supports 1+2+3 for OR or 1,2,3 for AND
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_glid',
    ),
    // Information for accepting a glid as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
    ),
    // Information for sorting on a glid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // name
  $data['getlocations_fields']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // street
  $data['getlocations_fields']['street'] = array(
    'title' => t('Street'),
    'help' => t('The street address of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // additional
  $data['getlocations_fields']['additional'] = array(
    'title' => t('Additional'),
    'help' => t('The additional address of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // city
  $data['getlocations_fields']['city'] = array(
    'title' => t('City'),
    'help' => t('The city of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_city',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // province
  $data['getlocations_fields']['province'] = array(
    'title' => t('Province'),
    'help' => t('The province of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_province',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // postal_code
  $data['getlocations_fields']['postal_code'] = array(
    'title' => t('Postal Code'),
    'help' => t('The postal code of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_postcode',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // country
  $data['getlocations_fields']['country'] = array(
    'title' => t('Country'),
    'help' => t('The country of the selected location.'),
    'field' => array(
      'handler' => 'getlocations_fields_handler_field_country',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_country',
    ),
    'filter' => array(
      'handler' => 'getlocations_fields_handler_filter_country',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
      // TODO: needs handler to sort by name, not code
    ),
  );

  // latitude
  $data['getlocations_fields']['latitude'] = array(
    'title' => t('Latitude'),
    'help' => t('The latitude of the selected location.'),
    'field' => array(
      'handler' => 'getlocations_fields_handler_field_latitude',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // longitude
  $data['getlocations_fields']['longitude'] = array(
    'title' => t('Longitude'),
    'help' => t('The longitude of the selected location.'),
    'field' => array(
      'handler' => 'getlocations_fields_handler_field_longitude',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // coordinates
  $data['getlocations_fields']['coordinates'] = array(
    'title' => t('Coordinates'),
    'help' => t("The coordinates of the selected location in 'lat,long' format."),
    'field' => array(
      'field' => 'latitude', // The handler adds the longitude.
      'handler' => 'getlocations_fields_handler_field_coordinates',
      'click sortable' => FALSE,
    ),
  );
  // wkt
  $data['getlocations_fields']['wkt'] = array(
    'title' => t('Wkt'),
    'help' => t("The coordinates of the selected location in WKT format."),
    'field' => array(
      'field' => 'latitude', // The handler adds the longitude.
      'handler' => 'getlocations_fields_handler_field_wkt',
      'click sortable' => FALSE,
    ),
  );
  // bbox
  $data['getlocations_fields']['bbox'] = array(
    'title' => t('Bounding box'),
    'help' => t('Filter locations within a bounding box.'),
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_bbox',
    ),
  );
  // distance
  $data['getlocations_fields']['distance'] = array(
    'title' => t('Distance'),
    'help' => t("The distance from the selected location and either the current user or a specific location."),
    'field' => array(
      'handler' => 'getlocations_fields_handler_field_distance',
    ),
    'sort' => array(
      'handler' => 'getlocations_fields_handler_sort_distance',
    ),
    'argument' => array(
      'handler' => 'getlocations_fields_handler_argument_distance',
    ),
    'filter' => array(
      'handler' => 'getlocations_fields_handler_filter_distance',
    ),
//    'relationship' => array(
//      'handler' => 'getlocations_fields_handler_relationship_distance',
//    ),
  );

  // marker
  $data['getlocations_fields']['marker'] = array(
    'title' => t('Marker'),
    'help' => t('The marker of the selected location.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // data
  $data['getlocations_fields']['data'] = array(
    'title' => t('Data'),
    'help' => t('Serialized data of the selected location.'),
    'field' => array(
      'handler' => 'getlocations_fields_handler_field_data',
    ),
    #'filter' => array(
    #  'handler' => 'getlocations_fields_handler_filter_data',
    #),

  );

/*
  // address
  $data['getlocations_fields']['address'] = array(
    'title' => t('Address'),
    'help' => t('The entire address block for the location.'),
    'field' => array(
      'field' => 'glid',
#      'handler' => 'getlocations_fields_handler_field_address',
      'element type' => 'div',
    ),
  );
 */
  // ----------------------------------------------------------------
  // END getlocations_fields table -- fields


  // getlocations_fields_entities table links node, users, taxonomy_term_data and comment to location data in getlocations_fields
  $data['getlocations_fields_entities']['table']['group']  = t('Getlocations Fields');

  $data['getlocations_fields_entities']['table']['join'] = array(
    'getlocations_fields' => array(
      'left_field' => 'glid',
      'field' => 'glid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
    'node_revision' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
    'taxonomy_term_data' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
    'comment' => array(
      'left_field' => 'cid',
      'field' => 'cid',
    ),
  );
  // entity field name
  $data['getlocations_fields_entities']['field_name'] = array(
    'title' => t('Field name'),
    'help' => t('The field name used in the Content type definition.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // node id
  $data['getlocations_fields_entities']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('The Node Identifier.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric'
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'label' => 'content',
      'help' => t('Bring in the node data.'),
    ),
  );
  // user id
  $data['getlocations_fields_entities']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('The User Identifier.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'label' => 'user',
      'help' => t('Bring in the user data.'),
    ),
  );
  // term id
  $data['getlocations_fields_entities']['tid'] = array(
    'title' => t('Taxonomy Term ID'),
    'help' => t('The Taxonomy Term Identifier.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'taxonomy_index',
      'field' => 'tid',
      'label' => 'term',
      'help' => t('Bring in the taxonomy data.'),
    ),
  );
  // comment id
  $data['getlocations_fields_entities']['cid'] = array(
    'title' => t('Comment ID'),
    'help' => t('The Comment Identifier.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'comment',
      'field' => 'cid',
      'label' => 'comment',
      'help' => t('Bring in the comment data.'),
    ),
  );

  // Tell the base tables about us.
  $data['node']['table']['join']['getlocations_fields'] = array(
    'left_table' => 'getlocations_fields_entities',
    'left_field' => 'nid',
    'field' => 'nid',
  );
  $data['node_revision']['table']['join']['getlocations_fields'] = array(
    'left_table' => 'getlocations_fields_entities',
    'left_field' => 'vid',
    'field' => 'vid',
  );
  $data['users']['table']['join']['getlocations_fields'] = array(
    'left_table' => 'getlocations_fields_entities',
    'left_field' => 'uid',
    'field' => 'uid',
  );
  $data['taxonomy_term_data']['table']['join']['getlocations_fields'] = array(
    'left_table' => 'getlocations_fields_entities',
    'left_field' => 'tid',
    'field' => 'tid',
  );
  $data['comment']['table']['join']['getlocations_fields'] = array(
    'left_table' => 'getlocations_fields_entities',
    'left_field' => 'cid',
    'field' => 'cid',
  );

  return $data;

}

/**
 * Helper function for proximity handlers.
 * Retrieves the coordinates of the location that this field measures distances against.
 *
 * @param $view
 *   The view object.
 * @param $options
 *   An array of the options (or values in the case of the filter) of the handler.
 *
 * @return
 *   An array with keys 'latitude' and 'longitude' or an empty array.
 */
function getlocations_fields_views_proximity_get_reference_location($view, $options) {
  $coordinates = array();
  switch ($options['origin']) {
    case 'user':
    case 'hybrid':
      global $user;
      $user_locations = getlocations_load_locations($user->uid, 'uid');
      if (isset($user_locations[0]['latitude']) || !empty($user_locations[0]['latitude'])) {
        $coordinates['latitude'] = (float) $user_locations[0]['latitude'];
        $coordinates['longitude'] = (float) $user_locations[0]['longitude'];
      }
      elseif ($options['origin'] == 'hybrid') {
        $coordinates['latitude'] = (isset($options['latitude']) ? (float) $options['latitude'] : 0);
        $coordinates['longitude'] = (isset($options['longitude']) ? (float) $options['longitude'] : 0);
      }
      break;

    case 'static':
      $coordinates['latitude'] = (isset($options['latitude']) ? (float) $options['latitude'] : 0);
      $coordinates['longitude'] = (isset($options['longitude']) ? (float) $options['longitude'] : 0);
      break;

    case 'search':
      $coordinates['latitude'] = (isset($options['latitude']) ? (float) $options['latitude'] : 0);
      $coordinates['longitude'] = (isset($options['longitude']) ? (float) $options['longitude'] : 0);
      break;

    case 'php':
      ob_start();
      $result = eval($options['php_code']);
      ob_end_clean();
      if ($result && isset($result['latitude']) && $result['latitude'] && isset($result['longitude']) && $result['longitude']) {
        $coordinates['latitude'] = (float) $result['latitude'];
        $coordinates['longitude'] = (float) $result['longitude'];
      }
      break;

    case 'nid_arg':
      if ($nodehandler = $view->display_handler->get_handler('argument', $options['nid_arg'])) {
        $nid = $nodehandler->get_value();
        if ($nid && is_numeric($nid)) {
          $tempobj = node_load($nid);
          $field_name = $options['nid_loc_field'];
        }
      }
      break;

    case 'uid_arg':
      if ($userhandler = $view->display_handler->get_handler('argument', $options['uid_arg'])) {
        $uid = $userhandler->get_value();
        if ($uid && is_numeric($uid)) {
          $tempobj = user_load($uid);
          $field_name = $options['uid_loc_field'];
        }
      }
      break;

    case 'tid_arg':
      if ($termhandler = $view->display_handler->get_handler('argument', $options['tid_arg'])) {
        $tid = $termhandler->get_value();
        if ($tid && is_numeric($tid)) {
          $tempobj = taxonomy_term_load($tid);
          $field_name = $options['tid_loc_field'];
        }
      }
      break;

    case 'cid_arg':
      // not tested
      if ($commenthandler = $view->display_handler->get_handler('argument', $options['cid_arg'])) {
        $cid = $commenthandler->get_value();
        if ($cid && is_numeric($cid)) {
          $tempobj = comment_load($cid);
          $field_name = $options['cid_loc_field'];
        }
      }
      break;

    // used by sort when argument is lat/lon
    case 'distance_arg':
      $coordinates = array();
      foreach ($view->argument as $argument) {
        if (isset($argument->field) && $argument->field == 'distance') {
          $a = explode('_', $view->args[$argument->position]);
          if (count($a) == 2) {
            $aa = explode(',', $a[0]);
              if (count($aa) == 2 && is_numeric($aa[0]) && is_numeric($aa[1])) {
              $lat = $aa[0];
              $lon = $aa[1];
            }
          }
          break;
        }
      }
      if (isset($lat)) {
        $coordinates['latitude'] = (float) $lat;
        $coordinates['longitude'] = (float) $lon;
      }
      break;
  } // end switch

  if (isset($tempobj) && $tempobj && isset($field_name) && $field_name) {
    if (isset($tempobj->{$field_name})) {
      if (! isset($tempobj->language)) {
        $lang = 'und';
      }
      else {
        $lang = $tempobj->language;
        if (! isset($tempobj->{$field_name}[$lang])) {
          $lang = 'und';
        }
      }
      $location = $tempobj->{$field_name};
      if (isset($location[$lang][0]['latitude']) && isset($location[$lang][0]['longitude'])) {
        $coordinates['latitude'] = (float) $location[$lang][0]['latitude'];
        $coordinates['longitude'] = (float) $location[$lang][0]['longitude'];
      }
    }
  }

  return $coordinates;
}

function getlocations_fields_views_proximity_get_argument_options($view) {
  // Get the arguments for this view so we can use nid, uid or Global: Null arguments.
  $uid_argument_options = array();
  $nid_argument_options = array();
  $tid_argument_options = array();
  $cid_argument_options = array();
  $arguments = $view->display_handler->get_handlers('argument');

  foreach ($arguments as $id => $handler) {
    if ($handler->field == 'null') {
      $uid_argument_options[$id] = $handler->ui_name();
      $nid_argument_options[$id] = $handler->ui_name();
      $tid_argument_options[$id] = $handler->ui_name();
    }
    elseif ($handler->field == 'nid') {
      $nid_argument_options[$id] = $handler->ui_name();
    }
    elseif ($handler->field == 'uid') {
      $uid_argument_options[$id] = $handler->ui_name();
    }
    elseif ($handler->field == 'tid') {
      $tid_argument_options[$id] = $handler->ui_name();
    }
    elseif ($handler->field == 'cid') {
      $cid_argument_options[$id] = $handler->ui_name();
    }
  }
  return array($nid_argument_options, $uid_argument_options, $tid_argument_options, $cid_argument_options);

}

function getlocations_fields_views_proximity_get_location_field_options() {
  $field_options = array();

  $fields = field_info_fields();
  foreach ($fields as $field) {
    if ($field['module'] == 'getlocations_fields') {
      $field_options[$field['field_name']] = t('Getlocations: @name', array('@name' => $field['field_name']));
    }
  }

  return $field_options;
}

/**
 * Implements hook_field_views_data().
 *
 * Views integration for getlocations_fields.
 *
 */
#function getlocations_fields_field_views_data($field) {
#  $data = field_views_field_default_views_data($field);
#  return $data;
#}

/**
 * Implements hook_views_plugins().
 */
function getlocations_fields_views_plugins() {

  return array(
    'module' => 'getlocations_fields',
    'style' => array(
      'getlocations_fields_streetview' => array(
        'title' => t('GetLocations Fields Streetview'),
        'help' => t('Displays a location in Streetview.'),
        'handler' => 'getlocations_fields_plugin_style_streetview',
        'theme' => 'getlocations_fields_view_streetview',
        'theme path' => GETLOCATIONS_FIELDS_PATH . '/views',
        'uses row plugin' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'argument default' => array(
      'querystring' => array(
        'title' => t('Bounding box from query string'),
        'handler' => 'getlocations_fields_plugin_argument_default_bboxquery',
      ),
    ),
  );
}

/**
 * Preprocess function for getlocations_fields_view_streetview.tpl.
 * getlocations_fields module only
 */
function template_preprocess_getlocations_fields_view_streetview(&$variables) {
  global $language;

  // just in case
  if (! getlocations_fields_streetview_settings_allow()) {
    $variables['mapid'] = FALSE;
    return;
  }

  $locations = $variables['view']->style_plugin->rendered_fields;
  $options = $variables['view']->style_plugin->options;
  $latlons = array();
  if (count($locations) == 1) {
    $location = $locations[0];

    $lid = 0;
    if (isset($location['glid']) && $location['glid'] > 0 && isset($location['latitude']) && isset($location['longitude'])) {
      $lid = $location['glid'];
    }

    if ($lid > 0) {
      // dump bummers with no lat/lon
      if ($latlon = getlocations_latlon_check($location['latitude'] . ',' . $location['longitude'])) {
        $ll = explode(',', $latlon);
        $location['latitude'] = $ll[0];
        $location['longitude'] = $ll[1];

        // get defaults
        $dvals = getlocations_fields_data_keys('d');
        $options['sv_heading'] = (isset($location['data'])   && is_numeric($location['data'])   ? $location['data']   : $dvals['sv_heading']);
        $options['sv_zoom']    = (isset($location['data_1']) && is_numeric($location['data_1']) ? $location['data_1'] : $dvals['sv_zoom']);
        $options['sv_pitch']   = (isset($location['data_2']) && is_numeric($location['data_2']) ? $location['data_2'] : $dvals['sv_pitch']);
        $options['sv_enable']  = (isset($location['data_3']) && is_numeric($location['data_3']) ? $location['data_3'] : $dvals['sv_enable']);

        $getlocations_defaults = getlocations_defaults();
        $newdefaults = getlocations_adjust_vars($getlocations_defaults, $options);
        $mapid = getlocations_setup_map($newdefaults, FALSE, TRUE);
        $options['latitude'] = $location['latitude'];
        $options['longitude'] = $location['longitude'];

        getlocations_fields_streetview_js_settings_do($options, $mapid);
        $variables['mapid'] = $mapid;
        $variables['width'] = $options['width'];
        $variables['height'] = $options['height'];
      }
    }
  }
}

function getlocations_fields_streetview_js_settings_do($defaults, $mapid) {

  $settings = array(
    $mapid => array(
      'width'                     => $defaults['width'],
      'height'                    => $defaults['height'],
      'sv_addresscontrol'         => $defaults['sv_addresscontrol'],
      'sv_addresscontrolposition' => $defaults['sv_addresscontrolposition'],
      'sv_pancontrol'             => $defaults['sv_pancontrol'],
      'sv_pancontrolposition'     => $defaults['sv_pancontrolposition'],
      'sv_zoomcontrol'            => $defaults['sv_zoomcontrol'],
      'sv_zoomcontrolposition'    => $defaults['sv_zoomcontrolposition'],
      'sv_linkscontrol'           => $defaults['sv_linkscontrol'],
      'sv_imagedatecontrol'       => $defaults['sv_imagedatecontrol'],
      'sv_scrollwheel'            => $defaults['sv_scrollwheel'],
      'sv_clicktogo'              => $defaults['sv_clicktogo'],
      'latitude'                  => $defaults['latitude'],
      'longitude'                 => $defaults['longitude'],
      'sv_heading'                => $defaults['sv_heading'],
      'sv_zoom'                   => $defaults['sv_zoom'],
      'sv_pitch'                  => $defaults['sv_pitch'],
      'sv_enable'                 => $defaults['sv_enable'],
      'js_path'                   => base_path() . GETLOCATIONS_PATH . '/js/',
      'sv_fullscreen'             => $defaults['sv_fullscreen'],
    ),
  );

  drupal_add_js(array('getlocations_fields_streetview' => $settings), 'setting');

}

/**
 * Implements hook_views_pre_render().
 *
 * This hook is called right before the render process. The query has been
 * executed, and the pre_render() phase has already happened for handlers, so
 * all data should be available.
 *
 * Adding output to the view can be accomplished by placing text on
 * $view->attachment_before and $view->attachment_after. Altering the content
 * can be achieved by editing the items of $view->result.
 *
 * This hook can be utilized by themes.
 * @param $view
 *   The view object about to be processed.
 */
function getlocations_fields_views_pre_render(&$view) {

  // look for the right view, machine name must end in getlocations_streetview
  if (preg_match('/getlocations_streetview$/i', $view->name)) {
    // streetview killswitch
    if (getlocations_fields_streetview_settings_allow()) {
      if (count($view->result) == 1) {
        if (isset($view->result[0]->getlocations_fields_data)) {
          // OK, now get the data, unserialize and get sv_enable
          $value = unserialize($view->result[0]->getlocations_fields_data);
          $enable = (isset($value['data']['sv_enable']) ? $value['data']['sv_enable'] : 1);
          if (! $enable) {
            // scrub the result
            unset($view->result[0]);
          }
        }
      }
      else {
        // scrub the result
        $c = count($view->result);
        for ($i = 0; $i < $c; $i++) {
          unset($view->result[$i]);
        }
      }
    }
    else {
      // scrub the result
      $c = count($view->result);
      for ($i = 0; $i < $c; $i++) {
        unset($view->result[$i]);
      }
    }
  }
}
