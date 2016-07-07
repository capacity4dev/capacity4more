<?php

/**
 * @file
 * Panels plugin to show the project status.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Project status management dashboard'),
  'description' => t('Renders project status management dashboard with edit links and thumbnail image.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_og_manage_project_status_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_manage_project_status_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_og_manage';
  $block->title = '';

  $project_thumbnail = c4m_features_og_manage_project_thumbnail();

  $block->content = theme('c4m_features_og_manage_project_status', array('info' => $project_thumbnail));

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_manage_project_status_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_manage_project_status_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_og_manage_project_status'] = array(
    'variables' => array(
      'info' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'project-status',
  );
}
