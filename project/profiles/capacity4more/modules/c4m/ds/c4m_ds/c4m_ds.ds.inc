<?php

/**
 * @file
 * c4m_ds.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function c4m_ds_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'c4m_rendered_content';
  $ds_field->label = 'Rendered content';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|pinned_content';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['c4m_rendered_content'] = $ds_field;

  return $export;
}
