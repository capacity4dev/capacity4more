<?php
/**
 * @file
 * c4m_user_admin.pages.inc
 */

/**
 * Form constructor for the activate user form.
 *
 * @see c4m_user_admin_user_activate_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_admin_user_activate_form($form, &$form_state, $account) {
  $form_state['user'] = $account;

  $account = entity_metadata_wrapper('user', $account);
  $question = t('Are you sure you want to activate the account of @first_name @last_name?', array(
    '@first_name' => $account->c4m_first_name->value(),
    '@last_name' => $account->c4m_last_name->value(),
  ));
  return confirm_form($form,
    $question,
    '',
    '',
    t('Activate account'), t('Cancel'));
}

/**
 * Form submission handler for c4m_user_admin_user_activate_form().
 *
 * @see c4m_user_admin_user_activate_form()
 */
function c4m_user_admin_user_activate_form_submit($form, &$form_state) {
  $account = $form_state['user'];
  module_load_include('inc', 'c4m_user_admin', 'actions/c4m_user_admin.action');
  c4m_user_admin_activate_action($account);
}

/**
 * Form constructor for the resend activation email form.
 *
 * @see c4m_user_admin_resend_activation_email_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_admin_resend_activation_email_form($form, &$form_state, $account) {
  $form_state['user'] = $account;

  $account = entity_metadata_wrapper('user', $account);
  $question = t('Are you sure you want to resend activation email for @first_name @last_name?', array(
    '@first_name' => $account->c4m_first_name->value(),
    '@last_name' => $account->c4m_last_name->value(),
  ));
  return confirm_form($form,
    $question,
    '',
    '',
    t('Resend activation email'), t('Cancel'));
}

/**
 * Form submission handler for c4m_user_admin_resend_activation_email_form().
 *
 * @see c4m_user_admin_resend_activation_email_form()
 */
function c4m_user_admin_resend_activation_email_form_submit($form, &$form_state) {
  $account = $form_state['user'];
  module_load_include('inc', 'c4m_user_admin', 'actions/c4m_user_admin.action');
  c4m_user_admin_resend_activation_email_action($account);
}

/**
 * Form constructor for the mark spammer form.
 *
 * @see c4m_user_admin_mark_spammer_form_submit()
 *
 * @ingroup forms
 */
function c4m_user_admin_mark_spammer_form($form, &$form_state, $account) {
  $form_state['user'] = $account;

  c4m_user_admin_mark_spammer_form_add_options($form);

  $account = entity_metadata_wrapper('user', $account);
  $question = t('Are you sure you want to mark @first_name @last_name as spammer?', array(
    '@first_name' => $account->c4m_first_name->value(),
    '@last_name' => $account->c4m_last_name->value(),
  ));
  return confirm_form($form,
    $question,
    '',
    '',
    t('Mark as spammer'), t('Cancel'));
}

/**
 * Form submission handler for c4m_user_admin_resend_activation_email_form().
 *
 * @see c4m_user_admin_mark_spammer_form()
 */
function c4m_user_admin_mark_spammer_form_submit($form, &$form_state) {
  $account = $form_state['user'];
  $method = $form_state['values']['method'];
  module_load_include('inc', 'c4m_user_admin', 'actions/c4m_user_admin.action');
  c4m_user_admin_mark_spammer_action($account, array('method' => $method));
}
