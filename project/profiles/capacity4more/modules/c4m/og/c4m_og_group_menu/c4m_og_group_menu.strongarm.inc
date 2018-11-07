<?php

/**
 * @file
 * c4m_og_group_menu.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function c4m_og_group_menu_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_assignment';
  $strongarm->value = 'autocomplete';
  $export['og_menu_assignment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_block_links';
  $strongarm->value = 0;
  $export['og_menu_block_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_context_limit';
  $strongarm->value = 0;
  $export['og_menu_context_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_create_by_default';
  $strongarm->value = 1;
  $export['og_menu_create_by_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_default_links_node_group';
  $strongarm->value = 'Home|node/[node:nid]
Wiki|wiki
Library|documents
Discussions|discussions
Media|media
Events|calendar
Members|members';
  $export['og_menu_default_links_node_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_default_links_node_project';
  $strongarm->value = 'Home|node/[node:nid]
Wiki|wiki
Library|documents
News|news
Media|media
Events|calendar
Members|members';
  $export['og_menu_default_links_node_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_hide_create_option';
  $strongarm->value = 1;
  $export['og_menu_hide_create_option'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_hide_help';
  $strongarm->value = 0;
  $export['og_menu_hide_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_max_menus_per_group';
  $strongarm->value = '1';
  $export['og_menu_max_menus_per_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_show_blocks';
  $strongarm->value = 0;
  $export['og_menu_show_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_menu_show_nodetype';
  $strongarm->value = 0;
  $export['og_menu_show_nodetype'] = $strongarm;

  return $export;
}
