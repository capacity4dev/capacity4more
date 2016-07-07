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
 *   The mail text.
 */
function _c4m_content_group_mail_text($key, $language, array $variables) {
  // Try to load the text first from variable.
  $text = variable_get($key, NULL);

  // Fallback to default text.
  if (empty($text)) {
    $text = _c4m_content_group_mail_text_default($key, $language);
  }

  // Replace variables & tokens.
  return token_replace(
    $text,
    $variables,
    array(
      'language' => $language,
      'callback' => 'c4m_content_group_mail_tokens',
      'sanitize' => FALSE,
      'clear' => TRUE,
    )
  );
}

/**
 * Helper to load the default message texts.
 *
 * @param string $key
 *   The message key.
 * @param object $language
 *   The language object.
 *
 * @return string
 *   The text to use in the outgoing email.
 */
function _c4m_content_group_mail_text_default($key, $language) {
  $options = array();
  if (!empty($language->langcode)) {
    $options['langcode'] = $language->langcode;
  }
  $text = NULL;

  switch ($key) {
    case 'group_pending_approval_admin_subject':
      $text = t('Group request', array(), $options);
      break;

    case 'group_pending_approval_admin_body':
      $text = t('Hello,

A new request from user: [group:owner] for a group titled "[group:title]" has been created ([group:dashboard_url]).',
        array(),
        $options
      );
      break;

    case 'group_rejected_user_subject':
      $text = t('Your group was rejected', array(), $options);
      break;

    case 'group_rejected_user_body':
      $text = t('Hello [group:owner],

Your group titled "[group:title]" has been rejected.',
        array(),
        $options
      );
      break;

    case 'group_approved_user_subject':
      $text = t('Your group was approved', array(), $options);
      break;

    case 'group_approved_user_body':
      $text = t('Hello [group:owner],

Your group titled "[group:title]" has been approved ([group:dashboard_url]).',
        array(),
        $options);
      break;
  }

  return $text;
}
