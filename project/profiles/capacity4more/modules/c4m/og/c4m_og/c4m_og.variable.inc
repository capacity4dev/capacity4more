<?php

/**
 * @file
 * Variables provided by the capacity4more Organic Group Functionality module.
 */

/**
 * Implements hook_variable_info().
 */
function c4m_og_variable_info($options) {
  // Public groups.
  $variable['c4m_og_features_[group_type]'] = array(
    'type' => 'multiple',
    'title' => t('Default Features', array(), $options),
    'description' => t('Check the features to enable by default.', array(), $options),
    'group' => 'c4m_og',
    'repeat' => array(
      'type' => 'options',
      'options callback' => 'c4m_og_variable_features_option_list',
    ),
  );
  return $variable;
}

/**
 * Implements hook_variable_group_info().
 */
function c4m_og_variable_group_info() {
  $groups['c4m_og'] = array(
    'title' => t('C4M Organic Groups'),
    'description' => t('Variables for organic groups.'),
    'access' => 'create group content',
    'path' => array('admin/config/system/variable/c4m_og'),
  );
  return $groups;
}

/**
 * Implements hook_variable_type_info().
 */
function c4m_og_variable_type_info() {
  $types['group_type'] = array(
    'title' => t('Group type'),
    'options callback' => 'c4m_og_variable_group_type_option_list',
    'type' => 'select',
  );
  return $types;
}

/**
 * Callback for variable options.
 */
function c4m_og_variable_features_option_list($variable, $options = array()) {
  $features = c4m_og_feature_info();

  $list = array();
  foreach ($features as $feature) {
    $list[$feature['machine_name']] = $feature['name'] . '<span class="description"> (' . $feature['description'] . ')</span>';
  }
  return $list;
}

/**
 * Callback for variable options.
 *
 * @todo Add a key for projects, refactor c4m_og_features_group variable.
 */
function c4m_og_variable_group_type_option_list($variable, $options = array()) {
  return array(
    'group' => t('Group features', array(), $options),
  );
}
