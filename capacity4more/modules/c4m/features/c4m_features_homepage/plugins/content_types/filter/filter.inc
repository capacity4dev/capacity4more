<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Content Filter'),
  'description' => t('Renders Content Filter.'),
  'category' => t('C4M'),
);

/**
 * Render callback.
 */
function c4m_features_homepage_filter_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'c4m_features_homepage';
  $block->title = '';

  $block->content = drupal_get_form('c4m_features_homepage_filter_form_create');

  return $block;
}

/**
 * Create form element for homepage filter.
 *
 * @return mixed
 */
function c4m_features_homepage_filter_form_create() {
  $options = og_get_groups_by_user() ? array('groups' => t('My groups')) : array();
  $options += array(
    'interests' => t('My interests'),
    'showAll' => t('Show all'),
  );

  $default_value = !empty($_GET['filter']) ? $_GET['filter'] : 'showAll';

  if (!array_key_exists($default_value, $options)) {
    $default_value = 'showAll';
  }

  $element['homepage-filter'] = array(
    '#type' => 'radios',
    '#title' => t('Filter by'),
    '#options' => $options,
    '#default_value' => $default_value,
  );

   $element['#attached']['js'][] = drupal_get_path('module', 'c4m_features_homepage') . '/plugins/content_types/filter/filter_homepage.js';

  return $element;
}

/**
 * Edit form.
 */
function c4m_features_homepage_filter_content_type_edit_form($form, &$form_state) {
  return $form;
}
