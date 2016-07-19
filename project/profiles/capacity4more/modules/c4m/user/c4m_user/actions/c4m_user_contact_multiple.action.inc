<?php

/**
 * @file
 * Callback & forms related to the user contact multiple.
 */

/**
 * Implements hook_action_info().
 *
 * A custom action to contact a multiple users with a mail action.
 * Declares action for Site Admin, Group Admins and Group Owner.
 */
function c4m_user_contact_multiple_action_info() {
  $group = c4m_og_current_group();
  // If not within OG context, don't declare action.
  if (!$group) {
    return array();
  }
  // If not Site Admin, Group Admin or Group Owner, don't declare action.
  if (!_c4m_features_og_members_is_power_user($group)) {
    return array();
  }

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
 * Action form function.
 *
 * Create 'Contact Multiple' form.
 */
function c4m_user_contact_multiple_action_form(array $context, $form_state) {
  global $user;

  // If 'Select all items on all pages' is selected.
  if ($form_state['select_all_pages']) {
    $group = c4m_og_current_group();
    // Get ids of all active subscribers of current group.
    $uids = og_get_group_members_properties($group, array(), 'members__' . OG_STATE_ACTIVE, 'node');
  }
  else {
    // Get selected items on current page.
    $uids = $form_state['selection'];
  }

  $accounts = user_load_multiple($uids);
  $users_name = array();

  // Create an array of users names for notified subscribers.
  foreach ($accounts as $account) {
    // Make sure that id is valid, and GO/GA didn't select himself.
    if ($account->uid != 0 && $user->uid != $account->uid) {
      $users_name[] = c4m_user_name($account);
    }
  }

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
    '#default_value' => implode(', ', $users_name),
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
 * Action form validate function, for contact_multiple form.
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
 * Action form submit function, for contact_multiple form.
 *
 * Returns required parameters for action, to send the mail.
 * If 'Send copy' checkbox is checked, sends copy mail to invoking user.
 */
function c4m_user_contact_multiple_action_submit($form, $form_state) {
  global $user;
  $silent = TRUE;

  $subject = $form_state['values']['c4m_contact_multiple_subject'];
  $body = $form_state['values']['c4m_contact_multiple_body']['value'];

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
 * Action function for contact_multiple form.
 *
 * Activated for each selected account.
 * Sends email to account.
 */
function c4m_user_contact_multiple_action($account, array $context) {
  if (!isset($account)) {
    return;
  }

  global $user;
  // User should not execute action on himself - has 'Send me a copy' option.
  if ($account->uid == $user->uid) {
    return;
  }

  $subject = $context['subject'];
  $body = $context['body'];
  $from = $context['from'];
  $addressee_language = user_preferred_language($account);
  $silent = TRUE;

  _c4m_user_send_mail($account->mail, $from, $subject, $body, $addressee_language, $silent);
}
