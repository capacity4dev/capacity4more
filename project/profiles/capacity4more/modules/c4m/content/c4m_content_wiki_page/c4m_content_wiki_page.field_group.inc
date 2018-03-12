<?php

/**
 * @file
 * c4m_content_wiki_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function c4m_content_wiki_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|wiki_page|full';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wiki_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '3',
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
        'classes' => 'group-node-details field-group-fieldset',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_details|node|wiki_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_actions|node|wiki_page|full';
  $field_group->group_name = 'group_node_actions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wiki_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Do more through capacity4dev',
    'weight' => '2',
    'children' => array(
      0 => 'c4m_ds_node_highlight',
      1 => 'c4m_ds_node_promote',
      2 => 'c4m_ds_content_actions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Do more through capacity4dev',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-node-actions field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_node_actions|node|wiki_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pages|node|wiki_page|full';
  $field_group->group_name = 'group_pages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wiki_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group pages',
    'weight' => '1',
    'children' => array(
      0 => 'c4m_content_wiki_page_navigation',
      1 => 'c4m_content_wiki_page_add_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group pages',
      'instance_settings' => array(
        'id' => 'group-pages-navigation-left',
        'classes' => 'group-pages field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'blind',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_pages|node|wiki_page|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Do more through capacity4dev');
  t('Group pages');

  return $field_groups;
}
