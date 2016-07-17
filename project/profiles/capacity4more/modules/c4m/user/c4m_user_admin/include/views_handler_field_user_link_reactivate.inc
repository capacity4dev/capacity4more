<?php
/**
 * @file
 * Definition of views_handler_field_user_link_reactivate.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to present a link to reactivate user.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_link_reactivate extends views_handler_field_user_link {

  /**
   * @inheritdoc
   */
  public function render_link($data, $values) {
    $uid = $values->{$this->aliases['uid']};

    $account = user_load($uid);
    $account = entity_metadata_wrapper('user', $account);

    if ($account->last_login->value() > 0 && !$account->status->value() && !$account->c4m_is_spammer->value() && !$account->c4m_is_deleted->value() && user_access('administer users')) {
      $this->options['alter']['make_link'] = TRUE;

      $text = t('Reactivate user');

      $this->options['alter']['path'] = "user/$uid/reactivate";
      $this->options['alter']['query'] = drupal_get_destination();

      return $text;
    }
    return '';
  }

}
