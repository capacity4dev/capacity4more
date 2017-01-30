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
    '!login' => l(t('log in'), 'user', array(
      'query' => drupal_get_destination(),
    )),
  ));

  return array(
    'subject' => '',
    'content' => $markup,
  );
}

/**
 * Callback for the c4m_my_comments_link block.
 */
function _c4m_user_block_c4m_my_comments_link() {
  global $user;

  $count_user_comments = c4m_user_count_comments($user->uid, FALSE);
  $link = l(t('My comments (@count)', array('@count' => $count_user_comments)), "user/$user->uid/comments");

  return array(
    'subject' => '',
    'content' => $link,
  );
}

/**
 * Callback for the c4m_back_to_my_content_link block.
 */
function _c4m_user_block_c4m_back_to_my_content_link() {
  global $user;

  $link = l(t('Back to my content'), "user/$user->uid/content");

  return array(
    'subject' => '',
    'content' => $link,
  );
}
