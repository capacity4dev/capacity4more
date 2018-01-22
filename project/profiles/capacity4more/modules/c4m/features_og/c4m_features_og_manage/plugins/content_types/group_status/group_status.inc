<?php

/**
 * @file
 * Panels plugin to show the group status.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Group status management dashboard'),
  'description' => t('Renders group status management dashboard with edit links and thumbnail image.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_og_manage_group_status_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_manage_group_status_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_og_manage';
  $block->title = '';

  $group_status_statistics_and_thumbnail = c4m_features_og_manage_group_status_statistics_and_thumbnail();

  $block->content = theme('c4m_features_og_manage_group_status', array('info' => $group_status_statistics_and_thumbnail));

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_manage_group_status_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_manage_group_status_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_og_manage_group_status'] = array(
    'variables' => array(
      'info' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'group-status',
  );
}
