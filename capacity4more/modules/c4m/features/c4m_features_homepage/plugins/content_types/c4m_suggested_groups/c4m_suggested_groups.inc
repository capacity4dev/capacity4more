<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Suggested groups'),
  'description' => t('Renders suggested groups list.'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_features_homepage_c4m_suggested_groups_content_type_render($subtype, $conf, $args, $context) {
  // Add custom JavaScript for some behaviour on the group details pane.
  $block = new stdClass();
  $block->title = t('Suggested groups');
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
