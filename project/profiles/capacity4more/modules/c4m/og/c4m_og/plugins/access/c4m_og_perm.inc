<?php

/**
 * @file
 * Plugin to provide access control based on user permission strings in a group.
 */

/**
 * C4M_OG_PERM plugin information.
 *
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("OG: C4M user permission in group"),
  'description' => t('Control access by group permission string.'),
  'callback' => 'c4m_og_c4m_og_perm_ctools_access_check',
  'default' => array('perm' => ''),
  'settings form' => 'c4m_og_c4m_og_perm_ctools_access_settings',
  'summary' => 'c4m_og_c4m_og_perm_ctools_access_summary',
  'required context' => array(
    new ctools_context_required(t('User'), 'user'),
  ),
);

/**
 * Settings form for the 'by perm' access plugin.
 */
function c4m_og_c4m_og_perm_ctools_access_settings($form, &$form_state, $conf) {
  $perms = array();
  // Get list of permissions.
  foreach (og_get_permissions() as $perm => $value) {
    // By keeping them keyed by module we can use optgroups with the
    // 'select' type.
    $perms[$value['module']][$perm] = $value['title'];
  }

  $form['settings']['perm'] = array(
    '#type' => 'select',
    '#options' => $perms,
    '#title' => t('Group permission'),
    '#default_value' => $conf['perm'],
    '#description' => t('Only users with the selected permission flag, in the specified group, will be able to access this.'),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Check for access.
 */
function c4m_og_c4m_og_perm_ctools_access_check($conf, $context) {
  global $user;

  $group = c4m_og_current_group();
  if (!$group) {
    return FALSE;
  }

  return og_user_access('node', $group->nid, $conf['perm'], $user);
}

/**
 * Provide a summary description based upon the checked permissions.
 */
function c4m_og_c4m_og_perm_ctools_access_summary($conf, $context) {
  $permissions = og_get_permissions();
  return t('User has "@perm" in group', array('@perm' => $permissions[$conf['perm']]['title']));
}
