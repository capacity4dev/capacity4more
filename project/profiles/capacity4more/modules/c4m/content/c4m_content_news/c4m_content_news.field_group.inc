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
  $field_group->identifier = 'group_meta_author|node|news|full';
  $field_group->group_name = 'group_meta_author';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_node_meta';
  $field_group->data = array(
    'label' => 'Group meta author',
    'weight' => '15',
    'children' => array(
      0 => 'c4m_user_first_and_last_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group meta author',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-meta-author field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_meta_author|node|news|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_actions|node|news|full';
  $field_group->group_name = 'group_node_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Do more through capacity4dev',
    'weight' => '8',
    'children' => array(
      0 => 'c4m_ds_node_highlight',
      1 => 'c4m_ds_content_actions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Do more through capacity4dev',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-actions field-group-html5',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_node_actions|node|news|full'] = $field_group;

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
    'weight' => '10',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_meta|node|news|full';
  $field_group->group_name = 'group_node_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group meta',
    'weight' => '7',
    'children' => array(
      0 => 'c4m_user_picture',
      1 => 'c4m_ds_update_date',
      2 => 'c4m_ds_type_insert_action',
      3 => 'group_meta_author',
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
  $field_groups['group_node_meta|node|news|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Do more through capacity4dev');
  t('Group meta');
  t('Group meta author');

  return $field_groups;
}
