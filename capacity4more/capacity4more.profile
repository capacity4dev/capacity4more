<?php
/**
 * @file
 * Garmentbox profile.
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
  $form['update_notifications']['update_status_module']['#default_value'] = array(
    0 => 0,
    1 => 2,
  );
}

/**
 * Implements hook_install_tasks().
 */
function capacity4more_install_tasks() {
  $tasks = array();

  $tasks['capacity4more_setup_blocks'] = array(
    'display_name' => st('Setup Blocks'),
    'display' => FALSE,
  );

//  $tasks['capacity4more_setup_og_permissions'] = array(
//    'display_name' => st('Setup Blocks'),
//    'display' => FALSE,
//  );

  $tasks['capacity4more_setup_set_variables'] = array(
    'display_name' => st('Set variables'),
    'display' => FALSE,
  );

  // Run this as the last task!
  $tasks['capacity4more_setup_rebuild_permissions'] = array(
    'display_name' => st('Rebuild permissions'),
    'display' => FALSE,
  );

  return $tasks;
}

/**
 * Task callback; Setup blocks.
 */
function capacity4more_setup_blocks() {
  $default_theme = variable_get('theme_default', 'bartik');

  $blocks = array(
    array(
      'module' => 'system',
      'delta' => 'user-menu',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'header',
      'pages' => '',
      'title' => '<none>',
      'cache' => DRUPAL_NO_CACHE,
    ),
  );

  drupal_static_reset();
  _block_rehash($default_theme);
  foreach ($blocks as $record) {
    $module = array_shift($record);
    $delta = array_shift($record);
    $theme = array_shift($record);
    db_update('block')
      ->fields($record)
      ->condition('module', $module)
      ->condition('delta', $delta)
      ->condition('theme', $theme)
      ->execute();
  }
}

/**
 * Task callback; Setup OG permissions.
 *
 * We do this here, late enough to make sure all group-content were
 * created.
 */
//function capacity4more_setup_og_permissions() {
//  $og_roles = og_roles('node', 'company');
//  $rid = array_search(OG_AUTHENTICATED_ROLE, $og_roles);
//
//  $permissions = array();
//  $types = array(
//    'discussion',
//  );
//  foreach ($types as $type) {
//    $permissions["create $type content"] = TRUE;
//    $permissions["update own $type content"] = TRUE;
//    $permissions["update any $type content"] = TRUE;
//  }
//  og_role_change_permissions($rid, $permissions);
//}

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
function capacity4more_setup_set_variables() {
  $variables = array(
    // Homepage
    'site_frontpage' => 'homepage',

    // Theme
    'theme_default' => 'bootstrap',
    'admin_theme' => 'seven',
    'node_admin_theme' => 1,
    'jquery_update_jquery_version' => 1.8,
    'jquery_update_jquery_admin_version' => 1.5,
    'page_manager_node_view_disabled' => FALSE,
    'page_manager_term_view_disabled' => FALSE,
  );

  foreach ($variables as $key => $value) {
    variable_set($key, $value);
  }
}
