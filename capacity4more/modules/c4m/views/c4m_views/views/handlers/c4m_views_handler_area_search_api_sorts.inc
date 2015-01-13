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
class c4m_views_handler_area_search_api_sorts extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Find out the information to render.
   */
  function render($empty = FALSE) {
    $block = module_invoke('search_api_sorts', 'block_view', 'search-sorts');
    // Allow modules to alter the search sorts.
    drupal_alter('search_api_sorts', $block, $this->view);
    if (!$block) {
      return;
    }

    return render($block['content']);
  }
}

