<?php
/**
 * @file
 * Views Search API area handler.
 */

/**
 * Area handlers are available to be placed in a views header and footer.
 * Spelling suggestions will only display if some are returned with the results.
 */
class c4m_search_views_handler_area_display_keywords extends views_handler_area {
  function render($empty = FALSE) {
    // Loop through the filters and find any text searches.
    $get = array();
    foreach ($this->view->filter as $key => $filter) {
      if ($filter instanceof SearchApiViewsHandlerFilterFulltext) {
        $get[] = $filter->value;
      }
    }

    return '<p>' . t('Showing results for %query.', array('%query' => implode(' ', $get))) . '</p>';
  }
}

