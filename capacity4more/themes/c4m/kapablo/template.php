<?php

/**
 * @file
 * Template functions.
 */

include_once 'theme/css.inc';
include_once 'theme/menu.inc';
include_once 'theme/pager.inc';
include_once 'theme/preprocess.inc';
include_once 'theme/search.inc';

/**
 * Implements hook_preprocess_HOOK().
 *
 * Alter standard drupal message to custom message.
 */
function kapablo_preprocess_status_messages(&$variables) {
  // Messages to change: original message => custom message.
  $custom_messages = array(
    "Field Groups must be populated via URL." => t("You can't create content out of group or you don't have permissions to create content in the current group!"),
  );

  // If status messages exist check each for match with custom messages.
  if (isset($_SESSION['messages'])) {
    // Remove duplicates messages.
    $_SESSION['messages'] = array_unique($_SESSION['messages']);
    // Search for message.
    foreach ($_SESSION['messages'] as $type => $messages) {
      foreach ($custom_messages as $original_message => $custom_message) {
        $pos = array_search($original_message, $messages);
        // If message found delete it and set new.
        if ($pos !== FALSE) {
          unset($_SESSION['messages'][$type][$pos]);
          $_SESSION['messages'][$type][$pos] = $custom_message;
        }
      }
    }
  }
}
