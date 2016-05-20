<?php
/**
 * @file
 * Hooks provided by the c4m_user_profile module.
 */

/**
 * Validates an email address.
 *
 * @param string $mail
 *   Email address.
 *
 * @return array
 *   An array of error messages array. Error have the #weight key.
 */
function hook_c4m_user_profile_validate_email($mail, $form_state, $form) {
  return array(
    array(
      'message' => t('Error message'),
      '#weight' => 9,
    ),
  );
}

/**
 * Validates an email address only on AJAX calls.
 *
 * @param string $mail
 *   Email address.
 *
 * @return array
 *   An array of messages array. Error have the #weight key.
 */
function hook_c4m_user_profile_validate_email_ajax($mail, $form_state, $form) {
  return array(
    array(
      'message' => t('Message'),
      '#weight' => 9,
    ),
  );
}
