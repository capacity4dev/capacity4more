<?php

/**
 * @file
 * c4m_user_profile.pages.inc
 */

/**
 * Form constructor for the resend email change confirmation email form.
 *
 * @see c4m_user_profile_resend_email_change_confirmation_email_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_profile_resend_email_change_confirmation_email_form($form, &$form_state) {
  $question = t('Resend email change confirmation');
  return confirm_form($form,
    $question,
    'user',
    t('<p>Are you sure you want to resend the email change confirmation?</p>'),
    t('Send'), t('Cancel'));
}

/**
 * Form validation handler for the resend email change confirmation email form.
 *
 * @see c4m_user_profile_resend_email_change_confirmation_email_form()
 */
function c4m_user_profile_resend_email_change_confirmation_email_form_validate($form, &$form_state) {
  global $user;

  if (!isset($user->data['email_confirm']) || !isset($user->data['email_confirm']['pending_email']) || $user->data['email_confirm']['expiration_time'] <= REQUEST_TIME) {
    form_set_error(NULL, t('You no longer require to validate your new email address.'));
  }
}

/**
 * Form submission handler for the resend email change confirmation email form.
 *
 * @see c4m_user_profile_resend_email_change_confirmation_email_form()
 */
function c4m_user_profile_resend_email_change_confirmation_email_form_submit($form, &$form_state) {
  global $user;
  $account = user_load($user->uid);
  email_confirm_build_mail(array('mail' => $account->data['email_confirm']['pending_email']), $account);
  $form_state['redirect'] = 'user';
}

/**
 * Form constructor for the remove account confirmation form.
 *
 * @see c4m_user_profile_remove_account_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_profile_remove_account_form($form, $form_state, $account) {
  // We emulate the default user deletion form values to use
  // the default process.
  $form['_account'] = array(
    '#type' => 'value',
    '#value' => $account,
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $account->uid,
  );

  $form['user_cancel_confirm'] = array(
    '#type' => 'value',
    '#value' => FALSE,
  );

  $form['user_cancel_notify'] = array(
    '#type' => 'value',
    '#value' => FALSE,
  );

  $form['user_cancel_method'] = array(
    '#type' => 'value',
    // This method will block the user but leave the content
    // assigned to the user.
    '#value' => 'user_cancel_block',
  );

  $form['anonymize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do you want to anonymize your content?'),
  );

  $form['feedback'] = array(
    '#type' => 'textarea',
    '#title' => t('Provide a reason (optional)'),
  );

  $question = t('Are you sure you want to leave the platform? This action is irreversible');

  return confirm_form($form, $question, 'user');
}

/**
 * Form submission handler for the remove account confirmation form.
 *
 * @see c4m_user_profile_remove_account_form()
 */
function c4m_user_profile_remove_account_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  if ($values['anonymize']) {
    // This cancel method will reassign all the content of the user
    // to the anonymous user.
    $values['user_cancel_method'] = 'user_cancel_reassign';
  }

  // This calls the default Drupal workflow for cancelling an account.
  user_cancel($values, $values['uid'], $values['user_cancel_method']);

  // As the user no longer exists, it doesn't have access to the
  // current page (user profile). So we redirect it to the homepage.
  $form_state['redirect'] = '<front>';
}

/**
 * Implements hook_menu_local_tasks_alter().
 */
function c4m_user_profile_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  dpm($router_item);
}

/**
 * Menu callback function.
 */
function c4m_user_profile_my_contact_view() {
  global $user;

  $view = views_get_view('my_content');
  $view->set_display('page');
  $view->set_arguments(array(9));
  $view->pre_execute();
  $view->execute('page');
  $output = $view->render('page');

  return $output;
}
