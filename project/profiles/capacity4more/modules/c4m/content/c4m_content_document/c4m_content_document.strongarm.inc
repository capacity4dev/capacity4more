<?php

/**
 * @file
 * c4m_content_document.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_content_document_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_document';
  $strongarm->value = 0;
  $export['comment_anonymous_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_document';
  $strongarm->value = 1;
  $export['comment_default_mode_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_document';
  $strongarm->value = '50';
  $export['comment_default_per_page_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_document';
  $strongarm->value = '2';
  $export['comment_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_document';
  $strongarm->value = 1;
  $export['comment_form_location_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_document';
  $strongarm->value = '0';
  $export['comment_preview_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_document';
  $strongarm->value = 0;
  $export['comment_subject_field_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_comment_publication_clears_host_entity_cache_node_document';
  $strongarm->value = array(
    'default' => 1,
    'full' => 0,
    'teaser' => 1,
    'teaser_group' => 1,
    'activity_global' => 1,
    'activity_group' => 1,
    'block_list' => 0,
    'highlight_list' => 0,
    'pinned_content' => 0,
  );
  $export['display_cache_comment_publication_clears_host_entity_cache_node_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_activity_global';
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
    'c4m_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_activity_global'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_activity_group';
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
    'c4m_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_activity_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_block_list';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_block_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_default';
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
    'c4m_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_full';
  $strongarm->value = array(
    'default' => array(
      'use' => '0',
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
    'c4m_vocab_document_type' => array(
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
    'og_vocabulary' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
    'c4m_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_full'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_highlight_list';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_highlight_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_pinned_content';
  $strongarm->value = array(
    'default' => array(
      'use' => '1',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_pinned_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_teaser';
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
    'c4m_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_teaser'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'display_cache_node_document_teaser_group';
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
    'c4m_document' => array(
      'override' => '2',
      'page_granularity' => '0',
      'user_granularity' => '1',
      'granularity' => '1',
    ),
  );
  $export['display_cache_node_document_teaser_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_document';
  $strongarm->value = array(
    'view_modes' => array(
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'activity_group' => array(
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
      'my_comments' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__document';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
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
      'activity_group' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_teaser_table' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_related' => array(
        'custom_settings' => FALSE,
      ),
      'featured_block' => array(
        'custom_settings' => FALSE,
      ),
      'library' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_event' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'c4m_dashboard' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_teaser_list' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_group' => array(
        'custom_settings' => TRUE,
      ),
      'block_list' => array(
        'custom_settings' => TRUE,
      ),
      'pinned_content' => array(
        'custom_settings' => TRUE,
      ),
      'group_dashboard' => array(
        'custom_settings' => FALSE,
      ),
      'highlight_list' => array(
        'custom_settings' => TRUE,
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
          'weight' => '13',
        ),
        'redirect' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(
        'flag_c4m_node_highlight' => array(
          'full' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'teaser' => NULL,
          'teaser_group' => NULL,
          'activity_global' => NULL,
          'activity_group' => NULL,
          'block_list' => NULL,
          'pinned_content' => NULL,
          'highlight_list' => NULL,
        ),
        'flag_c4m_og_content_highlight' => array(
          'full' => array(
            'weight' => '28',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'activity_group' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'activity_global' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'teaser_group' => array(
            'weight' => '34',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '29',
            'visible' => FALSE,
          ),
          'pinned_content' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'highlight_list' => array(
            'weight' => '29',
            'visible' => FALSE,
          ),
        ),
        'highlighted' => array(
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'teaser_group' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'highlight_list' => NULL,
        ),
        'promoted' => array(
          'teaser' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'teaser_group' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'highlight_list' => NULL,
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_document';
  $strongarm->value = array();
  $export['menu_options_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_document';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_document';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_document';
  $strongarm->value = '0';
  $export['node_preview_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_document';
  $strongarm->value = 1;
  $export['node_submitted_document'] = $strongarm;

  return $export;
}
