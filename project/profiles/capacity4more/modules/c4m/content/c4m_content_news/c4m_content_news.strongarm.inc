<?php

/**
 * @file
 * c4m_content_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_content_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_news';
  $strongarm->value = 0;
  $export['comment_anonymous_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_news';
  $strongarm->value = 1;
  $export['comment_default_mode_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_news';
  $strongarm->value = '50';
  $export['comment_default_per_page_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_news';
  $strongarm->value = 1;
  $export['comment_form_location_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_news';
  $strongarm->value = '2';
  $export['comment_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_news';
  $strongarm->value = '0';
  $export['comment_preview_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_news';
  $strongarm->value = 0;
  $export['comment_subject_field_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_comment_publication_clears_host_entity_cache_node_news';
  $strongarm->value = array(
    'default' => 1,
    'full' => 0,
    'teaser' => 1,
    'teaser_group' => 1,
    'activity_global' => 1,
    'activity_group' => 1,
    'block_list' => 0,
    'pinned_content' => 0,
  );
  $export['display_cache_comment_publication_clears_host_entity_cache_node_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_activity_global';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_activity_global'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_activity_group';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_activity_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_block_list';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_block_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_default';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_full';
  $strongarm->value = array(
    'default' => array(
      'use' => '0',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_related_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_vocab_topic' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_vocab_date' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_vocab_language' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_vocab_geo' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'og_vocabulary' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_full'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_pinned_content';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_pinned_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_teaser';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_teaser'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_news_teaser_group';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_news_teaser_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_news';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'activity_group' => array(
        'custom_settings' => TRUE,
      ),
      'my_comments' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__news';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'teaser_group' => array(
        'custom_settings' => TRUE,
      ),
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'activity_group' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'block_list' => array(
        'custom_settings' => TRUE,
      ),
      'group_dashboard' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'pinned_content' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_news';
  $strongarm->value = array();
  $export['menu_options_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_news';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_news';
  $strongarm->value = '0';
  $export['node_preview_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_news';
  $strongarm->value = 1;
  $export['node_submitted_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_pattern';
  $strongarm->value = 'news/[node:title]';
  $export['pathauto_node_news_pattern'] = $strongarm;

  return $export;
}
