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

  $account = user_load($user->uid);
  $first_groups = '';
  $extra_groups = '';

  // Get All user's groups (We get them sorted by id).
  $groups = og_get_groups_by_user($account, NULL, TRUE);

  if (empty($groups['node'])) {
    return FALSE;
  }

  $nids = array_values($groups['node']);

  $my_groups = node_load_multiple($nids);

  usort($my_groups, 'c4m_sort_object_by_title');

  // Render node views for each group,
  // First 3 groups are displayed (first_groups), the rest are hidden and only
  // shown when user clicks on "Show all" (extra_groups).
  $count = 0;
  foreach ($my_groups as $group) {
    if ($group->type != 'group') {
      continue;
    }
    $node_view = node_view($group, 'block_list');
    if ($count < 3) {
      $first_groups .= drupal_render($node_view);
    }
    else {
      $extra_groups .= drupal_render($node_view);
    }
    $count++;
  }

  $variables = array(
    'first_groups' => $first_groups,
    'extra_groups' => $extra_groups,
    'show_all_link' => $count > 3 ? TRUE : FALSE,
  );

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = $first_groups ? theme('c4m_features_homepage_my_groups', $variables) : FALSE;
  return $block;
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
      'first_groups' => NULL,
      'extra_groups' => NULL,
      'show_all_link' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'my-groups',
  );
}
