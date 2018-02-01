<?php

/**
 * @file
 * Definition of c4m_views_handler_area_items_per_page.
 */

/**
 * Views area handler that shows links to control the number of items per page.
 *
 * @ingroup views_area_handlers
 */
// @codingStandardsIgnoreLine
class c4m_views_handler_area_items_per_page extends views_handler_area {

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    $items_per_page = preg_split('/,\s+/', $this->query->pager->options['expose']['items_per_page_options']);

    $search_params = drupal_get_query_parameters();
    $current_value = $this->view->exposed_data['items_per_page'];
    if (isset($search_params['items_per_page'])) {
      $current_value = $search_params['items_per_page'];
      unset($search_params['items_per_page']);
    }

    $links = [];
    foreach ($items_per_page as $value) {
      if ($current_value == $value) {
        $links[$value] = $value;
      }
      else {
        $links[$value] = l($value, $this->view->display_handler->options['path'], ['query' => $search_params + ['items_per_page' => $value]]);
      }
      if ($value > $this->view->total_rows) {
        // Stop the cycle.
        // If we have 15 items, we want to stop at 20 not at 10.
        break;
      }
    }
    if (!$links) {
      return '';
    }
    $output = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['items-per-page-container'],
      ],
      0 => [
        ['#markup' => t('View')],
        [
          '#theme' => 'item_list',
          '#attributes' => [
            'class' => ['list-unstyled', 'list-inline'],
          ],
          '#items' => $links,
        ],
      ],
    ];
    return drupal_render($output);
  }

}
