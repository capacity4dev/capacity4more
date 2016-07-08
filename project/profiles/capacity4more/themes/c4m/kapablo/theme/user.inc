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
    $text = t('By submitting this form you also accept the "<a href="@terms" target="_blank">terms and conditions</a>" of the site', array('@terms' => url('legal')));
  }
  else {
    $text = t('By submitting this form you also accept the "terms and conditions" of the site');
  }
  return $text;
}
