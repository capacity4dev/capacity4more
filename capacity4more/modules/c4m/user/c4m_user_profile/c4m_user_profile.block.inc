<?php
/**
 * @file Block definitions for the user profile.
 */

/**
 * Block definition for the top bar (user region).
 * Welcomes the user by name + sub-menu or CTA to login.
 */
function _c4m_user_profile_block_user_welcome() {
  $block            = array();
  $block['subject'] = '';

  if (user_is_anonymous()) {
    $block['content'] =
      t('Welcome.') . ' ' .
      t('Please <a href="@register">register</a> or <a href="@login">login.</a>',
        array(
          '@register' => url('user/register'),
          '@login'    => url('user/login'),
        ));
    return $block;
  }

  global $user;

  // @TODO: submenu, theming function, real name...
  $block['content'] = t('Hello @user', array('@user' => $user->name));

  return $block;
}

/**
 * Block definition for the top bar (user region).
 * Displays number of messages/notifications/...
 */
function _c4m_user_profile_block_user_notifications() {
  $block            = array();
  $block['subject'] = '';

  if (user_is_anonymous()) {
    return;
  }

  // @TODO: submenu, theming function...
  $block['content'] = t('# of messages/notifications/...');

  return $block;
}