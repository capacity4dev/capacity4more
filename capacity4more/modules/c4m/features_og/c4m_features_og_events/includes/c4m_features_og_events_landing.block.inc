<?php
/**
 * Override blocks.
 *
 * @param array $data
 *   The render array.
 * @param stdClass $block
 *   The block information for who the block is being displayed.
 */
function _c4m_features_og_events_landing_block_view_alter(&$data, $block) {
  $info = array(
    'Facet API: Search service: Search Nodes : Date » End date' => 'Date ranges facet',
  );
  if (!empty($block->info) &&
      array_key_exists($block->info, $info)) {
    $block_title = '';
    switch ($info[$block->info]) {
      case 'Date ranges facet':
        // Remove block title and add link to current page.
        $block_title = '';
        // Add link to Overview
        $item['class'] = 'leaf';
        $item['data'] = l(t('Overview'), 'events');
        array_unshift($data['content']['c4m_datetime_end:value2']['#items'], $item);
        break;
    }
    $data['subject'] = $block_title;
  }
}
