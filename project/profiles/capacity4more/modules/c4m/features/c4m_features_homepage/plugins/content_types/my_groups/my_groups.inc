<?php

/**
 * @file
 * My groups panels block.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('My groups'),
  'description' => t("Renders authenticated user's groups."),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_my_groups_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_my_groups_content_type_render($subtype, $conf, $args, $context) {
  global $user;
  $groups = c4m_features_homepage_get_user_groups_grouped_by_membership($user);

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = '';
  if (empty($groups)) {
    return $block;
  }

  $rendered_groups = '';
  $count = 0;

  // Render node views for each group.
  foreach ($groups as $type => $group_list) {
    $title = c4m_features_homepage_get_group_type_title($type);
    $rendered_groups .= '<h4>' . $title . '</h4>';

    foreach ($group_list as $group) {
      $node_view = node_view($group, 'block_list');
      $rendered_groups .= drupal_render($node_view);

      $count++;
      if ($count >= 5) {
        break;
      }
    }

    if ($count >= 5) {
      break;
    }
  }

  $link_options = array(
    'query' => array(
      'filter' => 'groups',
    )
  );
  $variables = array(
    'groups' => $rendered_groups,
    'link' => url('groups', $link_options),
  );

  $block->content = $rendered_groups ? theme('c4m_features_homepage_my_groups', $variables) : FALSE;
  return $block;
}

/**
 * Returns the title for the type of membership of a group.
 *
 * @param string $type
 *   The group membership type.
 *
 * @return string
 *   The translated title for the membership type.
 */
function c4m_features_homepage_get_group_type_title($type) {
  $titles = array(
    'owner' => t('Owner of the following Group(s)'),
    'administrator' => t('Administrator of the following Group(s)'),
    'member' => t("Member of the following Group(s)"),
    'pending' => t('Membership requested in the following Group(s)'),
  );

  return $titles[$type];
}

/**
 * Returns the list of groups of an user.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 *
 * @returns mixed|null
 *   List of groups or NULL if the user has no groups.
 */
function c4m_features_homepage_get_user_groups($account = NULL) {
  $groups = c4m_user_og_get_groups($account);

  // Removes groups where the logged in user has no access.
  $groups = array_filter($groups, 'c4m_features_homepage_node_access_view_filter');

  usort($groups, 'c4m_sort_object_by_title');

  return $groups;
}

/**
 * Callback for array_filter that checks if the user has access to the node.
 *
 * @param object $node
 *   Node object.
 *
 * @returns boolean
 *   Indicates if the user has access or not.
 */
function c4m_features_homepage_node_access_view_filter($node) {
  return node_access('view', $node);
}

/**
 * Returns the list of groups of an user, grouped by the membership type.
 *
 * @param object $account
 *   User object. Defaults global user if NULL.
 *
 * @returns mixed|null
 *   List of groups or NULL if the user has no groups.
 */
function c4m_features_homepage_get_user_groups_grouped_by_membership($account = NULL) {
  $groups = c4m_features_homepage_get_user_groups($account);

  $grouped_groups = array(
    'owner' => array(),
    'administrator' => array(),
    'member' => array(),
  );
  foreach ($groups as $group) {
    $membership = c4m_user_og_get_role_in_group($account, $group);
    $grouped_groups[$membership][$group->nid] = $group;
  }

  // Remove empty list of groups so the block is not rendered if there are no
  // groups.
  foreach ($grouped_groups as $type => $groups) {
    if (empty($groups)) {
      unset($grouped_groups[$type]);
    }
  }

  return $grouped_groups;
}

/**
 * Edit form.
 */
function c4m_features_homepage_my_groups_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_my_groups_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_my_groups'] = array(
    'variables' => array(
      'groups' => NULL,
      'link' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'my-groups',
  );
}
