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
function _c4m_moodle_link_filter($text, $filter) {
  $moodle_base_url = variable_get('c4m_moodle_base_url');

  // If we don't know the Moodle base URL, just skip.
  if (empty($moodle_base_url)) {
    return $text;
  }

  return preg_replace_callback(
    '%<a[^>]*?href="(' . $moodle_base_url . '[^"]*?)"[^>]*?>(.*?)</a>%i',
    '_c4m_moodle_link_filter_process_matches',
    $text
  );
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

/**
 * Processes regex matches of links for _c4m_moodle_link_filter().
 *
 * @param array $matches
 *   Parameter passed by intlinks_hide_bad_filter_process();
 *   an array from regex match of the link.
 *
 * @return string
 *   Redirect link with the original link as query destination parameter.
 */
function _c4m_moodle_link_filter_process_matches($matches) {
  $url = $matches[1];
  $label = $matches[2];

  $moodle_redirect_url = l($label, 'moodle/redirect', array(
    'query' => array(
      'destination' => rawurlencode($url),
    ),
    // To make sure the links are rendered as the original.
    'html' => TRUE,
  ));

  return $moodle_redirect_url;
}
