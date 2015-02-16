<?php
/**
 * @file
 * c4m_mail.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function c4m_mail_filter_default_formats() {
  $formats = array();

  // Exported format: Mail.
  $formats['mail'] = array(
    'format' => 'mail',
    'name' => 'Mail',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
