<?php

/**
 * @file
 * Template functions.
 */

/**
 * theme_menu_tree__MENU_ID().
 *
 * Add bootstrap classes to the menu to style it as a horizontal menu (default bootstrap).
 *
 * @param $variables
 *
 * @return string
 */
function kapablo_menu_tree__menu_group_menu($variables) {
  return '<ul class="menu nav nav-pills nav-justified" role="tablist">' . $variables['tree'] . '</ul>';
}
