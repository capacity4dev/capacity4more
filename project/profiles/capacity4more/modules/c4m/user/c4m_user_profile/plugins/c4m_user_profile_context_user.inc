<?php
/**
 * @file
 * Definition of c4m_user_profile_context_user class.
 */

// @codingStandardsIgnoreFile

class c4m_user_profile_context_user extends context_condition {

  function condition_values() {
    $values = array();
    $values['confirm_email'] = 'Email to be confirmed';
    return $values;
  }

  function execute($account) {
    $account = user_load($account->uid);
    $value = !empty($account->data['email_confirm']) && $account->data['email_confirm']['expiration_time'] > REQUEST_TIME ? 'confirm_email' : 0;
    foreach ($this->get_contexts($value) as $context) {
      $this->condition_met($context, $value);
    }
  }
}
