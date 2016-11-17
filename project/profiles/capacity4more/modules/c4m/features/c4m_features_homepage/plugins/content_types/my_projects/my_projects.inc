<?php

/**
 * @file
 * My projects panels block.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('My projects/programmes'),
  'description' => t("Renders authenticated user's projects & programmes."),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_my_projects_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_my_projects_content_type_render($subtype, $conf, $args, $context) {
  global $user;
  $projects = c4m_features_homepage_get_user_projects_grouped_by_membership($user, TRUE);

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = '';
  if (empty($projects)) {
    return $block;
  }

  $rendered_projects = '';
  $count = 0;
  $max_projects_to_display = 5;
  $total_projects = 0;

  // Render node views for each project.
  foreach ($projects as $type => $project_list) {
    $total_projects += count($project_list);

    if ($count >= $max_projects_to_display) {
      continue;
    }

    $title = c4m_features_homepage_get_project_type_title($type);
    $rendered_projects .= '<h4>' . $title . '</h4>';

    foreach ($project_list as $project) {
      if ($count >= $max_projects_to_display) {
        continue;
      }

      $node_view = node_view($project, 'block_list');
      $rendered_projects .= drupal_render($node_view);

      $count++;
    }
  }

  // When total projects are greater than the max projects to display then we
  // should display the "show more" button.
  $display_see_more = $total_projects > $max_projects_to_display;

  $link_options = array(
    'query' => array(
      'filter' => 'projects',
    )
  );
  $variables = array(
    'projects' => $rendered_projects,
    'link' => url('projects', $link_options),
    'display_see_more' => $display_see_more,
  );
  $output = '';
  if ($rendered_projects) {
    $output .= theme('c4m_features_homepage_my_projects', $variables);
    $renderable_array = c4m_features_homepage_node_creation_button_cta('project');
    $output .= render($renderable_array);
  }

  $block->content = $output;
  return $block;
}

/**
 * Returns the title for the type of membership of a project.
 *
 * @param string $type
 *   The project membership type.
 *
 * @return string
 *   The translated title for the membership type.
 */
function c4m_features_homepage_get_project_type_title($type) {
  $titles = array(
    'owner' => t('Owner of the following Project(s)'),
    'member' => t("Administrator of the following Project(s)"),
    'pending' => t('Membership requested in the following Project(s)'),
  );

  return $titles[$type];
}

/**
 * Returns the list of projects of an user.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 * @param bool $allow_pending
 *   Optional include requested projects (pending status).
 *
 * @returns mixed|null
 *   List of projects or NULL if the user has no projects.
 */
function c4m_features_homepage_get_user_projects($account = NULL, $allow_pending = FALSE) {
  $projects = c4m_user_og_get_groups($account, 'project', NODE_PUBLISHED, TRUE, $allow_pending);

  // Removes projects where the logged in user has no access.
  $projects = array_filter($projects, 'c4m_features_homepage_node_access_view_filter');

  usort($projects, '_c4m_og_sort_by_status');

  return $projects;
}

/**
 * Returns the list of projects of an user, grouped by the membership type.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 * @param bool $allow_pending
 *   Optional include requested projects (pending status).
 *
 * @returns mixed|null
 *   List of projects or NULL if the user has no projects.
 */
function c4m_features_homepage_get_user_projects_grouped_by_membership($account = NULL, $allow_pending = FALSE) {
  $projects = c4m_features_homepage_get_user_projects($account, $allow_pending);

  $grouped_projects = array(
    'owner' => array(),
    'member' => array(),
  );
  foreach ($projects as $project) {
    $membership = c4m_user_og_get_role_in_group($account, $project);

    if ($project->c4m_is_template[LANGUAGE_NONE][0]['value'] != '1') {
      $grouped_projects[$membership][$project->nid] = $project;
    }
  }

  // Remove empty list of projects so the block is not rendered if there are no
  // projects.
  foreach ($grouped_projects as $type => $projects) {
    if (empty($projects)) {
      unset($grouped_projects[$type]);
    }
  }

  return $grouped_projects;
}

/**
 * Edit form.
 */
function c4m_features_homepage_my_projects_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_my_projects_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_my_projects'] = array(
    'variables' => array(
      'projects' => NULL,
      'link' => NULL,
      'display_see_more' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'my-projects',
  );
}
