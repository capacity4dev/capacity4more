<?php
/**
 * @file
 * Definition of c4m_user_profile_context_user class.
 */

// @codingStandardsIgnoreFile

class c4m_user_profile_context_user extends context_condition {

  function condition_values() {
    $values = array();
    $values['is_invalid_email'] = 'Is invalid email';
    $values['confirm_email'] = 'Email to be confirmed';
    return $values;
  }

  function execute($account) {
    $account = user_load($account->uid);
    $values[] = !empty($account->data['email_confirm']) && $account->data['email_confirm']['expiration_time'] > REQUEST_TIME ? 'confirm_email' : 0;
    $values[] = !empty($account->c4m_is_invalid_email[LANGUAGE_NONE][0]['value']) ? 'is_invalid_email' : 0;

    foreach ($values as $value) {
      foreach ($this->get_contexts($value) as $context) {
        $this->condition_met($context, $value);
      }
    }
  }
}
