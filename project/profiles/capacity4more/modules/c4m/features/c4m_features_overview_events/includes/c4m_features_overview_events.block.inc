<?php

/**
 * @file
 * All blocks for the c4m_features_overview_events module.
 */

/**
 * The links to event views.
 *
 * @return mixed
 *   Block definition.
 */
function _c4m_features_overview_events_block_event_views_links() {
  // Link to the general overview page.
  $items[] = array(
    'data' => l(t('Overview'), 'events'),
    'class' => array('leaf'),
  );

  $upcoming_events_count = _c4m_features_overview_events_count_via_views('upcoming');
  $past_events_count = _c4m_features_overview_events_count_via_views('past');

  // Links to the upcoming and past events page.
  $pages = array(
    'upcoming' => array(
      'text' => t('Upcoming (@count)', array('@count' => $upcoming_events_count)),
    ),
    'past' => array(
      'text' => t('Past (@count)', array('@count' => $past_events_count)),
    ),
  );

  foreach ($pages as $key => $page) {
    $attributes = array('attributes' => array('class' => array($key . '-events')));
    $items[] = array(
      'data' => l($page['text'], 'events/' . $key, $attributes),
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

/**
 * Total number of events.
 *
 * @return mixed
 *   Block definition.
 */
function _c4m_features_overview_events_block_event_total_count() {

  $upcoming_events_count = _c4m_features_overview_events_count_via_views('upcoming');
  $past_events_count = _c4m_features_overview_events_count_via_views('past');

  $total_events_count = $upcoming_events_count + $past_events_count;

  $content = theme('html_tag', array(
    'element' => array(
      '#tag' => 'h2',
      '#value' => 'EVENTS (' . $total_events_count . ' in total)',
    ),
  ));

  return array(
    'subject' => '',
    'content' =>  $content,
  );
}
