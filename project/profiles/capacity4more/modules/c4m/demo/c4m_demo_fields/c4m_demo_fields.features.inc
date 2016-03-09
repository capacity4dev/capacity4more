<?php
/**
 * @file
 * c4m_demo_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_demo_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_demo_fields_node_info() {
  $items = array(
    'demo_fields' => array(
      'name' => t('Demo Fields'),
      'base' => 'node_content',
      'description' => t('Demonstration of the base fields within the capacity4more distribution.
<strong>Do not use this content type within a production environment!</strong>'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
