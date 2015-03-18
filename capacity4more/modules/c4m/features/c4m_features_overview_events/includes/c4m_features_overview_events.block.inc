<?php
/**
 * @file
 * All blocks for the c4m_features_overview_events module.
 */

/**
 * The links to event views.
 *
 * @return array
 */
function _c4m_features_overview_events_block_event_views_links() {
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
    $search_filters = array(
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
          'field' => 'type',
          'value' => 'event',
          'operator' => '=',
        ),
      ),
      '2' => array(
        'conjunction' => 'AND',
        'condition' => array(
          'field' => 'c4m_datetime_end:value2',
          'value' => time(),
          'operator' => $page['date_range_operator'],
        ),
      ),
    );

    // Execute search to retrieve counts only, so we set number of rows we
    // to be returned to 0.
    $search_options = array(
      '0' => array(
        'name' => 'limit',
        'value' => 0,
      )
    );
    $result = c4m_search_custom_search($search_filters, $search_options);

    $link_options = array('query' => drupal_get_query_parameters());

    $count = ' (' . $result['result count'] . ')';
    $items[] = array(
      'data' => l($page['text'] . $count, 'events/' . $key, $link_options),
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
