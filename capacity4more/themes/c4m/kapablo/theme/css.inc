<?php
/**
 * @file
 * All CSS related manipulations to the theme.
 */

/**
 * Implements hook_css_alter().
 *
 * Add CSS.
 *
 * @see hook_css_alter()
 */
function kapablo_css_alter(&$css) {
  $theme_path = drupal_get_path('theme', 'kapablo');

  // Add default stylesheet.
  $style = $theme_path . '/css/style.css';

  $css[$style] = array(
    'data'       => $style,
    'type'       => 'file',
    'every_page' => TRUE,
    'media'      => 'all',
    'preprocess' => FALSE,
    'group'      => CSS_THEME,
    'browsers'   => array('!IE' => TRUE, 'IE' => 'gte IE 9'),
    'weight'     => 5,
  );

  $css['fontAwesome'] = array(
    'data'       => libraries_get_path('font_awesome') . '/css/font-awesome.min.css',
    'type'       => 'file',
    'every_page' => TRUE,
    'media'      => 'all',
    'preprocess' => FALSE,
    'group'      => CSS_THEME,
    'browsers'   => array('!IE' => TRUE, 'IE' => 'gte IE 9'),
    'weight'     => 4,
  );

  $exclude = array();

  foreach ($exclude as $path) {
    if (isset($css[$path])) {
      unset($css[$path]);
    }
  }
}
