<?php

/**
 * @file
 * getlocations_leaflet.views.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Getlocations Leaflet maps views integration.
 */

/**
 * Define leaflet views style.
 *
 * Implements hook_views_plugins().
 */
function getlocations_leaflet_views_plugins() {
  $plugins = array(
    'module' => 'getlocations_leaflet',
    'style' => array(
      'getlocations_leaflet' => array(
        'title' => t('Getlocations Leaflet Map'),
        'help' => t('Displays a View as a Getlocations Leaflet map.'),
        'path' => GETLOCATIONS_LEAFLET_PATH,
        'handler' => 'getlocations_leaflet_plugin_style',
        'theme' => 'getlocations_leaflet_view_map',
        'theme path' => GETLOCATIONS_LEAFLET_PATH . '/views',
        'uses row plugin' => FALSE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
        'uses fields' => TRUE,
      ),
    ),
  );

  return $plugins;
}

/**
 * Preprocess function for getlocations_leaflet_view_map.tpl
 */
function template_preprocess_getlocations_leaflet_view_map(&$variables) {
  global $language;

  $locations = $variables['view']->style_plugin->rendered_fields;
  $options = $variables['view']->style_plugin->options;
  $base_field = $variables['view']->style_plugin->view->base_field;
  $thiskey = FALSE;
  $latlons = array();
  $minmaxes = array('minlat' => 0, 'minlon' => 0, 'maxlat' => 0, 'maxlon' => 0);
  $iconlist = array();
  $cat = FALSE;
  $cats = array();
  $ct = 0;
  $entity_type = 'node';
  if ($base_field == 'uid') {
    $entity_type = 'user';
  }
  elseif ($base_field == 'tid') {
    $entity_type = 'taxonomy_term';
  }
  elseif ($base_field == 'cid') {
    $entity_type = 'comment';
  }

  if ($options['custom_content_enable'] and !empty($options['custom_content_source'])) {
    $custom_content_source = $options['custom_content_source'];
  }
  else {
    $custom_content_source = NULL;
  }

  $map_settings = getlocations_leaflet_map_get_info('Getlocations OSM');
  $map_settings = getlocations_leaflet_get_map_layers($map_settings);
  // show_search_distance
  if (
    isset($variables['view']->exposed_data['distance'])
    && isset($variables['view']->exposed_data['distance']['latitude'])
    && $variables['view']->exposed_data['distance']['latitude']
    && isset($variables['view']->exposed_data['distance']['longitude'])
    && $variables['view']->exposed_data['distance']['longitude']
    && $variables['view']->exposed_data['distance']['search_distance']
  ) {
    $map_settings['search_dist_info'] = $variables['view']->exposed_data['distance'];
  }

  if (count($locations)) {
    $cats = array();
    // we should loop over them and dump bummers with no lat/lon
    foreach ($locations AS $key => $location) {

      $custom_content = $custom_content_source ? $location[$custom_content_source] : '';
      $lid = 0;
      if (module_exists('getlocations_fields') && isset($location['glid']) && $location['glid'] > 0) {
        $lid = $location['glid'];
      }
      elseif (module_exists('location') && isset($location['lid']) && $location['lid'] > 0) {
        $lid = $location['lid'];
        if (isset($location['type'])) {
          $location['field_name'] = getlocations_get_fieldname($location['type'], $entity_type);
        }
      }
      elseif (module_exists('geofield') && isset($location[$base_field]) && $location[$base_field] > 0 ) {
        $lid = $location[$base_field];
        $location['field_name'] = getlocations_get_fieldname($location['type'], $entity_type);
        $location['latitude'] = $location[$location['field_name']];
        $location['longitude'] = $location[$location['field_name'] . '_1'];
      }
      elseif (module_exists('geolocation') && isset($location[$base_field]) && $location[$base_field] > 0 ) {
        $lid = $location[$base_field];
        $location['field_name'] = getlocations_get_fieldname($location['type'], $entity_type);
        $location['latitude'] = $location[$location['field_name']];
        $location['longitude'] = $location[$location['field_name'] . '_1'];
      }
      if ($lid > 0) {

        $marker = '';
        $vector = '';
        // awesome
        if ($options['awesome'] && $options['marker_type'] == 'fa') {
          if ($entity_type == 'node') {
            $per_field_markers = FALSE;
            $getlocations_node_marker = variable_get('getlocations_node_marker', array('enable' => 0));
            if ($getlocations_node_marker['enable']) {
              if (isset($location['type']) && isset($location['field_name'])) {
                $mkey = 'node_marker__' . drupal_strtolower($location['type']) . '__' . $location['field_name'];
                $vicon = getlocations_leaflet_awesome_marker_get($options, $mkey);
                $per_field_markers = TRUE;
              }
            }
            if (! $per_field_markers) {
              $vicon = getlocations_leaflet_awesome_marker_get($options, 'node');
            }
            // TODO per tid marker
          }
          elseif ($entity_type == 'taxonomy_term') {
            $vicon = getlocations_leaflet_awesome_marker_get($options, 'vocabulary');
          }
          elseif ($entity_type == 'user') {
            $vicon = getlocations_leaflet_awesome_marker_get($options, 'user');
          }
          elseif ($entity_type == 'comment') {
            $vicon = getlocations_leaflet_awesome_marker_get($options, 'comment');
          }
          else {
            $vicon = getlocations_leaflet_awesome_marker_get($options);
          }
          $vector = $vicon;
        }
        else {
          if ($entity_type == 'node') {
            $marker = $options['node_map_marker'];
            if (isset($location['type']) && isset($location['field_name']) ) {
              if (isset($options['node_marker__' . drupal_strtolower($location['type']) . '__' . $location['field_name']])) {
                $marker = $options['node_marker__' . drupal_strtolower($location['type']) . '__' . $location['field_name']];
              }
            }
            // term marker
            $getlocations_term_marker = variable_get('getlocations_term_marker', array('enable' => 0, 'vids' => 0, 'max_depth' => ''));
            if ($getlocations_term_marker['enable'] && $getlocations_term_marker['vids']) {
              $vids = $getlocations_term_marker['vids'];
              foreach ($vids AS $vid) {
                if ($nid = getlocations_get_nid_from_lid($lid)) {
                  $query = db_select('taxonomy_index', 't');
                  $query->fields('t', array('tid'));
                  $query->join('taxonomy_term_data', 'd', 't.tid=d.tid');
                  $query->condition('t.nid', $nid);
                  $query->condition('d.vid', $vid);
                  $result = $query->execute()->fetchObject();
                  if (isset($result->tid) && $result->tid > 0 && isset($options['term_marker_' . $result->tid])) {
                    $marker = $options['term_marker_' . $result->tid];
                  }
                }
              }
            }
          }
          elseif ($entity_type == 'taxonomy_term') {
            $marker = $options['vocabulary_map_marker'];
            if (isset($location['field_name'])) {
              if (isset($options['vocabulary_marker_' . $location['field_name']])) {
                $marker = $options['vocabulary_marker_' . $location['field_name']];
              }
            }
          }
          elseif ($entity_type == 'user') {
            $marker = $options['user_map_marker'];
          }
          elseif ($entity_type == 'comment') {
            $marker = $options['comment_map_marker'];
          }
        }

        // dump bummers with no lat/lon
        if ($latlon = getlocations_latlon_check($location['latitude'] . ',' . $location['longitude'])) {
          $ll = explode(',', $latlon);
          $location['latitude'] = $ll[0];
          $location['longitude'] = $ll[1];
          $title = htmlspecialchars_decode(isset($location['name']) && $location['name'] ? strip_tags($location['name']) : (isset($location['title']) && $location['title'] ? strip_tags($location['title']) : ''), ENT_QUOTES);
          $minmaxes = getlocations_do_minmaxes($ct, $location, $minmaxes);

          // per item marker
          if (isset($location['marker']) && ! empty($location['marker'])) {
            $marker = $location['marker'];
          }
          if (isset($location['mapzoom'])) {
            $mapzoom = $location['mapzoom'];
          }

          // categories
          $cat = '';
          if ($options['category_method']) {
            if ($options['category_method'] == 1) {
              // content type
              if (! isset($location['type']) && isset($location['machine_name'])) {
                $location['type'] = $location['machine_name'];
              }
              if (isset($location['type'])) {
                $cat = $location['type'];
                // lookup label
                $query = db_select('node_type', 't');
                $query->fields('t', array('name'));
                $query->condition('t.type', $cat);
                $label = $query->execute()->fetchField();
                $cats[$cat] = $label;
              }
            }
            elseif ($options['category_method'] == 2) {
              // term_reference_field
              if (isset($location[$options['category_term_reference_field']])) {
                $label = $location[$options['category_term_reference_field']];
                $cat = preg_replace("/\s+/", "_", $label);
                $cat = preg_replace("/'/", "", $cat);
                $cat = drupal_strtolower($cat);
                $cats[$cat] = $label;
              }
            }
            if ($cat) {
              $options['categories'] = $cats;
            }
          }

          if ($options['markeraction'] == 'popup') {
            $extra = FALSE;
            if (isset($options['getdirections_link'])) {
              $extra['gdlink'] = $options['getdirections_link'];
            }
            // 'show_search_distance'
            if ($options['show_search_distance'] && isset($map_settings['search_dist_info']) ) {
              $extra['sdist'] = (isset($map_settings['search_dist_info']['search_units']) ? $map_settings['search_dist_info']['search_units'] : '') . '|' . $map_settings['search_dist_info']['latitude'] . '|' . $map_settings['search_dist_info']['longitude'];
            }
            $markeraction = array('type' => 'popup', 'data' => ($custom_content ? $custom_content : getlocations_getinfo($lid, $base_field, $extra)));
          }
          elseif ($options['markeraction'] == 'link') {
            $markeraction = array('type' => 'link', 'data' => getlocations_getlidinfo($lid, $base_field));
          }
          else {
            $markeraction = array();
          }

          $iconlist[$marker] = getlocations_leaflet_get_marker($marker);

          $latlons[$ct] = array($location['latitude'], $location['longitude'], $base_field, 0, $lid, $title, $marker, $vector, $markeraction, $cat);

          // special case for ajax, a custom content field containing the key of the map associated with an exposed form
          $thiskey = FALSE;
          if (isset($location['nothing']) && preg_match("/^key_/", $location['nothing'])) {
            $thiskey = trim($location['nothing']);
          }

          $ct++;
        }
      }
    } // end foreach locations
  }

  if ($ct < 2 || $lid == 0) {
    unset($minmaxes);
    $minmaxes = '';
  }

  if (! empty($options['baselayers'])) {
    $map_layers = array();
    foreach ($options['baselayers'] AS $k => $v) {
      if ($options['baselayers'][$k] && isset($map_settings['map_layers'][$k])) {
        $map_layers[$k] = $map_settings['map_layers'][$k];
      }
    }
    if (! empty($map_layers)) {
      $map_settings['map_layers'] = $map_layers;
    }
  }

  $nodezoom = FALSE;
  if ($ct == 1 && $options['nodezoom']) {
    $nodezoom = $options['nodezoom'];
    $map_settings['map_opts']['center'] = array($location['latitude'], $location['longitude']);
    $map_settings['map_opts']['zoom'] = $nodezoom;
  }
  elseif ($ct < 1) {
    $ll = explode(',', $options['latlong']);
    $map_settings['map_opts']['center'] = array($ll[0], $ll[1]);
    $map_settings['map_opts']['zoom'] = $options['zoom'];
  }

  $mapid = getlocations_setup_map('', FALSE, FALSE, TRUE);
  if ($thiskey) {
    $mapid = $thiskey;
  }
  // add in some more
  $map_settings = getlocations_leaflet_map_settings_do($map_settings, $options, $latlons, $mapid);

  $map_settings['map_settings']['nodezoom'] = ($nodezoom ? $nodezoom : FALSE);
  $map_settings['map_settings']['minmaxes'] = (empty($minmaxes) ? FALSE : implode(',', $minmaxes));

  $map_settings['icons'] = $iconlist;
  $map_settings['datanum'] = $ct;
  $map_settings['latlons'] = $latlons;
  $map_settings['map_settings']['categories'] = $cats;
  $map_settings['map_settings']['category_showhide_buttons'] = $options['category_showhide_buttons'];

  $variables['map'] = theme('getlocations_leaflet_map', array(
    'width' => $options['width'],
    'height' => $options['height'],
    'map_settings' => $map_settings,
    'mapid' => $mapid,
    'links' => '',
  ));

}
