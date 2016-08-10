<?php

/**
 * @file
 * my profile_groups panels block.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('My profile groups'),
  'description' => t("Renders user groups."),
  'category' => t('C4M'),
  'hook theme' => 'c4m_user_profile_my_profile_groups_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_user_profile_my_profile_groups_content_type_render($subtype, $conf, $args, $context) {
  module_load_include('inc', 'c4m_features_homepage', 'plugins/content_types/my_groups/my_groups');
  $user = menu_get_object('user', 1);
  $groups = c4m_features_homepage_get_user_groups_grouped_by_membership($user, array('group'));

  if (is_null($groups)) {
    return;
  }

  $rendered_groups = '';
  // Render node views for each group,
  foreach ($groups as $type => $group_list) {
    $title = c4m_user_profile_get_group_type_title($type);
    $rendered_groups .= '<h3>' . $title . '</h3>';

    foreach ($group_list as $group) {
      $node_view = node_view($group, 'block_list');
      $rendered_groups .= drupal_render($node_view);
    }
  }

  $variables = array(
    'groups' => $rendered_groups,
  );

  $block = new stdClass();
  $block->module = 'c4m_user_profile';
  $block->title = '';
  $block->content = $rendered_groups ? theme('c4m_user_profile_my_profile_groups', $variables) : FALSE;
  return $block;
}

function c4m_user_profile_get_group_type_title($type) {
  $titles = array(
    'owned' => t('Groups I own'),
    'admin' => t('Groups I manage'),
    'member' => t("Groups I'm member of"),
  );

  return $titles[$type];
}

/**
 * Edit form.
 */
function c4m_user_profile_my_profile_groups_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_user_profile_my_profile_groups_content_type_theme(&$theme, $plugin) {
  $theme['c4m_user_profile_my_profile_groups'] = array(
    'variables' => array(
      'groups' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'my-profile-groups',
  );
}
