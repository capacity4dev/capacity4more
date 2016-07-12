<?php

/**
 * @file
 * Callback & forms related to the user contact multiple.
 */

/**
 * A custom action to contact a multiple users with a mail.
 *
 * @return array
 *   Information about the action.
 */
function c4m_user_contact_multiple_action_info() {
  return array(
    'c4m_user_contact_multiple_action' => array(
      'type' => 'user',
      'label' => t('Contact'),
      'configurable' => TRUE,
      'triggers' => array('any'),
    ),
  );
}

/**
 * Create 'Contact Multiple' form.
 */
function c4m_user_contact_multiple_action_form(array $context, $form_state) {
  global $user;
  $to_list = '';

  foreach ($form_state['selection'] as $user_id) {
    if ($user_id != 0) {
      $account = user_load($user_id);
      $to_list .= c4m_user_name($account) . ', ';
    }
  }
  $to_list = rtrim($to_list, ", ");

  $form['c4m_contact_multiple_from'] = array(
    '#type' => 'textfield',
    '#title' => t('From'),
    '#description' => t('From address.'),
    '#size' => 30,
    '#default_value' => $user->mail,
    '#disabled' => TRUE,
  );

  $form['c4m_contact_multiple_to'] = array(
    '#type' => 'textarea',
    '#title' => t('To'),
    '#default_value' => $to_list,
    '#description' => t('Group members that will receive the email.'),
    '#rows' => 3,
    '#disabled' => TRUE,
  );

  $form['c4m_contact_multiple_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Enter mail subject.'),
    '#size' => 10,
  );

  $form['c4m_contact_multiple_body'] = array(
    '#title' => t('Body'),
    '#description' => t('Enter mail body.'),
    '#type' => 'text_format',
    '#format' => 'filtered_html',
  );

  $form['c4m_contact_multiple_self_copy'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send me a copy'),
    '#default_value' => FALSE,
  );

  return $form;
}

/**
 * Validate function for contact_multiple_form.
 *
 * Verifies that email subject and body are not empty.
 */
function c4m_user_contact_multiple_action_validate($form, $form_state) {
  $subject = $form_state['values']['c4m_contact_multiple_subject'];
  $body = $form_state['values']['c4m_contact_multiple_body']['value'];

  if (empty($subject)) {
    form_error($form['c4m_contact_multiple_subject'], 'The subject of the mail can\'t be empty.');
  }

  if (empty($body)) {
    form_error($form['c4m_contact_multiple_body'], 'The body of the mail can\'t be empty.');
  }
}

/**
 * Submit function for contact_multiple_form.
 *
 * Returns required parameters for action, to send the mail.
 * If 'Send copy' checkbox is checked, sends copy mail to running user.
 */
function c4m_user_contact_multiple_action_submit($form, $form_state) {
  global $user;
  $silent = TRUE;
 // $count_members = 0;

  $subject = $form_state['values']['c4m_contact_multiple_subject'];
  $body = $form_state['values']['c4m_contact_multiple_body']['value'];

/*  $ids = explode('|', $form_state['values']['hidden_ids']);

  foreach ($ids as $user_id){
    $addressee_account = user_load($user_id);
    $addressee_language = user_preferred_language($addressee_account);
    if (!isset($addressee_account->uid)) {
      continue;
    }

    _c4m_user_send_mail($addressee_account->mail, $user->mail, $subject, $body, $addressee_language, $silent);
    $count_members += 1;
  }
  drupal_set_message('Message sent to ' . $count_members . ' members.');*/

  if ($form_state['values']['c4m_contact_multiple_self_copy']) {
    // Sending a copy of the mail to the sender since the user checked
    // the "Send me a copy" checkbox on the form.
    $user_language = user_preferred_language($user);
    _c4m_user_send_mail($user->mail, $user->mail, "Self copy: {$subject}", $body, $user_language, $silent);
    drupal_set_message('Copy message sent.');
  }

  return array(
    'subject' => $subject,
    'body' => $body,
    'from' => $user->mail,
  );
}

/**
 * Action function for contact_multiple_form.
 *
 * Activated for each selected user.
 * Sends email to user.
 */
function c4m_user_contact_multiple_action(&$user, array $context) {
  if (!isset($user)) {
    return;
  }

  $subject = $context['subject'];
  $body = $context['body'];
  $from = $context['from'];
  $addressee_language = user_preferred_language($user);
  $silent = TRUE;

  _c4m_user_send_mail($user->mail, $from, $subject, $body, $addressee_language, $silent);
}

