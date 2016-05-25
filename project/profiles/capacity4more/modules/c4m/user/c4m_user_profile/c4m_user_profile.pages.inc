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
