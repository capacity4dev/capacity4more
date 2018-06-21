<?php

/**
 * @file
 * Admin forms.
 */

/**
 * Form constructor for the c4m_user_admin_email_domain_organisation_test form.
 *
 * @see c4m_user_admin_email_domain_organisation_test_validate()
 * @see c4m_user_admin_email_domain_organisation_test_submit()
 *
 * @ingroup forms
 */
function c4m_user_admin_email_domain_organisation_test($form, &$form_state) {
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address'),
    '#description' => t('Enter the email address to be tested.'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Test'));

  return $form;
}

/**
 * Form validation handler for c4m_user_admin_email_domain_organisation_test().
 *
 * @see c4m_user_admin_email_domain_organisation_test_submit()
 */
function c4m_user_admin_email_domain_organisation_test_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('Please provide a valid email address.'));
  }
}

/**
 * Form submission handler for c4m_user_admin_email_domain_organisation_test().
 *
 * @see c4m_user_admin_email_domain_organisation_test_validate()
 */
function c4m_user_admin_email_domain_organisation_test_submit($form, &$form_state) {
  // Rebuild the form in order to keep filter values.
  $form_state['rebuild'] = TRUE;
  $email = $form_state['values']['email'];

  $user = new C4mOrganisationUser($email);

  $organisations = $user->getOrganisationsInfo();
  $info[] = t('Has Organisation: @has_organisation', array(
    '@has_organisation' => !empty($organisations) ? 'Yes' : 'No',
  ));

  $info_message = array();
  foreach ($organisations as $id => $organisation) {
    $info_message[] = l($organisation->title, 'node/' . $organisation->nid);
  }
  $info[] = t('Organisations: !organisations.', array(
    '!organisations' => !empty($info_message) ? implode(', ', $info_message) : 'No',
  ));

  $branding_organisations = $user->getBrandingOrganisationsInfo();
  $info_message = array();
  foreach ($branding_organisations as $id => $organisation) {
    $info_message[] = l($organisation->title, 'node/' . $organisation->nid);
  }
  $info[] = t('Branding organisations: !organisations.', array(
    '!organisations' => !empty($info_message) ? implode(', ', $info_message) : 'No',
  ));

  drupal_set_message(t('<p>Organisation information for @email<br />!info</p>', array(
    '@email' => $email,
    '!info' => implode('<br />', $info),
  )));
}
