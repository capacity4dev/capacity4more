<?php
/**
 * @file
 * Panels plugin to show the project details.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Project details management dashboard'),
  'description' => t('Renders project details management dashboard with edit links.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_og_manage_project_details_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_og_manage_project_details_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_og_manage';
  $block->title = '';

  $project_details = c4m_features_og_manage_project_details();

  $block->content = theme('c4m_features_og_manage_project_details', array('details' => $project_details));

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_og_manage_project_details_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_og_manage_project_details_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_og_manage_project_details'] = array(
    'variables' => array(
      'details' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'project-details',
  );
}
