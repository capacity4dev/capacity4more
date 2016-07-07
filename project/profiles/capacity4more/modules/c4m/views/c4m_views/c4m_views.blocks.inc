<?php

/**
 * @file
 * C4M Views module - block functionalities.
 */

/**
 * Implements hook_block_info().
 */
function c4m_views_block_info() {
  $blocks['views_page_title'] = array(
    'info' => t('Views page title'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function c4m_views_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'views_page_title':
      if ($view_title = _c4m_views_get_current_views_page_title()) {
        $block['content'] = $view_title;
      }
      break;
  }

  return $block;
}
