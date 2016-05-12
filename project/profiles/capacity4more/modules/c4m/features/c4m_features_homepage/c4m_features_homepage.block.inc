<?php
/**
 * @file
 * Code for the homepage blocks.
 */

/**
 * Callback for the c4m_features_homepage_newsletter block.
 */
function _c4m_features_homepage_block_c4m_features_homepage_newsletter() {
  if (!$list_title = variable_get('campaignmonitor_list_title')) {
    return FALSE;
  }

  return array(
    'subject' => '',
    'content' => drupal_get_form('c4m_features_homepage_newsletter_form'),
  );
}
