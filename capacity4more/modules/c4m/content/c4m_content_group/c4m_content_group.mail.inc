<?php
/**
 * @file
 * Functionality to send mail messages.
 */

/**
 * Helper to load the mail text from the variable.
 *
 * @param string $key
 *   The message key.
 * @param object $language
 *   The language object.
 * @param array $variables
 *   The text variables.
 *
 * @return string
 */
function _c4m_content_group_mail_text($key, $language, $variables) {
  // Try to load the text first from variable.
  $text = variable_get($key, NULL);
  if ($text) {
    return $text;
  }

  // Load default text.
  return _c4m_content_group_mail_text_default($key, $language, $variables);
}

/**
 * Helper to load the default message texts.
 *
 * @param string $key
 *   The message key.
 * @param object $language
 *   The language object.
 * @param array $variables
 *   The text variables.
 *
 * @return string
 */
function _c4m_content_group_mail_text_default($key, $language, $variables) {
  $options = array();
  if (!empty($language->langcode)) {
    $options['langcode'] = $language->langcode;
  }
  $text = NULL;

  switch ($key) {
    case 'group_pending_approval_admin_subject':
      $text = t('Group request', $variables, $options);
      break;

    case 'group_pending_approval_admin_body':
      $text = t('Hello,

A new request from user: @group_owner for a group titled "@group_title" has been created (@group_dashboard_url).',
        $variables,
        $options
      );
      break;

    case 'group_rejected_user_subject':
      $text = t('Your group was rejected', $variables, $options);
      break;

    case 'group_rejected_user_body':
      $text = t('Hello @group_owner,

Your group titled "@group_title" has been rejected.',
        $variables,
        $options
      );
      break;

    case 'group_approved_user_subject':
      $text = t('Your group was approved', $variables, $options);
      break;

    case 'group_approved_user_body':
      $text = t('Hello @group_owner,

Your group titled "@group_title" has been approved (@group_dashboard_url).',
        $variables,
        $options);
      break;
  }

  return $text;
}
