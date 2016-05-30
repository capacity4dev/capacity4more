<?php

/**
 * @file
 * Blocks functionalities.
 */

/**
 * Implements hook_block_info().
 */
function c4m_search_og_block_info() {
  $blocks['c4m_search_group_form'] = array(
    'info' => t('Search group'),
    'cache' => DRUPAL_NO_CACHE,
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function c4m_search_og_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'c4m_search_group_form':
      // Find current group ID.
      $gid = c4m_og_current_group_id();

      // Assemble search URL using current group.
      $redirect_url = url('searchgroup', array(
        'purl' => array(
          'provider' => 'og_purl|node',
          'id' => $gid,
        ),
      ));

      // Collect search redirect form using group search URL.
      $form = drupal_get_form('c4m_search_redirect_form', $redirect_url, NULL, t('Search in group...'));
      $block['content'] = drupal_render($form);
      break;
  }

  return $block;
}
