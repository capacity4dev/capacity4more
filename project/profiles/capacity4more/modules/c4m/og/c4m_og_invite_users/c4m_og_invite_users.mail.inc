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
 * @param array $variables
 *   The text variables.
 *
 * @return string
 *   The mail text.
 */
function _c4m_og_invite_users_mail_text($key, array $variables) {
  global $language;

  // Try to load the text first from variable.
  $text = variable_get($key, NULL);

  // Replace variables & tokens.
  $group = og_context();
  $variables['group'] = node_load($group['gid']);
  return token_replace($text, $variables, array(
    'language' => $language,
    'callback' => 'c4m_og_invite_users_mail_tokens',
    'sanitize' => FALSE,
    'clear' => TRUE,
  )
  );
}
