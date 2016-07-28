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
function c4m_user_profile_remove_account_form($form, $form_state) {
  $account = menu_get_object('user', 1);

  if ($groups = c4m_og_get_user_owned_groups($account->uid, array('group', 'project'))) {
    $items = array();

    foreach ($groups as $nid => $title) {
      $items[] = l($title, 'node/' . $nid);
    }

    $form['warning'] = array(
      '#type' => 'markup',
      '#markup' => '<p>'
        . t('You can\'t leave the platform meanwhile you still own groups and projects. Please, transfer the ownership first.')
        . '</p>'
        . theme('item_list', array('items' => $items)),
    );

    return $form;
  }

  // We emulate the default user deletion form values to use the default process.
  $form['_account'] = array(
    '#type' => 'value',
    '#value' => $account
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
  $account = $form['#account'];

  if ($values['anonymize']) {
    $values['user_cancel_method'] = 'user_cancel_reassign';
  }

  user_cancel($values, $values['uid'], $values['user_cancel_method']);

  $form_state['redirect'] = '/';
}
