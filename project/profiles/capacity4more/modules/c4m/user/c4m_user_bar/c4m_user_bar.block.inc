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

  $links = array(
    l(t('Sign up'), 'user/register', array('attributes' => array('class' => array('text-small', 'text-orange')))),
    l(t('Log in'), 'user/login', array('attributes' => array('class' => array('text-small', 'text-blue')))),
  );

  $output = array(
    '#theme'      => 'item_list',
    '#items'      => $links,
    '#attributes' => array(
      'class' => array(
        'pull-right'
      ),
    ),
  );

  $block['content'] = render($output);
  return $block;
}