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
  $groups = c4m_features_homepage_get_user_groups();

  if (is_null($groups)) {
    return;
  }

  $rendered_groups = '';
  // Render node views for each group,
  // First 5 groups are displayed (first_groups), the rest are hidden and only
  // shown when user clicks on "Show all" (extra_groups).
  $count = 0;
  foreach ($groups as $group) {
    $node_view = node_view($group, 'block_list');
    $rendered_groups .= drupal_render($node_view);

    $count++;
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

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = $rendered_groups ? theme('c4m_features_homepage_my_groups', $variables) : FALSE;
  return $block;
}

/**
 * Returns the list of groups of an user.
 *
 * @param object $account.
 *   User object. Defaults global user if NULL.
 * @param $types.
 *   Array of group types to be returned.
 *
 * @returns mixed|null
 *   List of groups or NULL if the user has no groups.
 */
function c4m_features_homepage_get_user_groups($account = NULL, $types = array('group')) {
  if (is_null($account)) {
    global $user;
    $account = user_load($user->uid);
  }

  // Get All user's groups (We get them sorted by id).
  $groups = og_get_groups_by_user($account, NULL, TRUE);

  if (empty($groups['node'])) {
    return FALSE;
  }

  $nids = array_values($groups['node']);

  $groups = node_load_multiple($nids);
  usort($groups, 'c4m_sort_object_by_title');

  return $groups;
}

/**
 * Returns the list of groups of an user, grouped by the membership type.
 *
 * @param object $account.
 *   User object. Defaults global user if NULL.
 * @param $types.
 *   Array of group types to be returned.
 *
 * @returns mixed|null
 *   List of groups or NULL if the user has no groups.
 */
function c4m_features_homepage_get_user_groups_grouped_by_membership($account = NULL, $types = array('group')) {
  $groups = c4m_features_homepage_get_user_groups($account, $types);

  foreach ($groups as $group) {
    // Ignores not wanted groups.
    if (in_array($group->type, $types)) {
      continue;
    }

    $group_admins = c4m_og_get_group_admins($group->nid);
    $is_admin = in_array($account->uid, array_keys($group_admins));

    // Is the owner of the group.
    if ($group->uid == $account->uid) {
      $grouped_groups['owned'][$group->nid] = $group;
    }
    // Is a group admin.
    else if ($is_admin) {
      $grouped_groups['admin'][$group->nid] = $group;
    }
    // Is a group member.
    else {
      $grouped_groups['member'][$group->nid] = $group;
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
