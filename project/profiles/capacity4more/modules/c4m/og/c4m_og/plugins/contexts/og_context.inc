<?php
/**
 * @file
 * Plugin to provide a group context.
 *
 * A group context is a group node wrapped in a context object that can be
 * utilized by anything that accepts contexts.
 */

/**
 * Plugins are described by creating a $plugin array.
 *
 * Which will be used by the system that includes this file.
 */
$plugin = array(
  'title' => t("Current OG Group from context"),
  'description' => t('Get the current Group from the Organic Groups context.'),
  'context' => 'c4m_og_context_create_og_context',
  'edit form' => 'c4m_og_context_settings_form',
  'keyword' => 'og_context',
  'convert list' => 'c4m_og_context_node_convert_list',
  'convert' => 'c4m_og_context_node_convert',
);

/**
 * It's important to remember that $conf is optional here.
 *
 * Because contexts are not always created from the UI.
 *
 * @param bool $empty
 *   Is the context available.
 * @param mixed $data
 *   The data array.
 * @param mixed $conf
 *   The configuration.
 * @param mixed $plugin
 *   The plugin information.
 *
 * @return mixed
 *   The found context or NULL when none found.
 */
function c4m_og_context_create_og_context($empty, $data = NULL, $conf = FALSE, $plugin = NULL) {
  $context = new ctools_context('og_context');
  $context->plugin = 'og_context';

  if ($empty) {
    return $context;
  }

  // Check if there is an active context.
  $og_context = og_context();
  if (!$og_context) {
    return;
  }

  // Check if the group of the active context exists.
  $group = node_load($og_context['gid']);
  if (!$group) {
    return;
  }

  // See if there is a limit on the allowed group types.
  if ($conf
    && !empty($data['og_context_group_types'])
    && !in_array($group->type, $data['og_context_group_types'])
  ) {
    return;
  }

  $context->data = $group;
  $context->title = $group->title;
  $context->argument = $group->nid;
  $context->restrictions['type'] = array($group->type);
  return $context;
}

/**
 * Settings form for the og_context.
 *
 * @param array $form
 *   The form as already created by ctools.
 * @param array $form_state
 *   The form state as already created by ctools.
 *
 * @return array
 *   The settings form array.
 *
 * @see c4m_og_context_settings_form_submit()
 */
function c4m_og_context_settings_form(array $form, array &$form_state) {
  $conf = $form_state['conf'];
  $default = empty($conf['og_context_group_types'])
    ? array()
    : $conf['og_context_group_types'];

  $group_bundles = og_get_all_group_bundle();
  $options = empty($group_bundles['node'])
    ? array()
    : $group_bundles['node'];

  // Filter by group node type.
  $form['og_context_setting'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Limit by group type'),
    '#description' => t('Limit the context to only this group types. Select none to allow all.'),
    '#default_value' => $default,
    '#options' => $options,
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Submit handler for c4m_og_context_settings_form().
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state.
 */
function c4m_og_context_settings_form_submit(array $form, array &$form_state) {
  $group_types = array();
  if (!empty($form_state['values']['og_context_setting'])) {
    $group_types = array_filter($form_state['values']['og_context_setting']);
  }

  $form_state['conf']['og_context_group_types'] = $group_types;
}

/**
 * Provide a list of ways that this context can be converted to a string.
 *
 * @return array
 *   Array of tokens.
 */
function c4m_og_context_node_convert_list() {
  $tokens = token_info();
  foreach ($tokens['tokens']['node'] as $id => $info) {
    if (!isset($list[$id])) {
      $list[$id] = $info['name'];
    }
  }

  return $list;
}

/**
 * Convert a context into a string.
 *
 * @param object $context
 *   The context to alter.
 * @param string $type
 *   The node type.
 *
 * @return mixed
 *   The converted context.
 */
function c4m_og_context_node_convert($context, $type) {
  $tokens = token_info();
  if (!isset($tokens['tokens']['node'][$type])) {
    return;
  }

  $values = token_generate(
    'node',
    array($type => $type),
    array('node' => $context->data)
  );
  if (!isset($values[$type])) {
    return;
  }

  return $values[$type];
}
