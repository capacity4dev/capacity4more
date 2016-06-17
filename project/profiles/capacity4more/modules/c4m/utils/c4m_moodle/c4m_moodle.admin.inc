<?php

/**
 * @file
 * C4M Moodle administration functionalities.
 */

/**
 * Form constructor for the form at "admin/config/c4m/moodle".
 *
 * @see c4m_moodle_admin_moodle_configuration_validate()
 *
 * @ingroup forms
 */
function c4m_moodle_admin_moodle_configuration($form, &$form_state) {
  $form['c4m_moodle_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Moodle URL'),
    '#description' => t('The base URL of the Moodle platform.'),
    '#default_value' => variable_get('c4m_moodle_base_url', NULL),
  );

  return system_settings_form($form);
}

/**
 * Form validation handler for c4m_moodle_admin_moodle_configuration().
 */
function c4m_moodle_admin_moodle_configuration_validate($form, &$form_state) {
  if (!valid_url($form_state['values']['c4m_moodle_base_url'], TRUE)) {
    form_set_error('c4m_moodle_base_url', t('Please provide a valid URL.'));
  }
}
