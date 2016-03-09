<?php

/**
 * @file
 * Admin page callbacks for the Media: Flickr module.
 */

/**
 * Form builder; The Media: Flickr configuration form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function media_flickr_settings_form() {
  $form['media_flickr_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Flickr API key'),
    '#default_value' => variable_get('media_flickr_api_key', ''),
  );
  $form['media_flickr_api_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Flickr API secret'),
    '#default_value' => variable_get('media_flickr_api_secret', ''),
  );

  return system_settings_form($form);
}
