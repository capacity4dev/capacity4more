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

  $facet_items = _c4m_search_get_facet_items('type');
  if (!$facet_items) {
    return NULL;
  }

  $facet_item = reset($facet_items);
  // Return if the first facet item is active.
  if ($facet_item['#active']) {
    return NULL;
  }

  // List of (global) content types. Have them keyed for later use.
  $types = array(
    'article' => 'article',
    'group' => 'group',
    'project' => 'project',
  );

  $facet_items = array_intersect_key($facet_items, $types);

  foreach ($facet_items as &$facet_item) {
    $text = format_plural($facet_item['#count'], "1 {$facet_item['#markup']}", "@count {$facet_item['#markup']}s");
    $facet_item = l($text, $facet_item['#path'], array(
      'query' => $facet_item['#query'],
    ));
  }

  $content['info'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('bg-info'),
    ),
  );

  if (isset($param['text'])) {
    $content['info']['term'] = array(
      '#type' => 'markup',
      '#markup' => t(
        'You searched for: %searchterm',
        array('%searchterm' => $param['text'])
      ),
    );
  }

  $content['info']['list'] = array(
    '#theme' => 'item_list',
    '#items' => $facet_items,
  );

  return array(
    'subject' => NULL,
    'content' => $content,
  );
}

/**
 * Returns the search overview info for a content type.
 *
 * @param string $type
 *   Content type.
 *
 * @return string
 *   Overview info.
 */
function _c4m_search_nodes_get_overview_info($type) {
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $type)
    ->entityCondition('published', NODE_PUBLISHED)
    ->count()
    ->execute();

  return format_plural($result, "1 {$type}", "@count {$type}s");
}
