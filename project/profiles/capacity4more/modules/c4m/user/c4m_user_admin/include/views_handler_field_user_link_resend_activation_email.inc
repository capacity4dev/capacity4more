<?php
/**
 * @file
 * Definition of views_handler_field_user_link_resend_activation_email.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to present a link to activate user.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_link_resend_activation_email extends views_handler_field_user_link {

  /**
   * @inheritdoc
   */
  public function render_link($data, $values) {
    $uid = $values->{$this->aliases['uid']};

    $account = user_load($uid);
    $account = entity_metadata_wrapper('user', $account);

    if (!$account->last_login->value() && !$account->status->value() && !$account->c4m_is_spammer->value() && !$account->c4m_is_deleted->value() && user_access('administer users')) {
      $this->options['alter']['make_link'] = TRUE;

      $text = t('Resend activation email');

      $this->options['alter']['path'] = "user/$uid/resend-activation-email";
      $this->options['alter']['query'] = drupal_get_destination();

      return $text;
    }
    return '';
  }

}
