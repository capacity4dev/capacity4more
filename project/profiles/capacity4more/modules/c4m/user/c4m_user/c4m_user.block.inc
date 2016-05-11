<?php
/**
 * @file
 * Code for the user blocks.
 */

/**
 * Callback for the c4m_block_contact_members block.
 */
function _c4m_user_block_c4m_block_contact_members() {
  global $user;

  if ($user->uid) {
    return NULL;
  }

  $markup = t('!register or !login to contact a member', array(
    '!register' => l(t('Register'), 'user/register'),
    '!login' => l(t('log in'), 'user/login', array(
      'query' => drupal_get_destination(),
    )),
  ));

  return array(
    'subject' => '',
    'content' => $markup,
  );
}
