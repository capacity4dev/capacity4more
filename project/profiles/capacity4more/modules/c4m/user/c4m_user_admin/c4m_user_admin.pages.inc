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
