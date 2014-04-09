<?php
/**
 * @file
 * c4m_content_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_article_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_c4m_group_metadata|node|article|form';
  $field_group->group_name = 'group_c4m_group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'c4m_vocab_geo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'c4m-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_c4m_group_metadata|node|article|form'] = $field_group;

  return $export;
}
