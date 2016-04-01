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

  // Get summary of (global) content types.
  $types = array(
    'article',
    'group',
    'project',
  );

  $item_list = array();
  foreach ($types as $type) {
    $item_list[] = _c4m_search_nodes_get_overview_info($type);
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
    '#items' => $item_list,
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
