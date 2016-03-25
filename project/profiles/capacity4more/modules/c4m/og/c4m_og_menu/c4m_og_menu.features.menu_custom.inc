<?php
/**
 * @file
 * c4m_og_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function c4m_og_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: c4m-og-menu.
  $menus['c4m-og-menu'] = array(
    'menu_name' => 'c4m-og-menu',
    'title' => 'Group Menu',
    'description' => '(Sub-)navigation inside OG context (group or project). Includes the different features per group.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('(Sub-)navigation inside OG context (group or project). Includes the different features per group.');
  t('Group Menu');

  return $menus;
}
