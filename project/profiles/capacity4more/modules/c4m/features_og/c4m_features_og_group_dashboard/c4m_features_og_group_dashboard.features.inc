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
    'global' => 1,
    'types' => array(
      0 => 'discussion',
      1 => 'document',
      2 => 'event',
      3 => 'photo',
      4 => 'photoalbum',
      5 => 'wiki_page',
    ),
    'flag_short' => '<i class="fa fa-thumb-tack" aria-hidden="true"></i><span class="action">Promote</span>',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '<i class="fa fa-thumb-tack" aria-hidden="true"></i><span class="action">Demote</span>',
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
    'flag_confirmation' => 'Are you sure you want to pin (promote) this content?',
    'unflag_confirmation' => 'Are you sure you want to unpin (demote) this content?',
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Recommendation".
  $flags['c4m_og_content_recommend'] = array(
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
      10 => 'news',
      11 => 'organisation',
      12 => 'page_element',
      13 => 'photo',
      14 => 'photoalbum',
      15 => 'project',
      16 => 'topic',
      17 => 'wiki_page',
    ),
    'flag_short' => '<i class="fa fa-thumbs-o-up" aria-hidden="true"></i><span class="action">Recommend</span>',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '<i class="fa fa-thumbs-o-up" aria-hidden="true"></i><span class="action">Recommended</span>',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
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
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "C4M Follow Content".
  $flags['subscribe_c4m_follow_content'] = array(
    'entity_type' => 'node',
    'title' => 'C4M Follow Content',
    'global' => 0,
    'types' => array(
      0 => 'article',
      1 => 'discussion',
      2 => 'document',
      3 => 'event',
      4 => 'news',
      5 => 'photoalbum',
      6 => 'wiki_page',
    ),
    'flag_short' => '<i class="fa fa-plus-square-o" aria-hidden="true"></i><span class="action">Follow</span>',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '<i class="fa fa-minus-square-o" aria-hidden="true"></i><span class="action">Unfollow</span>',
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
      'highlight_list' => 0,
      'group_dashboard' => 0,
      'pinned_content' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "C4M Follow Group".
  $flags['subscribe_c4m_follow_group'] = array(
    'entity_type' => 'node',
    'title' => 'C4M Follow Group',
    'global' => 0,
    'types' => array(
      0 => 'group',
      1 => 'project',
    ),
    'flag_short' => 'Enable notifications',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Disable notifications',
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
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "C4M Follow Node".
  $flags['subscribe_c4m_follow_node'] = array(
    'entity_type' => 'node',
    'title' => 'C4M Follow Node',
    'global' => 0,
    'types' => array(
      0 => 'article',
      1 => 'discussion',
      2 => 'document',
      3 => 'event',
      4 => 'news',
      5 => 'wiki_page',
    ),
    'flag_short' => 'Flag this item',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
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
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "C4M Follow Term".
  $flags['subscribe_c4m_follow_term'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'C4M Follow Term',
    'global' => 0,
    'types' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_topic',
    ),
    'flag_short' => 'Enable notifications',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Disable notifications',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'c4m_features_og_group_dashboard',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
