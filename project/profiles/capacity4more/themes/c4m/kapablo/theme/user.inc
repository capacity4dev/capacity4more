<?php

/**
 * @file
 * Theme functions related to the users.
 */

/**
 * Implements hook_legal_accept_label().
 */
function kapablo_legal_accept_label($variables) {
  if ($variables['link']) {
    $text = t('Check this to indicate that you have read and agreed to the "<a href="@terms" target="_blank">terms and conditions</a>" of this site', array('@terms' => url('conditions')));
  }
  else {
    $text = t('Check this to indicate that you have read and agreed to the "terms and conditions" of this site');
  }
  return $text;
}
