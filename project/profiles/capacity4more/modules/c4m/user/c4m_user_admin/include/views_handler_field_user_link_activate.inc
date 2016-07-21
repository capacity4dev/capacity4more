<?php
/**
 * @file
 * Definition of views_handler_field_user_link_activate.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to present a link to activate user.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_link_activate extends views_handler_field_user_link {

  /**
   * @inheritdoc
   */
  public function render_link($data, $values) {
    $uid = $values->{$this->aliases['uid']};

    $account = user_load($uid);
    $account = entity_metadata_wrapper('user', $account);

    // Verifying user has not logged in, which means that account
    // was not activated. Link offers an option to 'Activate'.
    // No need to check c4m_is_deleted, because it's tightly coupled with status.
    if (!$account->last_login->value() && !$account->status->value() && !$account->c4m_is_spammer->value() && $account->c4m_is_deleted->value() && user_access('administer users')) {
      $this->options['alter']['make_link'] = TRUE;

      $text = t('Activate user');

      $this->options['alter']['path'] = "user/$uid/activate";
      $this->options['alter']['query'] = drupal_get_destination();

      return $text;
    }
    return '';
  }

}
