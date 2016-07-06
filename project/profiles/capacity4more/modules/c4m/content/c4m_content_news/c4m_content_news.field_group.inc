<?php
/**
 * @file
 * c4m_content_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_news_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_details|node|news|full';
  $field_group->group_name = 'group_node_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '8',
    'children' => array(
      0 => 'c4m_vocab_date',
      1 => 'c4m_vocab_geo',
      2 => 'c4m_vocab_language',
      3 => 'c4m_vocab_topic',
      4 => 'og_vocabulary',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-details field-group-fieldset clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_node_details|node|news|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');

  return $field_groups;
}
