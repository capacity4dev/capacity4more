<?php

/**
 * @file
 * c4m_vocab_widget.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function c4m_vocab_widget_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'taxonomy_terms';
  $path_breadcrumb->name = 'Taxonomy terms';
  $path_breadcrumb->path = 'taxonomy/term/%termidnumber';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%termidnumber:name',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(
      'termidnumber' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            7 => 0,
            9 => 0,
            11 => 0,
            13 => 0,
            15 => 0,
            17 => 0,
            19 => 0,
            21 => 0,
            23 => 0,
            25 => 0,
            27 => 0,
            29 => 0,
            31 => 0,
            33 => 0,
            35 => 0,
            37 => 0,
            39 => 0,
            41 => 0,
            4 => 0,
            5 => 0,
            1 => 0,
            8 => 0,
            10 => 0,
            12 => 0,
            14 => 0,
            16 => 0,
            18 => 0,
            20 => 0,
            22 => 0,
            24 => 0,
            26 => 0,
            28 => 0,
            30 => 0,
            32 => 0,
            34 => 0,
            36 => 0,
            38 => 0,
            40 => 0,
            42 => 0,
            3 => 0,
            2 => 0,
            6 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -83;
  $export['taxonomy_terms'] = $path_breadcrumb;

  return $export;
}
