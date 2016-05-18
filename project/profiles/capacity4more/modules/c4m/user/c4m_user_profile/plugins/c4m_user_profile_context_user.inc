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
    return $values;
  }

  function execute($account) {
    $account = user_load($account->uid);
    $value = !empty($account->c4m_is_invalid_email[LANGUAGE_NONE][0]['value']) ? 'is_invalid_email' : 0;
    foreach ($this->get_contexts($value) as $context) {
      $this->condition_met($context, $value);
    }
  }
}
