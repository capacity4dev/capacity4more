<?php
/**
 * @file
 * c4m_features_og_group_dashboard.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_features_og_group_dashboard_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function c4m_features_og_group_dashboard_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function c4m_features_og_group_dashboard_flag_default_flags() {
  $flags = array();
  // Exported flag: "Promote".
  $flags['c4m_og_content_highlight'] = array(
    'entity_type' => 'node',
    'title' => 'Promote',
    'global' => 0,
    'types' => array(
      0 => 'discussion',
      1 => 'document',
      2 => 'event',
      3 => 'wiki_page',
    ),
    'flag_short' => 'Promote',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Demote',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => 'teaser',
      'full' => 0,
      'rss' => 0,
      'print' => 0,
      'featured_block' => 0,
      'inthe_picture_block' => 0,
      'library' => 0,
      'upcoming_event' => 0,
      'activity_group' => 0,
      'activity_global' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'c4m_dashboard' => 0,
      'c4m_teaser_list' => 0,
      'c4m_teaser_table' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to flag this content?',
    'unflag_confirmation' => 'Are you sure you want to unflag this content?',
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
