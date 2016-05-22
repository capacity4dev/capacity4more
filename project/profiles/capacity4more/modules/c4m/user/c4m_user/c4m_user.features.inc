<?php
/**
 * @file
 * c4m_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function c4m_user_flag_default_flags() {
  $flags = array();
  // Exported flag: "Recommendation".
  $flags['recommendation'] = array(
    'entity_type' => 'node',
    'title' => 'Recommendation',
    'global' => 0,
    'types' => array(
      0 => 'article',
      1 => 'banner',
      2 => 'book',
      3 => 'discussion',
      4 => 'document',
      5 => 'event',
      6 => 'featured',
      7 => 'feed',
      8 => 'group',
      9 => 'inthe_picture',
      10 => 'organisation',
      11 => 'page_element',
      12 => 'photo',
      13 => 'photoalbum',
      14 => 'project',
      15 => 'topic',
      16 => 'wiki_page',
    ),
    'flag_short' => 'Recommend this item',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove recommendation this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'teaser_group' => 0,
      'activity_global' => 0,
      'activity_group' => 0,
      'block_list' => 0,
      'group_dashboard' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'c4m_user',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
