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
  //  // @TODO: Add print, IE7, IE8 specific CSS files.
  //  // Add print stylesheet.
  //  $print = $theme_path . '/css/print.css';
  //  $css[$print] = array(
  //    'data' => $print,
  //    'type' => 'file',
  //    'every_page' => TRUE,
  //    'media' => 'print',
  //    'preprocess' => FALSE,
  //    'group' => CSS_THEME,
  //    'browsers' => array('!IE' => TRUE, 'IE' => TRUE),
  //    'weight' => 50,
  //  );
  //
  //  // Add IE 8 stylesheet.
  //  $ie8 = $theme_path . '/css/lt-ie9.css';
  //  $css[$ie8] = array(
  //    'data' => $ie8,
  //    'type' => 'file',
  //    'every_page' => TRUE,
  //    'media' => 'all',
  //    'preprocess' => FALSE,
  //    'group' => CSS_THEME,
  //    'browsers' => array('IE' => 'lt IE 9', '!IE' => FALSE),
  //    'weight' => 10,
  //  );
  //
  //  // Add IE 7 stylesheet.
  //  $ie7 = $theme_path . '/css/lt-ie8.css';
  //  $css[$ie7] = array(
  //    'data' => $ie7,
  //    'type' => 'file',
  //    'every_page' => TRUE,
  //    'media' => 'all',
  //    'preprocess' => FALSE,
  //    'group' => CSS_THEME,
  //    'browsers' => array('IE' => 'lt IE 8', '!IE' => FALSE),
  //    'weight' => 15,
  //  );

  $exclude = array();

  // @TODO: Remove obsolete CSS files.

  foreach ($exclude as $path) {
    if (isset($css[$path])) {
      unset($css[$path]);
    }
  }
}
