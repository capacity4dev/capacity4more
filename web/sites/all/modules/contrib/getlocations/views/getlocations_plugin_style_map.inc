<?php

/**
 * @file
 * getlocations_plugin_style_map.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Contains the getlocations style plugin.
 */

/**
 * Getlocations style plugin to render rows as icons on a map.
 *
 * @ingroup views_style_plugins
 */
class getlocations_plugin_style_map extends views_plugin_style {

  /**
   * If this view is displaying an entity, save the entity type and info.
   */
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);

    foreach (entity_get_info() as $key => $info) {
      if ($view->base_table == $info['base table']) {
        $this->entity_type = $key;
        $this->entity_info = $info;
        break;
      }
    }
  }

  /**
   * Set default options
   */
  function options(&$options) {
    parent::options($options);
    $options['empty_result'] = FALSE;
  }

  function option_definition() {

    $options = parent::option_definition();

    $getlocations_defaults = getlocations_defaults();

    $options['width']                 = array('default' => $getlocations_defaults['width']);
    $options['height']                = array('default' => $getlocations_defaults['height']);
    $options['node_map_marker']       = array('default' => $getlocations_defaults['node_map_marker']);
    $options['user_map_marker']       = array('default' => $getlocations_defaults['user_map_marker']);
    $options['vocabulary_map_marker'] = array('default' => $getlocations_defaults['vocabulary_map_marker']);
    $options['term_map_marker']       = array('default' => $getlocations_defaults['term_map_marker']);
    $options['comment_map_marker']    = array('default' => $getlocations_defaults['comment_map_marker']);
    $options['latlong']               = array('default' => $getlocations_defaults['latlong']);
    $options['zoom']                  = array('default' => $getlocations_defaults['zoom']);
    $options['minzoom_map']           = array('default' => $getlocations_defaults['minzoom_map']);
    $options['maxzoom_map']           = array('default' => $getlocations_defaults['maxzoom_map']);
    $options['controltype']           = array('default' => $getlocations_defaults['controltype']);
    $options['pancontrol']            = array('default' => $getlocations_defaults['pancontrol']);
    $options['mtc']                   = array('default' => $getlocations_defaults['mtc']);
    $options['maptype']               = array('default' => $getlocations_defaults['maptype']);
    $options['baselayers']            = array('default' => $getlocations_defaults['baselayers']);
    $options['scale']                 = array('default' => $getlocations_defaults['scale']) ;
    $options['overview']              = array('default' => $getlocations_defaults['overview']);
    $options['overview_opened']       = array('default' => $getlocations_defaults['overview_opened']);
    $options['scrollwheel']           = array('default' => $getlocations_defaults['scrollwheel']);
    $options['show_maplinks']         = array('default' => $getlocations_defaults['show_maplinks']);
    $options['sv_show']               = array('default' => $getlocations_defaults['sv_show']);
    $options['sv_showfirst']          = array('default' => $getlocations_defaults['sv_showfirst']);
    $options['sv_heading']            = array('default' => $getlocations_defaults['sv_heading']);
    $options['sv_zoom']               = array('default' => $getlocations_defaults['sv_zoom']);
    $options['sv_pitch']              = array('default' => $getlocations_defaults['sv_pitch']);
    $options['fullscreen']            = array('default' => $getlocations_defaults['fullscreen']);
    $options['show_bubble_on_one_marker'] = array('default' => $getlocations_defaults['show_bubble_on_one_marker']);
    $options['trafficinfo']           = array('default' => $getlocations_defaults['trafficinfo']);
    $options['trafficinfo_state']     = array('default' => $getlocations_defaults['trafficinfo_state']);
    $options['bicycleinfo']           = array('default' => $getlocations_defaults['bicycleinfo']);
    $options['bicycleinfo_state']     = array('default' => $getlocations_defaults['bicycleinfo_state']);
    $options['transitinfo']           = array('default' => $getlocations_defaults['transitinfo']);
    $options['transitinfo_state']     = array('default' => $getlocations_defaults['transitinfo_state']);
    $options['panoramio_use']         = array('default' => $getlocations_defaults['panoramio_use']);
    $options['panoramio_show']        = array('default' => $getlocations_defaults['panoramio_show']);
    $options['panoramio_state']       = array('default' => $getlocations_defaults['panoramio_state']);
    $options['places']                = array('default' => $getlocations_defaults['places']);
    $options['poi_show']              = array('default' => $getlocations_defaults['poi_show']);
    $options['transit_show']          = array('default' => $getlocations_defaults['transit_show']);
    $options['minzoom']               = array('default' => $getlocations_defaults['minzoom']);
    $options['maxzoom']               = array('default' => $getlocations_defaults['maxzoom']);
    $options['nodezoom']              = array('default' => $getlocations_defaults['nodezoom']);
    $options['markeraction']          = array('default' => $getlocations_defaults['markeraction']);
    $options['markeractiontype']      = array('default' => $getlocations_defaults['markeractiontype']);
    $options['markermanagertype']     = array('default' => $getlocations_defaults['markermanagertype']);
    $options['usemarkermanager']      = array('default' => $getlocations_defaults['usemarkermanager']);
    $options['useclustermanager']     = array('default' => $getlocations_defaults['useclustermanager']);
    $options['weather_use']           = array('default' => $getlocations_defaults['weather_use']);
    $options['weather_show']          = array('default' => $getlocations_defaults['weather_show']);
    $options['weather_state']         = array('default' => $getlocations_defaults['weather_state']);
    $options['weather_cloud']         = array('default' => $getlocations_defaults['weather_cloud']);
    $options['weather_cloud_state']   = array('default' => $getlocations_defaults['weather_cloud_state']);
    $options['map_backgroundcolor']   = array('default' => $getlocations_defaults['map_backgroundcolor']);
    if (! $getlocations_defaults['markermanagertype']) {
      $options['usemarkermanager'] = 0;
      $options['useclustermanager'] = 0;
    }
    $options['markerclusterer_style']    = array('default' => $getlocations_defaults['markerclusterer_style']);
    $options['markerclusterer_zoom']     = array('default' => $getlocations_defaults['markerclusterer_zoom']);
    $options['markerclusterer_size']     = array('default' => $getlocations_defaults['markerclusterer_size']);
    $options['markerclusterer_minsize']  = array('default' => $getlocations_defaults['markerclusterer_minsize']);
    $options['markerclusterer_title']    = array('default' => $getlocations_defaults['markerclusterer_title']);
    $options['markerclusterer_imgpath']  = array('default' => $getlocations_defaults['markerclusterer_imgpath']);
    $options['pansetting']               = array('default' => $getlocations_defaults['pansetting']);
    $options['draggable']                = array('default' => $getlocations_defaults['draggable']);
    $options['styles']                   = array('default' => $getlocations_defaults['styles']);
    $options['custom_content_enable']    = array('default' => $getlocations_defaults['custom_content_enable']);
    $options['custom_content_source']    = array('default' => $getlocations_defaults['custom_content_source']);
    $options['polygons_enable']          = array('default' => $getlocations_defaults['polygons_enable']);
    $options['polygons_strokecolor']     = array('default' => $getlocations_defaults['polygons_strokecolor']);
    $options['polygons_strokeopacity']   = array('default' => $getlocations_defaults['polygons_strokeopacity']);
    $options['polygons_strokeweight']    = array('default' => $getlocations_defaults['polygons_strokeweight']);
    $options['polygons_fillcolor']       = array('default' => $getlocations_defaults['polygons_fillcolor']);
    $options['polygons_fillopacity']     = array('default' => $getlocations_defaults['polygons_fillopacity']);
    $options['polygons_coords']          = array('default' => $getlocations_defaults['polygons_coords']);
    $options['polygons_clickable']       = array('default' => $getlocations_defaults['polygons_clickable']);
    $options['polygons_message']         = array('default' => $getlocations_defaults['polygons_message']);
    $options['rectangles_enable']        = array('default' => $getlocations_defaults['rectangles_enable']);
    $options['rectangles_strokecolor']   = array('default' => $getlocations_defaults['rectangles_strokecolor']);
    $options['rectangles_strokeopacity'] = array('default' => $getlocations_defaults['rectangles_strokeopacity']);
    $options['rectangles_strokeweight']  = array('default' => $getlocations_defaults['rectangles_strokeweight']);
    $options['rectangles_fillcolor']     = array('default' => $getlocations_defaults['rectangles_fillcolor']);
    $options['rectangles_fillopacity']   = array('default' => $getlocations_defaults['rectangles_fillopacity']);
    $options['rectangles_coords']        = array('default' => $getlocations_defaults['rectangles_coords']);
    $options['rectangles_clickable']     = array('default' => $getlocations_defaults['rectangles_clickable']);
    $options['rectangles_message']       = array('default' => $getlocations_defaults['rectangles_message']);
    $options['rectangles_apply']         = array('default' => $getlocations_defaults['rectangles_apply']);
    $options['rectangles_dist']          = array('default' => $getlocations_defaults['rectangles_dist']);
    $options['circles_enable']           = array('default' => $getlocations_defaults['circles_enable']);
    $options['circles_strokecolor']      = array('default' => $getlocations_defaults['circles_strokecolor']);
    $options['circles_strokeopacity']    = array('default' => $getlocations_defaults['circles_strokeopacity']);
    $options['circles_strokeweight']     = array('default' => $getlocations_defaults['circles_strokeweight']);
    $options['circles_fillcolor']        = array('default' => $getlocations_defaults['circles_fillcolor']);
    $options['circles_fillopacity']      = array('default' => $getlocations_defaults['circles_fillopacity']);
    $options['circles_coords']           = array('default' => $getlocations_defaults['circles_coords']);
    $options['circles_clickable']        = array('default' => $getlocations_defaults['circles_clickable']);
    $options['circles_message']          = array('default' => $getlocations_defaults['circles_message']);
    $options['circles_radius']           = array('default' => $getlocations_defaults['circles_radius']);
    $options['circles_apply']            = array('default' => $getlocations_defaults['circles_apply']);
    $options['polylines_enable']         = array('default' => $getlocations_defaults['polylines_enable']);
    $options['polylines_strokecolor']    = array('default' => $getlocations_defaults['polylines_strokecolor']);
    $options['polylines_strokeopacity']  = array('default' => $getlocations_defaults['polylines_strokeopacity']);
    $options['polylines_strokeweight']   = array('default' => $getlocations_defaults['polylines_strokeweight']);
    $options['polylines_coords']         = array('default' => $getlocations_defaults['polylines_coords']);
    $options['polylines_clickable']      = array('default' => $getlocations_defaults['polylines_clickable']);
    $options['polylines_message']        = array('default' => $getlocations_defaults['polylines_message']);
    $options['kml_url']                  = array('default' => $getlocations_defaults['kml_group']['kml_url']);
    $options['kml_url_click']            = array('default' => $getlocations_defaults['kml_group']['kml_url_click']);
    $options['kml_url_infowindow']       = array('default' => $getlocations_defaults['kml_group']['kml_url_infowindow']);
    $options['kml_url_viewport']         = array('default' => $getlocations_defaults['kml_group']['kml_url_viewport']);
    $options['kml_url_button']           = array('default' => $getlocations_defaults['kml_group']['kml_url_button']);
    $options['kml_url_button_label']     = array('default' => $getlocations_defaults['kml_group']['kml_url_button_label']);
    $options['kml_url_button_state']     = array('default' => $getlocations_defaults['kml_group']['kml_url_button_state']);
    $options['region_bias']              = array('default' => $getlocations_defaults['region_bias']);
    $options['fullscreen_disable']       = array('default' => $getlocations_defaults['fullscreen_disable']);
    $options['search_places']            = array('default' => $getlocations_defaults['search_places']);
    $options['search_places_size']       = array('default' => $getlocations_defaults['search_places_size']);
    $options['search_places_position']   = array('default' => $getlocations_defaults['search_places_position']);
    $options['search_places_label']      = array('default' => $getlocations_defaults['search_places_label']);
    $options['search_places_placeholder'] = array('default' => $getlocations_defaults['search_places_placeholder']);
    $options['search_places_dd']         = array('default' => $getlocations_defaults['search_places_dd']);
    $options['search_places_list']       = array('default' => $getlocations_defaults['search_places_list']);
    // jquery_colorpicker TODO does not work in Views Getlocations | settings
    $options['jquery_colorpicker_enabled'] = array('default' => 0);
    #$options['jquery_colorpicker_enabled'] = array('default' => $getlocations_defaults['jquery_colorpicker_enabled']);

    // categories
    $options['category_method']               = array('default' => $getlocations_defaults['category_method']);
    $options['category_term_reference_field'] = array('default' => $getlocations_defaults['category_term_reference_field']);
    $options['category_showhide_buttons']     = array('default' => $getlocations_defaults['category_showhide_buttons']);

    // geojson
    $options['geojson_enable']  = array('default' => $getlocations_defaults['geojson_enable']);
    $options['geojson_options'] = array('default' => $getlocations_defaults['geojson_options']);
    $options['geojson_data']    = array('default' => $getlocations_defaults['geojson_data']);

    $options['zoomcontrolposition']  = array('default' => $getlocations_defaults['zoomcontrolposition']);
    $options['pancontrolposition']   = array('default' => $getlocations_defaults['pancontrolposition']);
    $options['mapcontrolposition']   = array('default' => $getlocations_defaults['mapcontrolposition']);
    $options['scalecontrolposition'] = array('default' => $getlocations_defaults['scalecontrolposition']);
    $options['svcontrolposition']    = array('default' => $getlocations_defaults['svcontrolposition']);

    $options['highlight_enable']         = array('default' => $getlocations_defaults['highlight_enable']);
    $options['highlight_strokecolor']    = array('default' => $getlocations_defaults['highlight_strokecolor']);
    $options['highlight_strokeopacity']  = array('default' => $getlocations_defaults['highlight_strokeopacity']);
    $options['highlight_strokeweight']   = array('default' => $getlocations_defaults['highlight_strokeweight']);
    $options['highlight_fillcolor']      = array('default' => $getlocations_defaults['highlight_fillcolor']);
    $options['highlight_fillopacity']    = array('default' => $getlocations_defaults['highlight_fillopacity']);
    $options['highlight_radius']         = array('default' => $getlocations_defaults['highlight_radius']);
    $options['getdirections_link']       = array('default' => $getlocations_defaults['getdirections_link']);

    $options['gps_button']       = array('default' => 0);
    $options['gps_button_label'] = array('default' => $getlocations_defaults['gps_button_label']);
    $options['gps_marker']       = array('default' => $getlocations_defaults['gps_marker']);
    $options['gps_marker_title'] = array('default' => $getlocations_defaults['gps_marker_title']);
    $options['gps_bubble']       = array('default' => $getlocations_defaults['gps_bubble']);
    $options['gps_geocode']      = array('default' => $getlocations_defaults['gps_geocode']);
    $options['gps_center']       = array('default' => $getlocations_defaults['gps_center']);

    $options['show_search_distance']                = array('default' => $getlocations_defaults['show_search_distance']);
    $options['views_search_marker_enable']          = array('default' => $getlocations_defaults['views_search_marker_enable']);
    $options['views_search_marker']                 = array('default' => $getlocations_defaults['views_search_marker']);
    $options['views_search_marker_toggle']          = array('default' => $getlocations_defaults['views_search_marker_toggle']);
    $options['views_search_marker_toggle_active']   = array('default' => $getlocations_defaults['views_search_marker_toggle_active']);
    $options['views_search_radshape_enable']        = array('default' => $getlocations_defaults['views_search_radshape_enable']);
    $options['views_search_radshape_strokecolor']   = array('default' => $getlocations_defaults['views_search_radshape_strokecolor']);
    $options['views_search_radshape_strokeopacity'] = array('default' => $getlocations_defaults['views_search_radshape_strokeopacity']);
    $options['views_search_radshape_strokeweight']  = array('default' => $getlocations_defaults['views_search_radshape_strokeweight']);
    $options['views_search_radshape_fillcolor']     = array('default' => $getlocations_defaults['views_search_radshape_fillcolor']);
    $options['views_search_radshape_fillopacity']   = array('default' => $getlocations_defaults['views_search_radshape_fillopacity']);
    $options['views_search_radshape_toggle']        = array('default' => $getlocations_defaults['views_search_radshape_toggle']);
    $options['views_search_radshape_toggle_active'] = array('default' => $getlocations_defaults['views_search_radshape_toggle_active']);
    $options['views_search_center']                 = array('default' => $getlocations_defaults['views_search_center']);

    // node markers
    $getlocations_node_marker = variable_get('getlocations_node_marker', array('enable' => 0));
    if ($getlocations_node_marker['enable']) {
      if ($types = getlocations_get_types()) {
        foreach ($types AS $type => $name) {
          $field_names = getlocations_get_fieldname2($type, 'node');
          foreach ($field_names AS $field_name) {
            $mkey = 'node_marker__' . drupal_strtolower($type) . '__' . $field_name;
            $mmarker = (isset($getlocations_node_marker['content_type'][$type]['field_name'][$field_name]['map_marker']) ? $getlocations_node_marker['content_type'][$type]['field_name'][$field_name]['map_marker'] : $getlocations_defaults['node_map_marker']);
            $options[$mkey] = array('default' => $mmarker);
          }
        }
      }
    }
    if (module_exists('taxonomy')) {
      // vocabulary markers
      if ($types = getlocations_get_vocabularies()) {
        $getlocations_vocabulary_marker = variable_get('getlocations_vocabulary_marker', array('enable' => 0));
        if ($getlocations_vocabulary_marker['enable']) {
          foreach ($types AS $type => $name) {
            $field_name = getlocations_get_fieldname($type, 'taxonomy_term');
            $mkey = 'vocabulary_marker_' . $field_name;
            $mmarker = (isset($getlocations_vocabulary_marker['vocabulary'][$type]['map_marker']) ? $getlocations_vocabulary_marker['vocabulary'][$type]['map_marker'] : $getlocations_defaults['vocabulary_map_marker']);
            $options[$mkey] = array('default' => $mmarker);
          }
        }
      }

      // term markers
      $getlocations_term_marker = variable_get('getlocations_term_marker', array('enable' => 0, 'vids' => 0, 'max_depth' => ''));
      if ($getlocations_term_marker['enable'] && $getlocations_term_marker['vids']) {
        $depth = is_numeric($getlocations_term_marker['max_depth']) && $getlocations_term_marker['max_depth'] > 0 ? $getlocations_term_marker['max_depth'] : NULL;
        $vids = $getlocations_term_marker['vids'];
        foreach ($vids AS $vid) {
          $terms = taxonomy_get_tree($vid, 0, $depth);
          foreach ($terms AS $term) {
            $tid = $term->tid;
            $mkey = 'term_marker_' . $tid;
            $mmarker = (isset($getlocations_term_marker['vid'][$vid]['term'][$tid]['map_marker']) ? $getlocations_term_marker['vid'][$vid]['term'][$tid]['map_marker'] : $getlocations_defaults['term_map_marker']);
            $options[$mkey] = array('default' => $mmarker);
          }
        }
      }
    }

    // empty_result
    $options['empty_result'] = array('default' => FALSE);

    return $options;

  } // end option_definition

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['#theme'][] = 'getlocations_plugin_style_map_options_form';
    $getlocations_paths = getlocations_paths_get();
    $form['#attached']['js'] = array($getlocations_paths['getlocations_views_path']);

    $handlers = $this->display->handler->get_handlers('field');
    $source_options = array('' => t('None'));

    foreach ($handlers as $handle) {
      $source_options[$handle->options['id']] = (!empty($handle->options['label'])) ? $handle->options['label'] : $handle->options['id'];
    }
    $labels = array(
      'width' => t('Width'),
      'height' => t('Height'),
      'styles' => t('Styles'),
      'latlong' => t('Map center'),
      'zoom' => t('Zoom'),
      'minzoom_map' => t('Minimum Zoom'),
      'maxzoom_map' => t('Maximum Zoom'),
    );

    $form += getlocations_map_display_basics_form($this->options, $labels);
    $form += getlocations_map_display_options_form($this->options, FALSE);

    // markers
    $markers = getlocations_get_marker_titles();
    // node markers
    $getlocations_node_marker = variable_get('getlocations_node_marker', array('enable' => 0));
    if ($getlocations_node_marker['enable']) {
      if ($types = getlocations_get_types()) {
        foreach ($types AS $type => $name) {
          $field_names = getlocations_get_fieldname2($type, 'node');
          foreach ($field_names AS $field_name) {
            if (isset($getlocations_node_marker['content_type'][$type]['field_name'][$field_name]['map_marker']) ) {
              $mkey = 'node_marker__' . drupal_strtolower($type) . '__' . $field_name;
              $form[$mkey] = getlocations_element_map_marker(
                t('%name Content Map Marker, field %field', array('%name' => $name, '%field' => $field_name)),
                $markers,
                (isset($this->options[$mkey]) ? $this->options[$mkey] : $getlocations_node_marker['content_type'][$type]['field_name'][$field_name]['map_marker'])
              );
            }
          }
        }
      }
    }
    else {
      $form['node_map_marker'] = getlocations_element_map_marker(
        t('Content Map marker'),
        $markers,
        $this->options['node_map_marker']
      );
    }
    // user markers
    if (getlocations_check_entity_type('user') || getlocations_check_entity_type('profile2')) {
      $form['user_map_marker'] = getlocations_element_map_marker(
        t('User Map Marker'),
        $markers,
        $this->options['user_map_marker']
      );
    }
    // vocabulary markers
    if (module_exists('taxonomy')) {
      if ($types = getlocations_get_machine_vocabularies()) {
        $types2 = getlocations_get_vocabularies();
        $getlocations_vocabulary_marker = variable_get('getlocations_vocabulary_marker', array('enable' => 0));
        if ($getlocations_vocabulary_marker['enable']) {
          foreach ($types AS $type => $name) {
            $field_name = getlocations_get_fieldname($name, 'taxonomy_term');
            $mkey = 'vocabulary_marker_' . $field_name;
            $form[$mkey] = getlocations_element_map_marker(
              t('%name Vocabulary Marker', array('%name' => $types2[$type])),
              $markers,
              (isset($this->options[$mkey]) ? $this->options[$mkey] : $getlocations_vocabulary_marker['vocabulary'][$type]['map_marker'])
            );
          }
        }
        else {
          $form['vocabulary_map_marker'] = getlocations_element_map_marker(
            t('Vocabulary Map Marker'),
            $markers,
            $this->options['vocabulary_map_marker']
          );
        }
      }

      // term markers
      $getlocations_term_marker = variable_get('getlocations_term_marker', array('enable' => 0, 'vids' => 0, 'max_depth' => ''));
      if ($getlocations_term_marker['enable'] && $getlocations_term_marker['vids']) {
        $depth = is_numeric($getlocations_term_marker['max_depth']) && $getlocations_term_marker['max_depth'] > 0 ? $getlocations_term_marker['max_depth'] : NULL;
        $vids = $getlocations_term_marker['vids'];
        foreach ($vids AS $vid) {
          $terms = taxonomy_get_tree($vid, 0, $depth);
          $tct = 0;
          foreach ($terms AS $term) {
            $name = $term->name;
            $tid = $term->tid;
            $mkey = 'term_marker_' . $tid;
            $form[$mkey] = getlocations_element_map_marker(
              t('%name Map Marker', array('%name' => $name)),
              $markers,
              $this->options[$mkey]
            );
            if (! $tct) {
              $v = taxonomy_vocabulary_load($vid);
              $vocab_name = $v->name;
              $form[$mkey]['#prefix'] = t('Terms for %name', array('%name' => $vocab_name));
            }
            $tct++;
          }
        }
      }
      else {
        $form['term_map_marker'] = getlocations_element_map_marker(
          t('Term Map marker'),
          $markers,
          $this->options['term_map_marker']
        );
      }
    }
    // comments
    if (getlocations_check_entity_type('comment')) {
      // default comment marker
      $form['comment_map_marker'] = getlocations_element_map_marker(
        t('Comment Map marker'),
        $markers,
        $this->options['comment_map_marker']
      );
    }

    $form['markeractiontype'] = getlocations_element_map_markeractiontype(
      $this->options['markeractiontype']
    );
    $form['markeraction'] = getlocations_element_map_markeraction(
      $this->options['markeraction']
    );

    if (module_exists('getdirections')) {
      $form['getdirections_link'] = getlocations_element_map_checkbox(
        t('Link to Getdirections in bubble'),
        $this->options['getdirections_link'],
        t('Include a link to the Getdirections page in InfoBubble/InfoWindow.')
      );
    }

    // views_search_marker etc
    if (module_exists('getlocations_fields') && module_exists('views')) {
      $form += getlocations_fields_views_search_form($this->options);
    }

    // categories
    $term_reference_fields = getlocations_get_term_reference_fields();
    $opts = array(0 => t('None'), 1 => t('Content Type'));
    if ($term_reference_fields) {
      $opts += array(2 => t('Term reference'));
    }
    $form['category_method'] = getlocations_element_dd(
      t('Category method'),
      $this->options['category_method'],
      $opts,
      t('To ensure that this works you will need to add either a Content type or a Term reference field to the Field list in your View.')
    );
    $form['category_method']['#suffix'] = '<div id="wrap-category1">';
    if ($term_reference_fields) {
      $form['category_term_reference_field'] = getlocations_element_dd(
        t('Term reference field name'),
        $this->options['category_term_reference_field'],
        $term_reference_fields,
        t('Select the field on which you are categorising.')
      );
      $form['category_term_reference_field']['#prefix'] = '<div id="wrap-category2">';
      $form['category_term_reference_field']['#suffix'] = '</div>';
    }
    $form['category_showhide_buttons'] = getlocations_element_map_checkbox(
      t('Enable category show/hide buttons'),
      $this->options['category_showhide_buttons'],
      t('This option will place toggle buttons on the map.')
    );
    $form['category_showhide_buttons']['#suffix'] = '</div>';

    // custom content
    $form['custom_content_enable'] = getlocations_element_map_checkbox(
      t('Replace default content'),
      $this->options['custom_content_enable']
    );
    $form['custom_content_enable']['#prefix'] = '<div id="wrap-custom-content-enable">';
    $form['custom_content_enable'][ '#suffix'] = '</div>';
    $form['custom_content_source'] = getlocations_element_dd(
      t('Popup Data'),
      $this->options['custom_content_source'],
      $source_options,
      t('The field to use as a data source for the marker popup.')
    );
    $form['custom_content_source']['#prefix'] = '<div id="wrap-custom-content-source">';
    $form['custom_content_source']['#suffix'] = '</div>';

    // markermanager option
    if ($this->options['markermanagertype'] == 1) {
      $form['useclustermanager'] = array('#type' => 'hidden', '#value' => 0);
      // markermanager
      $form += getlocations_markermanager_form($this->options);
      $form['usemarkermanager']['#suffix'] = '<div id="wrap-usemarkermanager">';
      $form['maxzoom']['#suffix'] = '</div>';
    }
    elseif ($this->options['markermanagertype'] == 2)  {
      $form['usemarkermanager'] = array('#type' => 'hidden', '#value' => 0);
      $form += getlocations_markercluster_form($this->options);
      $form['useclustermanager']['#suffix'] = '<div id="wrap-useclustermanager">';
      $form['markerclusterer_minsize']['#suffix'] = '</div>';
    }
    else {
      $form['useclustermanager'] = array('#type' => 'hidden', '#value' => 0);
      $form['usemarkermanager'] = array('#type' => 'hidden', '#value' => 0);
    }

    $form['nodezoom'] = getlocations_element_map_zoom(
      t('Default Zoom for Single location'),
      $this->options['nodezoom'],
      t('The Default zoom level for a single marker.')
    );
    $form['pansetting'] = getlocations_element_map_pansetting(
      $this->options['pansetting']
    );
    $form['empty_result'] = getlocations_element_map_checkbox(
      t('Show map even if view has no results'),
      $this->options['empty_result']
    );

  } // end options_form

  /**
   * Validate the options form.
   */

  function options_validate(&$form, &$form_state) {

    $list = array('Map', 'Satellite', 'Hybrid', 'Physical', 'OpenStreetMap');
    $found = FALSE;
    foreach ($list AS $maptype) {
      if (isset($form_state['values']['maptype']) && $form_state['values']['maptype'] == $maptype && $form_state['values']['baselayers'][$maptype] ) {
        $found = TRUE;
        break;
      }
    }
    if (! $found) {
      // force a setting
      $form_state['values']['maptype'] = 'Map';
      $form_state['values']['baselayers']['Map'] = 1;
    }
    // css check
    if (isset($form_state['values']['style_options']['width'])) {
      if ($check = getlocations_dim_check($form_state['values']['style_options']['width'])) {
        $form_state['values']['style_options']['width'] = $check;
      }
      else {
        form_set_error('style_options][width', t('Width must be valid css'));
      }
    }
    if (isset($form_state['values']['style_options']['height'])) {
      if ($check = getlocations_dim_check($form_state['values']['style_options']['height'])) {
        $form_state['values']['style_options']['height'] = $check;
      }
      else {
        form_set_error('style_options][height', t('Height must be valid css'));
      }
    }
    if (isset($form_state['values']['style_options']['latlong'])) {
      if ($latlon = getlocations_latlon_check($form_state['values']['style_options']['latlong'])) {
        $form_state['values']['style_options']['latlong'] = $latlon;
      }
      else {
        form_set_error('style_options][latlong', t('Map coordinates must be expressed as a decimal latitude and longitude, separated by a comma.'));
      }
    }

  }

  function even_empty() {
    return parent::even_empty() || !empty($this->options['empty_result']);
  }

  function render() {
    if (isset($this->view->live_preview) && $this->view->live_preview) {
      return t('Getlocations Map views are not compatible with live preview.');
    }
    return parent::render();
  }

}
