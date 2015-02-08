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
  $strongarm->name = 'comment_anonymous_c4m_content_featured';
  $strongarm->value = 0;
  $export['comment_anonymous_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_c4m_content_featured';
  $strongarm->value = '2';
  $export['comment_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_c4m_content_featured';
  $strongarm->value = 1;
  $export['comment_default_mode_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_c4m_content_featured';
  $strongarm->value = '50';
  $export['comment_default_per_page_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_c4m_content_featured';
  $strongarm->value = 1;
  $export['comment_form_location_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_c4m_content_featured';
  $strongarm->value = '1';
  $export['comment_preview_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_c4m_content_featured';
  $strongarm->value = 1;
  $export['comment_subject_field_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__c4m_content_featured';
  $strongarm->value = array(
    'view_modes' => array(),
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
  $export['field_bundle_settings_node__c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_c4m_content_featured';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_c4m_content_featured';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_c4m_content_featured';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_c4m_content_featured';
  $strongarm->value = '1';
  $export['node_preview_c4m_content_featured'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_c4m_content_featured';
  $strongarm->value = 1;
  $export['node_submitted_c4m_content_featured'] = $strongarm;

  return $export;
}
