<?php

/**
 * @file
 * Views argument plugin.
 */

// @codingStandardsIgnoreFile

/**
 * The global activity stream argument default handler.
 *
 * To allow filtering the content of the global activity stream by the user's
 * interests, we need to pass the relevant IDs.
 */
class c4m_message_plugin_argument_default extends views_plugin_argument_default {

  /**
   * Return the node IDs of the user's interests.
   *
   * @return string
   *   A `+` separated list of node IDs of the user's interests.
   */
  public function get_argument() {
    $filterBy = filter_input(INPUT_GET, 'filter', FILTER_SANITIZE_STRING);

    if ($filterBy == 'interests') {
      global $user;
      $account = user_load($user->uid);
      $user_wrapper = entity_metadata_wrapper('user', $account->uid);
      $interests = $user_wrapper->c4m_vocab_topic->raw();
      $interests = implode('+', $interests);
    }
    else {
      $interests = 'all';
    }

    return $interests;
  }
}
