<?php

/**
 * @file
 * getlocations_fields_plugin_style_streetview.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Contains the getlocations_fields_streetview style plugin.
 */

/**
 * Getlocations style plugin to render a row as a google streetview.
 *
 * @ingroup views_style_plugins
 */
class getlocations_fields_plugin_style_streetview extends views_plugin_style {

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

    $options['width']                  = array('default' => $getlocations_defaults['width']);
    $options['height']                 = array('default' => $getlocations_defaults['height']);
    $options['sv_addresscontrol']         = array('default' => 1);
    $options['sv_addresscontrolposition'] = array('default' => '');
    $options['sv_pancontrol']             = array('default' => 1);
    $options['sv_pancontrolposition']     = array('default' => '');
    $options['sv_zoomcontrol']            = array('default' => 'default');
    $options['sv_zoomcontrolposition']    = array('default' => '');
    $options['sv_linkscontrol']           = array('default' => 1);
    $options['sv_imagedatecontrol']       = array('default' => 0);
    $options['sv_scrollwheel']            = array('default' => 1);
    $options['sv_clicktogo']              = array('default' => 1);
    $options['sv_fullscreen']             = array('default' => 0);

    return $options;

  } // end option_definition

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if (! module_exists('getlocations_fields')) {
      return;
    }
    $form['#theme'] = 'getlocations_plugin_style_streetview_options_form';

    $getlocations_fields_paths = getlocations_fields_paths_get();
    $form['#attached']['js'] = array($getlocations_fields_paths['getlocations_fields_views_path']);

    $handlers = $this->display->handler->get_handlers('field');
    $source_options = array('' => t('None'));

    foreach ($handlers as $handle) {
      $source_options[$handle->options['id']] = (!empty($handle->options['label'])) ? $handle->options['label'] : $handle->options['id'];
    }

    // streetview killswitch
    if (! getlocations_fields_streetview_settings_allow()) {
      $form['message'] = array(
        '#markup' => '<p><b>' . t('Streetview has been disabled globally, this plugin is inactive.') . '</b></p>',
      );
    }

    $form['width'] = getlocations_element_map_tf(
      t('Width'),
      $this->options['width'],
      t('The default width of a Google streetview, as a CSS length or percentage. Examples: <em>50px</em>, <em>5em</em>, <em>2.5in</em>, <em>95%</em>'),
      10,
      10,
      TRUE
    );

    $form['height'] = getlocations_element_map_tf(
      t('Height'),
      $this->options['height'],
      t('The default height of a Google streetview, as a CSS length or percentage. Examples: <em>50px</em>, <em>5em</em>, <em>2.5in</em>, <em>95%</em>'),
      10,
      10,
      TRUE
    );

    $form += getlocations_fields_sv_control_form($this->options);

    $form['sv_fullscreen'] = getlocations_element_map_checkbox(
      t('Show Fullscreen button'),
      $this->options['sv_fullscreen']
    );


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

  }

  function even_empty() {
    return parent::even_empty() || !empty($this->options['empty_result']);
  }

  function render() {
    if (isset($this->view->live_preview) && $this->view->live_preview) {
      return t('Getlocations Streetview views are not compatible with live preview.');
    }
    return parent::render();
  }


}
