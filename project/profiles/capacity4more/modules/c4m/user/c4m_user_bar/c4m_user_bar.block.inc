<?php
/**
 * @file
 * Block definitions for the user bar.
 */

/**
 * Block definition for the top bar (user region).
 *
 * Displays link to sign up or log in.
 *
 * @return array
 *   The block definition.
 */
function _c4m_user_bar_block_user_signup_login() {
  $block = array();
  $block['subject'] = '';

  if (!user_is_anonymous()) {
    return array();
  }

  $text = t(
    '<span class="userBar-register">!register</span><span class="userBar-login">!login</span>',
    array(
      '!login' => l(
        t('Log in'),
        'user/login',
        array(
          'attributes' => array('class' => array('text-link--blue', 'text-small')),
          'query' => drupal_get_destination(),
        )
      ),
      '!register' => l(
        t('Sign up'),
        'user/register',
        array('attributes' => array('class' => array('text-link--cta', 'text-small')))
      ),
    )
  );

  $output = array(
    'links' => array(
      '#markup' => $text
    )
  );

  $block['content'] = render($output);
  return $block;
}
