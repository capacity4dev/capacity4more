<?php

/**
 * @file
 * Featured projects panels plugin.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Featured projects'),
  'description' => t('Renders featured projects list.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_c4m_featured_projects_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_c4m_featured_projects_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  $block->module = 'c4m_features_homepage';
  $block->content = c4m_features_homepage_c4m_featured_projects_get_projects();

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_homepage_c4m_featured_projects_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_c4m_featured_projects_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_c4m_featured_projects'] = array(
    'variables' => array(
      'projects' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'c4m_featured_projects',
  );
}

