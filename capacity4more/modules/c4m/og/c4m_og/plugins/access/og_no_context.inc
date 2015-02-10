<?php
/**
 * @file
 * Plugin to provide access control/visibility based on the fact if the page is
 * not within an OG context.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Page is not within an OG context'),
  'description' => t('Control access by the fact that the page is not within an OG context.'),
  'callback' => 'c4m_og_og_no_context_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'c4m_og_og_no_context_ctools_access_settings',
  'summary' => 'c4m_og_og_no_context_ctools_access_summary',
);

/**
 * Settings form for the 'Page is not within an OG context' access plugin
 */
function c4m_og_og_no_context_ctools_access_settings($form, &$form_state, $conf) {

  return $form;
}

/**
 * Check for access based on the fact the page is not within an OG context.
 */
function c4m_og_og_no_context_ctools_access_check($conf, $context) {

  return !og_context('node', NULL, NULL, FALSE);
}

/**
 * Provide a summary description based upon the active context..
 */
function c4m_og_og_no_context_ctools_access_summary($conf, $context) {
  return t('Page is not within an OG context');
}
