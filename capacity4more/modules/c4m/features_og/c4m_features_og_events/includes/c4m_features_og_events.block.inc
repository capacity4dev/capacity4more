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
        // Make sure 'upcoming' comes before past.
        if (FALSE !== strpos($data['content']['c4m_datetime_end:value2']['#items'][0]['data'], 'past-events')) {
          // Move 'past' to the end of the list of items.
          $data['content']['c4m_datetime_end:value2']['#items'][] =
            array_shift($data['content']['c4m_datetime_end:value2']['#items']);
        }
        // Add link to Overview
        $item['class'] = 'leaf';
        $item['data'] = l(t('Overview'), 'events');
        array_unshift($data['content']['c4m_datetime_end:value2']['#items'], $item);
        break;
    }
    $data['subject'] = $block_title;
  }
}

/**
 * The links to event views.
 *
 * @return array
 */
function _c4m_features_og_events_block_event_views_links() {
  $group = c4m_og_current_group();

  // Link to the general overview page.
  $items[] = array(
    'data' => l(t('Overview'), 'events'),
    'class' => array('leaf'),
  );

  // Links to the upcoming and past events page.
  $pages = array(
    'upcoming' => array(
      'text' => t('Upcoming'),
      'date_range_operator' => '>=',
    ),
    'past' => array(
      'text' => t('Past'),
      'date_range_operator' => '<',
    ),
  );

  foreach ($pages as $key => $page) {
    $filters = array(
      '0' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'status',
          'value' => 1,
          'operator' => '=',
        ),
      ),
      '1' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'og_group_ref',
          'value' => $group->nid,
          'operator' => '=',
        ),
      ),
      '2' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'type',
          'value' => 'event',
          'operator' => '=',
        ),
      ),
      '3' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'c4m_datetime_end:value2',
          'value' => time(),
          'operator' => $page['date_range_operator'],
        ),
      ),
    );

    $result = c4m_search_custom_search($filters);

    $count = !empty($result['result count']) ? ' (' . $result['result count'] .
      ')' : '';
    $items[] = array(
      'data' => l($page['text'] . $count, 'events/' . $key),
      'class' => array('leaf'),
    );
  }

  $list = theme_item_list(
    array(
    'title' => NULL,
    'type' => 'ul',
    'items' => $items,
    'attributes' => array('class' => array('event-views-links')),
    )
  );
  return array(
    'subject' => '',
    'content' => $list,
  );
}

