<?php
/**
 * @file
 * Definition of views_handler_field_user_link_mark_spammer.
 */

// @codingStandardsIgnoreFile

/**
 * Field handler to present a link to mark user as spammer.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_link_mark_spammer extends views_handler_field_user_link {

  /**
   * @inheritdoc
   */
  public function render_link($data, $values) {
    $uid = $values->{$this->aliases['uid']};

    $account = user_load($uid);
    $account = entity_metadata_wrapper('user', $account);

    if (!$account->c4m_is_spammer->value() && user_access('administer users')) {
      $this->options['alter']['make_link'] = TRUE;

      $text = t('Mark as spammer');

      $this->options['alter']['path'] = "user/$uid/mark-as-spammer";
      $this->options['alter']['query'] = drupal_get_destination();

      return $text;
    }
    return '';
  }

}
