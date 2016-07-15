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

  // Links to the upcoming and past events page.
  $pages = array(
    'upcoming' => array(
      'text' => t('Upcoming'),
    ),
    'past' => array(
      'text' => t('Past'),
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
