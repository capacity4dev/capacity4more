<?php

/**
 * @file
 * getlocations_fields_plugin_argument_default_bboxquery.inc
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Location bboxquery argument handler.
 * code derived from https://www.drupal.org/project/views_geofield_bbox.
 *
 */

/**
 * Argument handler to accept bbox
 */
class getlocations_fields_plugin_argument_default_bboxquery extends views_plugin_argument_default {
  function option_definition() {
    $options = parent::option_definition();
    $options['argument'] = array('default' => '');
    $options['arg_id'] = array('default' => 'bbox');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['info'] = array(
      '#markup' => '<p class="description">Attempt to pull bounding box info
      directly from the query string, bypassing Drupal\'s normal argument
      handling. If the argument does not exist, all values will be shown.</p>',
    );
    $form['arg_id'] = array(
      '#type' => 'textfield',
      '#title'  => t('Query argument ID'),
      '#size' => 60,
      '#maxlength' => 64,
      '#default_value'  => $this->options['arg_id'] ? $this->options['arg_id'] : t('bbox'),
      '#description'  => t('The ID of the query argument.<br />Use <em>bbox</em>, (as in "<em>?bbox=left,bottom,right,top</em>".)<br />
        <b>mapping logic:</b><br />
        southWest.lng = left,
        southWest.lat = bottom,
        northEast.lng = right,
        northEast.lat = top
      '),
    );
  }

  /**
   * Return the default argument.
   */
  function get_argument() {
    if (isset($_GET[$this->options['arg_id']])) {
      return $_GET[$this->options['arg_id']];
    }
    else {
      return TRUE; // Return all values if arg not present
    }
  }

}
