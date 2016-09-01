<?php

/**
 * @file
 *  Page callbacs and related functions for all the contact functionality.
 */

/**
* Form callback for the admin page for configuring contact mail addresses.
 */
function c4m_contact_email_address_form($form, &$form_state) {
  $mail = variable_get('site_mail');

  $form['c4m_contact_email_addresses'] = array(
    '#title' => t('E-mail addresses'),
    '#type' => 'textarea',
    '#description' => t('Multiple addresses allowed. Add them separated by commas.'),
    '#default_value' => variable_get('c4m_contact_email_addresses', $mail),
  );

  return system_settings_form($form);
}

/**
 * Form validation callback for c4m_contact_email_address_form.
 */
function c4m_contact_email_address_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $mails = explode(',', $values['c4m_contact_email_addresses']);

  $errors = '';
  foreach ($mails as $mail) {
    if (!valid_email_address(trim($mail))) {
      $errors .= (!empty($errors)) ? ', ' . $mail : $mail;
    }
  }

  if (!empty($errors)) {
    $error_message = t('The next e-mails present errors: @mails. Each mail should be separated by a comma.', array('@mails' => $errors));
    form_set_error('c4m_contact_email_addresses', $error_message);
  }
}
