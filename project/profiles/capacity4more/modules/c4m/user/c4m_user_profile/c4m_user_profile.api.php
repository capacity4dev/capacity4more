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
      'message' => t('Message'),
      'type' => C4M_USER_PROFILE_VALIDATION_MESSAGE_TYPE_ERROR,
      '#weight' => 9,
    ),
  );
}
