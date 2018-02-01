<?php

/**
 * @file
 * Handler to add a node add button to a view area.
 */

/**
 * Views area handler to offer search_api_sorts sort block to views.
 *
 * @ingroup views_area_handlers
 */
// @codingStandardsIgnoreLine
class c4m_views_handler_area_search_api_sorts extends views_handler_area {

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    $block = module_invoke('search_api_sorts', 'block_view', 'search-sorts');
    // Allow modules to alter the search sorts.
    drupal_alter('search_api_sorts', $block, $this->view);
    if (!$block) {
      return;
    }

    return render($block['content']);
  }

}
