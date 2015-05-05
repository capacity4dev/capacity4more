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
 * Implements hook_preprocess_status_messages().
 *
 * Alter standard drupal message to custom message.
 */
function kapablo_preprocess_status_messages(&$variables) {
  // Messages to change: original message => custom message.
  $custom_messages = array(
    "Field Groups must be populated via URL." => t("You can't create content out of group or you don't have permissions to create content in the current group!"),
  );

  $set_messages = drupal_get_messages($variables['display'], FALSE);

  foreach ($set_messages as $type => $messages) {
    foreach ($custom_messages as $original_message => $custom_message) {
      $pos = array_search($original_message, $messages);
      if ($pos !== FALSE) {
        unset($_SESSION['messages'][$type][$pos]);
        $_SESSION['messages'][$type][$pos] = $custom_message;
      }
    }
  }
}
