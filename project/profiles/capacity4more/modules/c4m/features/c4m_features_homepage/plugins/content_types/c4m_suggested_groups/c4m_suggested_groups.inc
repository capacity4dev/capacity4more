<?php

/**
 * @file
 * Suggested groups panels plugin.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Suggested groups'),
  'description' => t('Renders suggested groups list.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_c4m_suggested_groups_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_c4m_suggested_groups_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = '';
  $block->module = 'c4m_features_homepage';
  $block->content = c4m_features_homepage_c4m_suggested_groups_get_groups();

  return $block;
}

/**
 * Edit form.
 */
function c4m_features_homepage_c4m_suggested_groups_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_c4m_suggested_groups_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_c4m_suggested_groups'] = array(
    'variables' => array(
      'groups' => NULL,
      'link' => NULL,
    ),
    'path' => $plugin['path'],
    'template' => 'c4m_suggested_groups',
  );
}
