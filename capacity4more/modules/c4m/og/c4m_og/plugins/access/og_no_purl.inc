<?php
/**
 * @file
 * Plugin to provide access control/visibility based on PURL in URL or not.
 */

/**
 * Plugin information.
 *
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Page URL doesn't have group purl in it."),
  'description' => t("Control access by the fact that the page URL doesn't have group purl in it."),
  'callback' => 'c4m_og_og_no_purl_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'c4m_og_og_no_purl_ctools_access_settings',
  'summary' => 'c4m_og_og_no_purl_ctools_access_summary',
);

/**
 * Settings form for the 'Page URL doesn't have group purl in it' access plugin.
 */
function c4m_og_og_no_purl_ctools_access_settings($form, &$form_state, $conf) {

  return $form;
}

/**
 * Check for access based on the fact the page URL doesn't have group PURL.
 */
function c4m_og_og_no_purl_ctools_access_check($conf, $context) {
  $handler = og_purl_og_context_handler();
  return empty($handler);
}

/**
 * Provide a summary description based upon the active context..
 */
function c4m_og_og_no_purl_ctools_access_summary($conf, $context) {
  return t("page URL doesn't have group purl in it");
}
