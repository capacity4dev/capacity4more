<?php
/**
 * @file
 * Theme functions for the c4m_features_header module.
 */

/**
 * Theme function for c4m header block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_header_menu(array $variables) {
  $output = '<div class="c4m-header-menu">';

  // Get c4m header menu.
  $c4m_header_menu = menu_tree('c4m-header');
  $output .= render($c4m_header_menu);

  $output .= '</div>';
  return $output;
}
