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

  $tasks['capacity4more_setup_set_variables'] = array(
    'display_name' => st('Set variables'),
    'display' => FALSE,
  );

  $tasks['capacity4more_setup_set_permissions'] = array(
    'display_name' => st('Set permissions'),
    'display' => FALSE,
  );

  $tasks['capacity4more_setup_set_og_permissions'] = array(
    'display_name' => st('Set OG permissions'),
    'display' => FALSE,
  );

  $tasks['capacity4more_setup_set_terms_og_permissions'] = array(
    'display_name' => st('Set terms OG permissions'),
    'display' => FALSE,
  );

  $tasks['capacity4more_setup_set_menu_purl'] = array(
    'display_name' => st('Set menu purl modifiers (main menu)'),
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
  $variables = array(
    // Homepage.
    'weight_frontpage' => '0',
    'site_frontpage' => 'node',

    // Theme.
    'theme_default' => 'kapablo',
    'admin_theme' => 'seven',
    'node_admin_theme' => 0,
    'jquery_update_jquery_version' => '2.1',
    'jquery_update_jquery_admin_version' => '2.1',
    'page_manager_node_view_disabled' => FALSE,
    'page_manager_term_view_disabled' => FALSE,
    'jquery_update_jquery_migrate_enable' => TRUE,

    // RESTful.
    'restful_file_upload' => TRUE,

    // Enable counting views of the entity.
    'statistics_count_content_views' => TRUE,

    // Set the homepage intro video.
    'c4m_features_homepage_intro_video_url' => 'http://youtu.be/O2AfmjzwAFY',
  );

  foreach ($variables as $key => $value) {
    variable_set($key, $value);
  }
}

/**
 * Task callback; Create permissions.
 */
function capacity4more_setup_set_permissions(&$install_state) {
  // Enable default permissions for authenticated users.
  $permissions = array(
    'access content',
    'create group content',
    'edit own group content',
    'delete own group content',
    'create new books',
    'add content to books',
  );

  $content_types = array(
    'discussion',
    'document',
    'event',
    'photo',
    'photoalbum',
  );

  foreach ($content_types as $content_type) {
    $permissions[] = "create $content_type content";
  }

  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $permissions);
}

/**
 * Task callback; Setting OG permissions.
 */
function capacity4more_setup_set_og_permissions() {
  // Set OG_AUTHENTICATED_ROLE permissions.
  $content_types = array(
    'discussion',
    'document',
    'event',
    'photo',
    'photoalbum',
  );

  $permissions = array();
  foreach ($content_types as $content_type) {
    $permissions = array_merge($permissions, array(
      "create $content_type content",
      "update own $content_type content",
      "delete own $content_type content",
    ));
  }

  $roles = og_roles('node', 'group');
  $auth_rid = array_search(OG_AUTHENTICATED_ROLE, $roles);
  og_role_grant_permissions($auth_rid, $permissions);

  // Set OG_ADMINISTRATOR_ROLE permissions.
  $content_types = array(
    'wiki_page',
  );

  $permissions = array();
  foreach ($content_types as $content_type) {
    $permissions = array_merge($permissions, array(
      "create $content_type content",
      "update own $content_type content",
      "update any $content_type content",
    ));
  }

  // OG Flag permissions.
  $og_flag_perms = array(
    'c4m_og_content_promote',
    'c4m_og_content_depromote',

    'c4m_og_content_recommend',
    'c4m_og_content_unrecommend',
  );
  $permissions = array_merge($permissions, $og_flag_perms);

  $roles = og_roles('node', 'group');
  $admin_member_rid = array_search(OG_ADMINISTRATOR_ROLE, $roles);
  og_role_grant_permissions($admin_member_rid, $permissions);

  // Set OG_ADMINISTRATOR_ROLE permissions by project.
  $content_types = array(
    'document',
    'event',
  );

  $permissions = array();
  foreach ($content_types as $content_type) {
    $permissions = array_merge($permissions, array(
      "create $content_type content",
      "update own $content_type content",
      "update any $content_type content",
      "delete own $content_type content",
      "delete any $content_type content",
    ));
  }

  $roles = og_roles('node', 'project');
  $auth_rid = array_search(OG_ADMINISTRATOR_ROLE, $roles);
  og_role_grant_permissions($auth_rid, $permissions);
}

/**
 * Task callback; Setting purl modifiers for main menu.
 */
function capacity4more_setup_set_menu_purl() {
  $menus = array('main-menu', 'user-menu');

  foreach ($menus as $menu) {
    variable_set('purl_menu_behavior_' . $menu, 'disabled');
  }
}

/**
 * Task callback; Setting terms OG permissions.
 */
function capacity4more_setup_set_terms_og_permissions() {
  $permissions = array(
    'edit terms',
    'delete terms',
  );

  $roles = og_roles('node', 'group');
  $auth_rid = array_search(OG_AUTHENTICATED_ROLE, $roles);
  $admin_rid = array_search(OG_ADMINISTRATOR_ROLE, $roles);
  og_role_grant_permissions($auth_rid, $permissions);
  $permissions[] = 'manage variables';
  og_role_grant_permissions($admin_rid, $permissions);
}
