<?php
/**
 * @file
 * c4m_demo_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function c4m_demo_fields_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-demo_fields-c4m_body'
  $field_instances['node-demo_fields-c4m_body'] = array(
    'bundle' => 'demo_fields',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A multiline text element that can be spitted in a summary and a full text part.
This field can have a WYSIWYG rich text editor interface.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'c4m_body',
    'label' => 'c4m_body',
    'required' => 1,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A multiline text element that can be spitted in a summary and a full text part.
This field can have a WYSIWYG rich text editor interface.');
  t('c4m_body');

  return $field_instances;
}
