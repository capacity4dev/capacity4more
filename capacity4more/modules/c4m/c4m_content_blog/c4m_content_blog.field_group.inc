<?php
/**
 * @file
 * c4m_content_blog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_blog_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_metadata|node|blog|form';
  $field_group->group_name = 'c4m_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'og_vocabulary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'c4m-metadata field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['c4m_metadata|node|blog|form'] = $field_group;

  return $export;
}
