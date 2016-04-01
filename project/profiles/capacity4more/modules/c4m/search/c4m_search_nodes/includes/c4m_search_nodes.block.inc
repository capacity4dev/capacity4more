<?php
/**
 * @file
 * Block specific functionality like block definitions & overrides.
 */

/**
 * Callback for the search_overview block.
 */
function _c4m_search_nodes_block_search_overview() {
  // Get active query parameters.
  $param = drupal_get_query_parameters();

  $search_term = (bool) (isset($param['text']) && strlen($param['text']) > 0);

  $facet_items = _c4m_search_get_facet_items('type');
  if (!$facet_items && !$search_term) {
    return NULL;
  }

  $facet_item = reset($facet_items);
  // Return if the first facet item is active.
  if ($facet_item['#active'] && !$search_term) {
    return NULL;
  }

  // List of (global) content types. Have them keyed for later use.
  $types = array(
    'article' => 'article',
    'group' => 'group',
    'project' => 'project',
  );

  $content['info'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('well', 'well-sm', 'bg-info'),
    ),
  );

  if ($search_term) {
    $content['info']['term'] = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#value' => t(
        'You searched for: %searchterm',
        array('%searchterm' => $param['text'])
      ),
    );
  }

  if (!$facet_item['#active']) {
    $facet_items = array_intersect_key($facet_items, $types);
    foreach ($facet_items as &$facet_item) {
      $text = format_plural(
        $facet_item['#count'],
        "1 {$facet_item['#markup']}",
        "@count {$facet_item['#markup']}s"
      );
      $facet_item = l(
        $text,
        $facet_item['#path'],
        array(
          'query' => $facet_item['#query'],
        )
      );
    }

    $content['info']['list'] = array(
      'description' => array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => t('Refine your search:'),
        '#attributes' => array('class' => 'search--refine'),
      ),
      'list' => array(
        '#theme' => 'item_list',
        '#items' => $facet_items,
        '#attributes' => array('class' => 'list-inline'),
      ),
    );
  }


  return array(
    'subject' => NULL,
    'content' => $content,
  );
}
