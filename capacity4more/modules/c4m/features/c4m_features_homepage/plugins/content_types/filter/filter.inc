<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Content Filter'),
  'description' => t('Renders Content Filter.'),
  'category' => t('C4M'),
  'hook theme' => 'c4m_features_homepage_filter_content_type_theme',
);

/**
 * Render callback.
 */
function c4m_features_homepage_filter_content_type_render($subtype, $conf, $args, $context) {
  global $user;
  $account = user_load($user->uid);
  $is_member = !empty($account->og_user_node);

  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';
  $block->content = theme('c4m_features_homepage_filter', array('is_member' =>$is_member));
  return $block;
}

/**
 * Edit form.
 */
function c4m_features_homepage_filter_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Delegated hook_theme().
 */
function c4m_features_homepage_filter_content_type_theme(&$theme, $plugin) {
  $theme['c4m_features_homepage_filter'] = array(
    'variables' => array(
      'is_member' => FALSE,
    ),
    'path' => $plugin['path'],
    'template' => 'filter',
  );
}
