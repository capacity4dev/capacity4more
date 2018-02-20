<?php

/**
 * @file
 * c4m_content_photoalbum.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_content_photoalbum_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_photoalbum';
  $strongarm->value = 0;
  $export['comment_anonymous_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_photoalbum';
  $strongarm->value = 1;
  $export['comment_default_mode_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_photoalbum';
  $strongarm->value = '50';
  $export['comment_default_per_page_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_photoalbum';
  $strongarm->value = 1;
  $export['comment_form_location_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_photoalbum';
  $strongarm->value = '0';
  $export['comment_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_photoalbum';
  $strongarm->value = '0';
  $export['comment_preview_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_photoalbum';
  $strongarm->value = 0;
  $export['comment_subject_field_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_photoalbum';
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
  $export['field_bundle_settings_comment__comment_node_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__photoalbum';
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
      'activity_group' => array(
        'custom_settings' => TRUE,
      ),
      'activity_global' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_dashboard' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_teaser_list' => array(
        'custom_settings' => FALSE,
      ),
      'c4m_teaser_table' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_group' => array(
        'custom_settings' => TRUE,
      ),
      'block_list' => array(
        'custom_settings' => TRUE,
      ),
      'group_dashboard' => array(
        'custom_settings' => FALSE,
      ),
      'pinned_content' => array(
        'custom_settings' => TRUE,
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
          'weight' => '7',
        ),
        'locations' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(
        'node_gallery_view' => array(
          'activity_group' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'activity_global' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'teaser_group' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'pinned_content' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'highlight_list' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
        ),
        'highlighted' => array(
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'block_list' => NULL,
          'highlight_list' => NULL,
        ),
        'flag_c4m_og_content_highlight' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'block_list' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
          'highlight_list' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser_group' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activity_global' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activity_group' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '31',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_photoalbum';
  $strongarm->value = array();
  $export['menu_options_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_photoalbum';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_photoalbum';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_photoalbum';
  $strongarm->value = '0';
  $export['node_preview_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_photoalbum';
  $strongarm->value = 0;
  $export['node_submitted_photoalbum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_photoalbum_pattern';
  $strongarm->value = 'photo-albums/[node:title]';
  $export['pathauto_node_photoalbum_pattern'] = $strongarm;

  return $export;
}
