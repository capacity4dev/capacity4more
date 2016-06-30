<?php
/**
 * @file
 * c4m_content_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function c4m_content_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function c4m_content_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Create a Project to work together on projects.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function c4m_content_project_paragraphs_info() {
  $items = array(
    'c4m_paragraph_text' => array(
      'name' => 'Text',
      'bundle' => 'c4m_paragraph_text',
      'locked' => '1',
    ),
  );
  return $items;
}
