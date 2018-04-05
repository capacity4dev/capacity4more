<?php

/**
 * @file
 * c4m_content_article.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_content_article_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_article';
  $strongarm->value = 0;
  $export['comment_anonymous_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_article';
  $strongarm->value = '2';
  $export['comment_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_article';
  $strongarm->value = 1;
  $export['comment_default_mode_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_article';
  $strongarm->value = '50';
  $export['comment_default_per_page_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_article';
  $strongarm->value = 1;
  $export['comment_form_location_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_article';
  $strongarm->value = '0';
  $export['comment_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_article';
  $strongarm->value = 0;
  $export['comment_subject_field_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_comment_publication_clears_host_entity_cache_node_article';
  $strongarm->value = array(
    'activity_global' => 1,
    'teaser' => 1,
    'default' => 1,
    'full' => 0,
    'block_list' => 1,
  );
  $export['display_cache_comment_publication_clears_host_entity_cache_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_article_default';
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
  $export['display_cache_node_article_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_article_full';
  $strongarm->value = array(
    'default' => array(
      'use' => '0',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_vocab_topic' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_vocab_geo' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_related_group' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_related_articles' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_body' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_related_user' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
    'c4m_link_multiple' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '0',
      'granularity' => '0',
    ),
  );
  $export['display_cache_node_article_full'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_article';
  $strongarm->value = array(
    'view_modes' => array(
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
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
  $export['field_bundle_settings_comment__comment_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
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
      'teaser_group' => array(
        'custom_settings' => FALSE,
      ),
      'block_list' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'group_dashboard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '11',
        ),
        'locations' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article';
  $strongarm->value = array();
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article';
  $strongarm->value = '0';
  $export['node_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article';
  $strongarm->value = 1;
  $export['node_submitted_article'] = $strongarm;

  return $export;
}
