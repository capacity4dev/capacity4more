<?php
/**
 * @file
 * Callback & forms related to the user admin.
 */

/**
 * Custom actions defined by c4m_user_admin module.
 *
 * @return array
 *   Information about the action.
 */
function _c4m_user_admin_action_info() {
  return array(
    'c4m_user_admin_activate_action' => array(
      'type' => 'user',
      'label' => t('Activate user'),
      'configurable' => FALSE,
      'triggers' => array('any'),
    ),
    'c4m_user_resend_activation_email_action' => array(
      'type' => 'user',
      'label' => t('Resend activation email'),
      'configurable' => FALSE,
      'triggers' => array('any'),
    ),
    'c4m_user_admin_mark_spammer_action' => array(
      'type' => 'user',
      'label' => t('Mark as spammer'),
      'configurable' => TRUE,
      'triggers' => array('any'),
    ),
  );
}

/**
 * Performs the 'activate user' action.
 *
 * @param object $user
 *   The user object.
 */
function c4m_user_admin_activate_action($user) {
  $edit['status'] = 1;
  $edit['c4m_is_spammer'] = 0;
  $edit['c4m_is_deleted'] = 0;
  user_save($user, $edit);
}

/**
 * Performs the 'resend activation email' action.
 *
 * @param object $account
 *   The user object.
 */
function c4m_user_admin_resend_activation_email_action($account) {
  $account_wrapper = entity_metadata_wrapper('user', $account);
  if (!$account_wrapper->status->value() && !$account_wrapper->c4m_is_spammer->value() && !$account_wrapper->c4m_is_deleted->value()) {
    $params['account'] = $account;
    drupal_mail('user_registrationpassword', 'register', $account->mail, user_preferred_language($account), $params);
  }
  else {
    drupal_set_message(t('Account of @first_name @last_name is either active or deleted or marked as spammer.', array(
      '@first_name' => $account_wrapper->c4m_first_name->value(),
      '@last_name' => $account_wrapper->c4m_last_name->value(),
    )));
  }
}

/**
 * Performs the 'mark as spammer' action.
 *
 * @param object $account
 *   The user object.
 * @param array $context
 *   The form context.
 */
function c4m_user_admin_mark_spammer_action($account, array $context) {
  if ($account->c4m_is_spammer[LANGUAGE_NONE][0]['value'] == 1) {
    return;
  }

  switch ($context['method']) {
    case 'delete':
      node_user_delete($account);
      comment_user_delete($account);
      break;

    case 'reassign':
      node_user_cancel(NULL, $account, 'user_cancel_reassign');
      comment_user_cancel(NULL, $account, 'user_cancel_reassign');
      break;
  }

  $edit['c4m_is_spammer'][LANGUAGE_NONE][0]['value'] = 1;
  user_save($account, $edit);

  $account_wrapper = entity_metadata_wrapper('user', $account);
  drupal_set_message(t('Account of @first_name @last_name was marked as spammer.', array(
    '@first_name' => $account_wrapper->c4m_first_name->value(),
    '@last_name' => $account_wrapper->c4m_last_name->value(),
  )));
}

/**
 * Form for the custom 'contact user' action.
 *
 * @param array $context
 *    Form context.
 *
 * @return array
 *    The form.
 */
function c4m_user_admin_mark_spammer_action_form(array $context) {
  $form = array();
  c4m_user_admin_mark_spammer_form_add_options($form);
  return $form;
}

/**
 * Submission of the custom 'mark as spammer' form.
 *
 * @param array $form
 *   The form that is submitted.
 * @param array $form_state
 *   The form state data.
 *
 * @return array
 *   The message details.
 */
function c4m_user_admin_mark_spammer_action_submit(array $form, array $form_state) {
  return array(
    'method' => $form_state['values']['method'],
  );
}
