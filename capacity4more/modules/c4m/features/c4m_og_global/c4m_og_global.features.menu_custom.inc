<?php
/**
 * @file
 * c4m_og_global.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function c4m_og_global_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-group-menu.
  $menus['menu-group-menu'] = array(
    'menu_name' => 'menu-group-menu',
    'title' => 'Group Menu',
    'description' => '(Sub-)navigation inside OG context (group or project). Includes the different features per group.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('(Sub-)navigation inside OG context (group or project). Includes the different features per group.');
  t('Group Menu');


  return $menus;
}
