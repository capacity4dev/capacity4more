<?php

/**
 * @file
 * Integration of Money field with the feeds module.
 */

/**
 * Implements hook_feeds_node_processor_targets_alter().
 * @see FeedsNodeProcessor::getMappingTargets()
 */
function money_feeds_node_processor_targets_alter(&$targets, $content_type) {
  $info = content_types($content_type);
  $fields = array();
  if (isset($info['fields']) && count($info['fields'])) {
    foreach ($info['fields'] as $field_name => $field) {
      if ($field['type']=='money') {
        $fields[$field_name] = isset($field['widget']['label']) ? $field['widget']['label'] : $field_name;
      }
    }
  }
  foreach ($fields as $k => $name) {
    $targets[$k . '_amount'] = array(
      'name' => $name . ' (Amount)',
      'callback' => 'money_feeds_set_target_amount',
      'description' => t('The value of the node\'s Money field called "!name".', array('!name' => $name)),
    );
    $targets[$k . '_currency'] = array(
      'name' => $name . ' (Currency)',
      'callback' => 'money_feeds_set_target_currency',
      'description' => t('The currency of the node\'s Money field called "!name".', array('!name' => $name)),
    );
  }
}

function money_feeds_set_target_amount($node, $target, $value) {
  // use just the field name as the target
  $target = drupal_substr($target, 0, strrpos($target, '_'));

  $field = isset($node->$target) ? $node->$target : array();

  // Handle multiple value fields.
  if (is_array($value)) {
    $i = 0;
    foreach ($value as $v) {
      if (!is_array($v) && !is_object($v)) {
        $field[$i]['amount'] = $v;
      }
      $i++;
    }
  }
  else {
    $field[0]['amount'] = $value;
  }

  $node->$target = $field;
}

function money_feeds_set_target_currency($node, $target, $value) {
  // use just the field name as the target
  $target = drupal_substr($target, 0, strrpos($target, '_'));

  $field = isset($node->$target) ? $node->$target : array();

  // Handle multiple value fields.
  if (is_array($value)) {
    $i = 0;
    foreach ($value as $v) {
      if (!is_array($v) && !is_object($v)) {
        $field[$i]['currency'] = $v;
      }
      $i++;
    }
  }
  else {
    $field[0]['currency'] = $value;
  }

  $node->$target = $field;
}
