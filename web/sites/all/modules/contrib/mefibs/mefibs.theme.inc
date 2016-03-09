<?php

/**
 * Theme the block listing in the mefibs config form in views ui.
 */
function theme_mefibs_views_ui_block_list(&$vars) {
  $form = $vars['form'];

  $header = array(
    '#',
    t('Name'),
    t('Machine name'),
    t('Filters'),
    t('Sorts'),
    t('Reset button'),
    t('Autosubmit'),
    t('Operations'),
  );
  $rows = array();

  $count = 1;
  foreach (element_children($form) as $key) {
    if (!is_numeric($key)) {
      continue;
    }
    $row = array();
    $row[] = $key + 1;

    if ($form[$key]['name']['#type'] == 'markup') {
      $row[] = drupal_render($form[$key]['name']);
      $row[] = drupal_render($form[$key]['machine_name']);
      $row[] = drupal_render($form[$key]['filters']);
      $row[] = drupal_render($form[$key]['sorts']);
      $row[] = drupal_render($form[$key]['reset_button']);
      $row[] = drupal_render($form[$key]['autosubmit']);
    }
    else {
      hide($form[$key]['actions']);
      $row[] = array(
        'data' => drupal_render($form[$key]),
        'colspan' => 6,
      );
      show($form[$key]['actions']);
    }
    
    $row[] = drupal_render($form[$key]['actions']);
    $rows[] = $row;
    $count++;
  }

  $output = theme('table', array(
    'rows' => $rows,
    'header' => $header,
  ));

  // Render the rest of the form and return.
  $output .= drupal_render_children($form);
  return $output;
}