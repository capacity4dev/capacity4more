<?php
/**
 * @file
 * Plugin to provide access control/visibility.
 *
 * Based on the fact if there is an active OG context.
 */

/**
 * Plugins are described by creating a $plugin array.
 *
 * Which will be used by the system that includes this file.
 */
$plugin = array(
  'title' => t('OG has group context'),
  'description' => t('Control access by the fact that the page is within an OG context.'),
  'callback' => 'c4m_og_og_context_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'c4m_og_og_context_ctools_access_settings',
  'summary' => 'c4m_og_og_context_ctools_access_summary',
);

/**
 * Settings form for the 'OG has group context' access plugin.
 */
function c4m_og_og_context_ctools_access_settings($form, &$form_state, $conf) {
  $default = (empty($conf['og_context_access_groups']))
    ? array()
    : $conf['og_context_access_groups'];

  $bundles = og_get_all_group_bundle();
  $options = empty($bundles['node'])
    ? array()
    : $bundles['node'];

  // Filter by group node type.
  $form['settings']['og_context_access_groups'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Limit by group type'),
    '#description' => t('Limit the access to only this group types. Select none to allow all.'),
    '#default_value' => $default,
    '#options' => $options,
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Check for access based on the fact there is an OG Context.
 */
function c4m_og_og_context_ctools_access_check($conf, $context) {
  // There should be an active OG context.
  $og_context = og_context();
  if (!$og_context) {
    return FALSE;
  }

  // The group of the OG context should exist.
  $group = node_load($og_context['gid']);
  if (!$group) {
    return FALSE;
  }

  // Check if the group type is within the (optionally) limited set of allowed
  // types.
  $group_types = array();
  if (!empty($conf)) {
    $group_types = array_filter($conf['og_context_access_groups']);
  }
  if (!empty($group_types) && !in_array($group->type, $group_types)) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Provide a summary description based upon the active context..
 */
function c4m_og_og_context_ctools_access_summary($conf, $context) {
  return t('OG has group context');
}
