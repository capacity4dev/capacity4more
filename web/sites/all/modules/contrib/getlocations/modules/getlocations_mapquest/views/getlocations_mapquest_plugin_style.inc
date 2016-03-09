<?php

/**
 * @file
 * getlocations_mapquest_plugin_style.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Extension of the Views Plugin Style for Mapquest Map
 * Adapted from the GeoField Map views module and the OpenLayers Views module.
 */
class getlocations_mapquest_plugin_style extends views_plugin_style {

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

    $getlocations_mapquest_defaults = getlocations_mapquest_defaults();
    // fallback
    $getlocations_defaults = getlocations_defaults();

    foreach ($getlocations_mapquest_defaults AS $key => $value) {
      $options[$key] = array('default' => $value);
    }

    $options['map_resize']            = array('default' =>  0);
    $options['fullscreen_disable']    = array('default' =>  0);
    $options['styles']                = array('default' => '');
    $options['jquery_colorpicker_enabled'] = array('default' => 0);

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
  }

  /**
   * Options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    #if (! module_exists('getlocations_fields')) {
    #  return;
    #}

    $form['#theme'] = 'getlocations_mapquest_plugin_style_options_form';

    $getlocations_mapquest_paths = getlocations_mapquest_paths_get();
    $getlocations_paths = getlocations_paths_get();

    $form['#attached']['js'] = array(
      $getlocations_mapquest_paths['getlocations_mapquest_formatter_path'],
      $getlocations_paths['getlocations_views_path'],
    );

    $handlers = $this->display->handler->get_handlers('field');
    $source_options = array('' => t('None'));
    foreach ($handlers as $handle) {
      $source_options[$handle->options['id']] = (!empty($handle->options['label'])) ? $handle->options['label'] : $handle->options['id'];
    }

    $labels = array(
      'width' => t('Width'),
      'height' => t('Height'),
    );

    $form += getlocations_map_display_basics_form($this->options, $labels);
    unset($form['map_resize']);
    unset($form['fullscreen_disable']);
    unset($form['styles']);

    unset($form['zoom']['#options']['21']);
    unset($form['zoom']['#options']['20']);
    unset($form['zoom']['#options']['19']);

    unset($form['minzoom_map']['#options']['21']);
    unset($form['minzoom_map']['#options']['20']);
    unset($form['minzoom_map']['#options']['19']);

    unset($form['maxzoom_map']['#options']['21']);
    unset($form['maxzoom_map']['#options']['20']);
    unset($form['maxzoom_map']['#options']['19']);

    $form += getlocations_mapquest_display_options_form($this->options);

    unset($form['nodezoom']['#options']['21']);
    unset($form['nodezoom']['#options']['20']);
    unset($form['nodezoom']['#options']['19']);

    // markers
/*
    if ($this->options['awesome'] && $this->options['marker_type'] == 'fa') {
      // do awesome markers
      // nodes
      $labels = array(
        'awesome_icon' => t('Node Awesome icon'),
        'awesome_icon_color' => t('Node Awesome icon color'),
        'awesome_marker_color' => t('Node Awesome marker color'),
        'awesome_title' => t('Node Awesome Fonts icon settings'),
        'awesome_icon_spin' => t('Node Awesome icon spin'),
        'awesome_icon_size' => t('Node Awesome icon size'),
        'awesome_icon_type' => t('Node Awesome icon type'),
        'awesome_icon_flip' => t('Node Awesome icon flip and rotate'),
      );
      $form += getlocations_mapquest_awesome_markers_elements_get($this->options, $labels, "node");
      // TODO per content type fieldname etc
/////////////////
      // node type markers
      if ($types = getlocations_get_types()) {
        $getlocations_node_marker = variable_get('getlocations_node_marker', array('enable' => 0));
        if ($getlocations_node_marker['enable']) {
          $typect = 0;
          foreach ($types AS $type => $name) {
            $field_names = getlocations_get_fieldname2($type, 'node');
            foreach ($field_names AS $field_name) {
              $label = t('%name Map marker, field %field' , array('%name' => $name, '%field' => $field_name));
              $mkey = 'node_marker__' . drupal_strtolower($type) . '__' . $field_name;
              $labels = array(
                'awesome_icon'         => t($label . ' Awesome icon'),
                'awesome_icon_color'   => t($label . ' Awesome icon color'),
                'awesome_marker_color' => t($label . ' Awesome marker color'),
                'awesome_title'        => t($label . ' Awesome Fonts icon settings'),
                'awesome_icon_spin'    => t($label . ' Awesome icon spin'),
                'awesome_icon_size'    => t($label . ' Awesome icon size'),
                'awesome_icon_type'    => t($label . ' Awesome icon type'),
                'awesome_icon_flip'    => t($label . ' Awesome icon flip and rotate'),
              );
              $form += getlocations_mapquest_awesome_markers_elements_get($this->options, $labels, $mkey);
            }
          }
        }
      }
/////////////////
      // users
      if (getlocations_check_entity_type('user') || getlocations_check_entity_type('profile2')) {
        $labels = array(
          'awesome_icon' => t('User Awesome icon'),
          'awesome_icon_color' => t('User Awesome icon color'),
          'awesome_marker_color' => t('User Awesome marker color'),
          'awesome_title' => t('User Awesome Fonts icon settings'),
          'awesome_icon_spin' => t('User Awesome icon spin'),
          'awesome_icon_size' => t('User Awesome icon size'),
          'awesome_icon_type' => t('User Awesome icon type'),
          'awesome_icon_flip' => t('User Awesome icon flip and rotate'),
        );
        $form += getlocations_mapquest_awesome_markers_elements_get($this->options, $labels, 'user');
      }

      if (module_exists('taxonomy')) {
        if ($types = getlocations_get_machine_vocabularies()) {
          // vocabulary
          // TODO per vocab
          $labels = array(
            'awesome_icon' => t('Vocabulary Awesome icon'),
            'awesome_icon_color' => t('Vocabulary Awesome icon color'),
            'awesome_marker_color' => t('Vocabulary Awesome marker color'),
            'awesome_title' => t('Vocabulary Awesome Fonts icon settings'),
            'awesome_icon_spin' => t('Vocabulary Awesome icon spin'),
            'awesome_icon_size' => t('Vocabulary Awesome icon size'),
            'awesome_icon_type' => t('Vocabulary Awesome icon type'),
            'awesome_icon_flip' => t('Vocabulary Awesome icon flip and rotate'),
          );
          $form += getlocations_mapquest_awesome_markers_elements_get($this->options, $labels, 'vocabulary');

        }
        // terms
        // TODO per term
        $labels = array(
          'awesome_icon' => t('Term Awesome icon'),
          'awesome_icon_color' => t('Term Awesome icon color'),
          'awesome_marker_color' => t('Term Awesome marker color'),
          'awesome_title' => t('Term Awesome Fonts icon settings'),
          'awesome_icon_spin' => t('Term Awesome icon spin'),
          'awesome_icon_size' => t('Term Awesome icon size'),
          'awesome_icon_type' => t('Term Awesome icon type'),
          'awesome_icon_flip' => t('Term Awesome icon flip and rotate'),
        );
        $form += getlocations_mapquest_awesome_markers_elements_get($this->options, $labels, 'term');
      }
      if (getlocations_check_entity_type('comment')) {
        // comment
        $labels = array(
          'awesome_icon' => t('Comment Awesome icon'),
          'awesome_icon_color' => t('Comment Awesome icon color'),
          'awesome_marker_color' => t('Comment Awesome marker color'),
          'awesome_title' => t('Comment Awesome Fonts icon settings'),
          'awesome_icon_spin' => t('Comment Awesome icon spin'),
          'awesome_icon_size' => t('Comment Awesome icon size'),
          'awesome_icon_type' => t('Comment Awesome icon type'),
          'awesome_icon_flip' => t('Comment Awesome icon flip and rotate'),
        );
        $form += getlocations_mapquest_awesome_markers_elements_get($this->options, $labels, 'comment');

      }

    }
    else {
*/
      // do getlocations markers
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

/*    } */

    // search markers
    if (module_exists('getlocations_fields') && module_exists('views')) {
      $form += getlocations_fields_views_search_form($this->options, 'mapquest');
    }

    // end markers

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


#    $form['nodezoom'] = getlocations_element_map_zoom(
#      t('Default Zoom for Single location'),
#      $this->options['nodezoom'],
#      t('The Default zoom level for a single marker.')
#    );

    $form['empty_result'] = getlocations_element_map_checkbox(
      t('Show map even if view has no results'),
      $this->options['empty_result']
    );
    #$form['empty_result'] = array('#type' => 'value', '#value' => 0);

    // munge the title and description
    $form['category_showhide_buttons']['#title'] = t('Enable category show/hide checkboxes');
    $form['category_showhide_buttons']['#description'] = t('This option will place checkboxes on the layer control');

  } // end options_form

  /**
   * Validate the options form.
   */
  function options_validate(&$form, &$form_state) {

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

    // latlong
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
      return t('Getlocations Mapquest views are not compatible with live preview.');
    }
    return parent::render();
  }


}
