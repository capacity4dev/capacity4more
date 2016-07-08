<?php

/**
 * @file
 * Hooks provided by the c4m_user_profile module.
 */

/**
 * Validates an email address.
 *
 * @param array $data
 *   Contains context information like:
 *   - email;
 *   - minimum_error_level;
 *   - form;
 *   - form_state;
 *   - alter_form;
 *   - validation_messages.
 */
function hook_c4m_user_profile_validate_email_alter(&$data) {
  $data['validation_messages'][] = array(
    'message' => t('The e-mail address %mail is not valid.', array('%mail' => $data['mail'])),
    'type' => C4M_USER_PROFILE_VALIDATION_MESSAGE_TYPE_ERROR,
    '#weight' => -6,
  );
}
