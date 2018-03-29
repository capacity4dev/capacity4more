<?php

/**
 * @file
 * The capacity4more profile.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function capacity4more_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];

  // Disable the update module by default.
  // It slows down accessing the administration back-end.
  $form['update_notifications']['update_status_module']['#default_value'] = [
    0 => 0,
    1 => 2,
  ];
}

/**
 * Implements hook_install_tasks().
 */
function capacity4more_install_tasks() {
  $tasks = [];

  $tasks['capacity4more_setup_set_variables'] = [
    'display_name' => st('Set variables'),
    'display' => FALSE,
  ];

  $tasks['capacity4more_setup_set_menu_purl'] = [
    'display_name' => st('Set menu purl modifiers (main menu)'),
    'display' => FALSE,
  ];

  // Run this as the last task!
  $tasks['capacity4more_setup_rebuild_permissions'] = [
    'display_name' => st('Rebuild permissions'),
    'display' => FALSE,
  ];

  return $tasks;
}

/**
 * Task callback; Rebuild permissions (node access).
 *
 * Setting up the platform triggers the need to rebuild the permissions.
 * We do this here so no manual rebuild is necessary when we finished the
 * installation.
 */
function capacity4more_setup_rebuild_permissions() {
  node_access_rebuild();
}

/**
 * Task callback; Set variables.
 */
function capacity4more_setup_set_variables(&$install_state) {
  $variables = [
    // Homepage.
    'weight_frontpage' => '0',
    'site_frontpage' => 'dashboard',

    // Theme.
    'theme_default' => 'kapablo',
    'admin_theme' => 'seven',
    'node_admin_theme' => 0,
    'jquery_update_jquery_version' => '1.8',
    'jquery_update_jquery_admin_version' => '2.1',
    'page_manager_node_view_disabled' => FALSE,
    'page_manager_term_view_disabled' => FALSE,
    'jquery_update_jquery_migrate_enable' => TRUE,

    // RESTful.
    'restful_file_upload' => TRUE,

    // Enable counting views of the entity.
    'statistics_count_content_views' => TRUE,
    'statistics_count_content_views_ajax' => TRUE,

    // Set the homepage intro video.
    'c4m_features_homepage_intro_video_url' => 'http://youtu.be/O2AfmjzwAFY',
  ];

  foreach ($variables as $key => $value) {
    variable_set($key, $value);
  }
}

/**
 * Task callback; Setting purl modifiers for main menu.
 */
function capacity4more_setup_set_menu_purl() {
  $menus = ['main-menu', 'user-menu'];

  foreach ($menus as $menu) {
    variable_set('purl_menu_behavior_' . $menu, 'disabled');
  }
}
