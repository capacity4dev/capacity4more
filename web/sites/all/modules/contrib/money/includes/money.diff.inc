<?php

/**
 * @file
 * Integration of Money CCK field with diff module.
 */

/**
 * Implements hook_diff().
 */
function money_diff(&$old_node, &$new_node) {
  $result = array();
  $cck_info = content_types($new_node->type);
  if (isset($cck_info['fields']) && is_array($cck_info['fields'])) {
    foreach ($cck_info['fields'] as $field) {
      if ($field['type'] != 'money') {
        continue;
      }
      $old_values = array();
      $new_values = array();
      if (isset($old_node->$field['field_name'])) {
        $old_values = _money_diff_values($old_node, $field);
      }
      if (isset($new_node->$field['field_name'])) {
        $new_values = _money_diff_values($new_node, $field);
      }
      $result[$field['field_name']] = array(
        '#name' => $field['widget']['label'],
        '#old' => $old_values,
        '#new' => $new_values,
        '#weight' => $field['widget']['weight'],
        '#format' => array(
          'show_header' => FALSE,
        ),
      );
    }
  }
  return $result;
}

function _money_diff_values($node, $field) {
  $result = array();
  foreach ($node->$field['field_name'] as $item) {
    $result[] = theme('money_formatter_default', array(
      '#field_name' => $field['field_name'],
      '#type_name' => $node->type,
      '#formatter' => 'default',
      '#item' => $item,
    ));
  }
  return $result;
}

