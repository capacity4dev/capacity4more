<?php

/**
 * @file
 * Block definitions for the c4m_features_og_events module.
 */

/**
 * The links to event views.
 *
 * @return mixed
 *   The block definition.
 */
function _c4m_features_og_events_block_event_views_links() {
  $group = c4m_og_current_group();
  if (!$group) {
    return;
  }

  // Link to the general overview page.
  $items[] = array(
    'data' => l(t('Overview'), 'calendar'),
    'class' => array('leaf'),
  );

  $upcoming_events_count = _c4m_features_og_events_count_via_views('upcoming');
  $past_events_count = _c4m_features_og_events_count_via_views('past');
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
      'data' => l($page['text'], 'calendar/' . $key, $attributes),
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
