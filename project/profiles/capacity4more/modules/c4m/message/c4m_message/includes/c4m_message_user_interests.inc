<?php

/**
 * @file
 * Views argument plugin.
 */

// @codingStandardsIgnoreFile

/**
 * Handlers returns the current user's interests (topics) to the views filter.
 *
 * To allow filtering the content of the activity streams by the user's
 * interests, we need to pass the topic IDs.
 */
class c4m_message_user_interests extends views_plugin_argument_default {

  /**
   * Return the term IDs of the user's interests.
   *
   * @return string
   *   A `+` separated list of node IDs of the user's interests.
   */
  public function get_argument() {
    $filter_by = filter_input(INPUT_GET, 'filter', FILTER_SANITIZE_STRING);

    if ($filter_by == 'interests') {
      // Convert the interest IDs array to a string formatted for the view's
      // contextual filter (1+2+3 for `OR`).
      $interests = implode('+', c4m_user_profile_get_interests());
    }
    else {
      $interests = 'all';
    }

    return $interests;
  }
}
