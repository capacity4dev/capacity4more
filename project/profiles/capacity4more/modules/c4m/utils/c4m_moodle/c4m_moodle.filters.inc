<?php

/**
 * @file
 * C4M Moodle filters functionality.
 */

/**
 * Implements hook_filter_info().
 */
function c4m_moodle_filter_info() {
  $filters['c4m_moodle_link_filter'] = array(
    'title' => t('Moodle link filter'),
    'description' => t('Converts Moodle links to a Moodle redirect controller link.'),
    'process callback' => '_c4m_moodle_link_filter',
    'tips callback' => '_c4m_moodle_link_filter_tips',
  );

  return $filters;
}

/**
 * Implements callback_filter_process().
 *
 * Converts links to the Moodle platform into links to the Drupal Moodle
 * Redirect Controller automatically.
 */
function _c4m_moodle_link_filter($text) {
  return $text;
}

/**
 * Implements callback_filter_tips().
 *
 * Provides help for the Moodle Link filter.
 *
 * @see filter_filter_info()
 */
function _c4m_moodle_link_filter_tips($filter, $format, $long = FALSE) {
  return t('Links to the Moodle platform turn into links to the Drupal Moodle Redirect Controller automatically.');
}
