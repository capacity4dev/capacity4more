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

  if (user_is_anonymous()) {
    $text = t('<strong>!login</strong> or <strong>!register</strong>', array(
      '!login' => l(t('Log in'), 'user/login', array(
        'attributes' => array('class' => array('text-link--blue')),
        'query' => drupal_get_destination(),
      )),
      '!register' => l(t('Register'), 'user/register', array('attributes' => array('class' => array('text-link--cta')))),
    ));
  }
  else {
    $text = l(t('Log out'), 'user/logout', array('attributes' => array('class' => array('text-link--blue'))));
  }

  $output = array(
    '#type'      => 'container',
    'links' => array(
      '#markup' => $text,
    ),
    '#attributes' => array(
      'class' => array(
        'text-small',
      ),
    ),
  );

  $block['content'] = render($output);
  return $block;
}
