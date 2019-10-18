<?php

/**
 * @file
 * c4m_content_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'c4m_metadata|node|article|form';
  $field_group->group_name = 'c4m_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '5',
    'children' => array(
      0 => 'c4m_vocab_geo',
      1 => 'c4m_vocab_topic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'c4m-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['c4m_metadata|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_actions|node|article|full';
  $field_group->group_name = 'group_node_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Do more through capacity4dev',
    'weight' => '11',
    'children' => array(
      0 => 'c4m_ds_content_actions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Do more through capacity4dev',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-actions',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_node_actions|node|article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_meta|node|article|full';
  $field_group->group_name = 'group_node_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group meta',
    'weight' => '12',
    'children' => array(
      0 => 'c4m_related_articles',
      1 => 'c4m_related_group',
      2 => 'c4m_vocab_geo',
      3 => 'c4m_vocab_topic',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group meta',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-meta field-group clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_node_meta|node|article|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Do more through capacity4dev');
  t('Group meta');
  t('Metadata');

  return $field_groups;
}
