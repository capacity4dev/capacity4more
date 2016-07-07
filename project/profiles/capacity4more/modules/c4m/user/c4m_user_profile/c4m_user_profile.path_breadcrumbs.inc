<?php

/**
 * @file
 * c4m_user_profile.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_user_profile_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_profile';
  $path_breadcrumb->name = 'User profile';
  $path_breadcrumb->path = 'user/%useridnumber';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'People',
      1 => '%useridnumber:c4m-first-name %useridnumber:c4m-last-name',
    ),
    'paths' => array(
      0 => 'people',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'useridnumber' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -82;
  $export['user_profile'] = $path_breadcrumb;

  return $export;
}
