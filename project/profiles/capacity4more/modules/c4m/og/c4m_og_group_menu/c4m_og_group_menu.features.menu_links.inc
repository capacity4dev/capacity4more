<?php

/**
 * @file
 * c4m_og_group_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function c4m_og_group_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_og-menu-settings:admin/config/group/og_menu.
  $menu_links['management_og-menu-settings:admin/config/group/og_menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/group/og_menu',
    'router_path' => 'admin/config/group/og_menu',
    'link_title' => 'OG menu settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configuration for Organic groups menu',
      ),
      'identifier' => 'management_og-menu-settings:admin/config/group/og_menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_organic-groups:admin/config/group',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('OG menu settings');

  return $menu_links;
}
