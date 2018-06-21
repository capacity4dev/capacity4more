<?php
/**
 * @file
 * c4m_content_featured.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_content_featured_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_featured';
  $strongarm->value = 0;
  $export['comment_anonymous_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_featured';
  $strongarm->value = 1;
  $export['comment_default_mode_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_featured';
  $strongarm->value = '50';
  $export['comment_default_per_page_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_featured';
  $strongarm->value = '1';
  $export['comment_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_featured';
  $strongarm->value = 1;
  $export['comment_form_location_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_featured';
  $strongarm->value = '0';
  $export['comment_preview_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_featured';
  $strongarm->value = 0;
  $export['comment_subject_field_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__featured';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'featured_block' => array(
        'custom_settings' => FALSE,
      ),
      'inthe_picture_block' => array(
        'custom_settings' => TRUE,
      ),
      'library' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_event' => array(
        'custom_settings' => FALSE,
      ),
      'activity_group' => array(
        'custom_settings' => FALSE,
      ),
      'activity_global' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
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
      'c4m_related' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_group' => array(
        'custom_settings' => FALSE,
      ),
      'block_list' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '30',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_featured';
  $strongarm->value = '20';
  $export['maxlength_js_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_featured';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_featured';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_featured';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_featured';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_featured';
  $strongarm->value = '0';
  $export['node_preview_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_featured';
  $strongarm->value = 1;
  $export['node_submitted_featured'] = $strongarm;

  return $export;
}
