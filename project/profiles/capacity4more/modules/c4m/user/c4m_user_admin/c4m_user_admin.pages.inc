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
 * Page callback for user report page.
 */
function _c4m_user_admin_page_user_report() {
  $date = _c4m_user_admin_get_user_report_last_generated_date();

  $content[] = array(
    '#markup' => t('<p>User report was last generated: @date.</p>', array('@date' => $date ? $date : t('Never'))),
  );
  if ($date) {
    $view = views_get_view('c4m_admin_users');
    if ($view) {
      if ($file_path = $view->display['views_data_export']->display_options['style_options']['file_path']) {
        $content[] = array(
          '#markup' => l(t('Download report'), file_create_url($file_path), array(
            'attributes' => array('id' => 'edit-cancel'),
          )),
        );
      }
    }
  }

  $content[] = array(
    '#markup' => l(t('Generate report'), 'admin/people/export/file', array(
      'attributes' => array('class' => array('button')),
    )),
  );
  return $content;
}

/**
 * Returns the time & date when the user report was last generated.
 *
 * @return string
 *   Date & time.
 */
function _c4m_user_admin_get_user_report_last_generated_date() {
  $timestamp = db_query("SELECT time_stamp FROM views_data_export WHERE view_name = 'c4m_admin_users' AND view_display_id = 'views_data_export' ORDER BY time_stamp DESC LIMIT 0, 1")->fetchCol();
  if (!$timestamp) {
    return '';
  }
  else {
    return date('Y-m-d H:i', $timestamp[0]);
  }
}
