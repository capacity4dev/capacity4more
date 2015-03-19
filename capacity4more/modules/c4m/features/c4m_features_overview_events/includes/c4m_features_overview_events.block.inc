<?php
/**
 * @file
 * All blocks for the c4m_features_overview_events module.
 */

/**
 * Override blocks.
 *
 * @param array $data
 *   The render array.
 * @param stdClass $block
 *   The block information for who the block is being displayed.
 */
function _c4m_features_overview_events_landing_block_view_alter(&$data, $block) {
  $info = array(
    'Facet API: Search service: Search Nodes : Date » End date' => 'Date ranges facet',
  );
  if (!empty($block->info) && array_key_exists($block->info, $info)) {
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
        if ($data['content']['c4m_datetime_end:value2']['#items']) {
          array_unshift($data['content']['c4m_datetime_end:value2']['#items'], $item);
        }
        break;
    }
    $data['subject'] = $block_title;
  }
}

/**
 * A block with filters for event views.
 *
 * @return array
 */
function _c4m_features_overview_events_block_event_filter() {
  // Hide filter block for anonymous users.
  if (user_is_anonymous()) {
    return;
  }
  return array(
    'subject' => NULL,
    'content' => drupal_get_form('_c4m_features_overview_events_block_event_filter_form'),
  );
}

/**
 * Create form to filter event views.
 *
 * @return mixed
 */
function _c4m_features_overview_events_block_event_filter_form() {
  // Remove unique form token so request can be cached. This is accompanied by
  // code in a hook_form_alter to ignore the token and remove the build_id.
  $form['#token'] = FALSE;
  $form['#method'] = 'get';
  $form['#action'] = request_uri();

  // Create options.
  $options = array();
  $groups = og_get_groups_by_user();
  if (!empty($groups)) {
    $options += array('groups' => t('My groups'));
  }
  $options += array(
    'interests' => t('My interests'),
    'showAll' => t('Show all')
  );

  // Create links for each option.
  $params = drupal_get_query_parameters();
  foreach ($options as $key => $option) {
    $query = array_merge($params, array('filter' => $key));
    $options[$key] = l($option, current_path(), array('query' => $query));
  }

  $default_value = !empty($_GET['filter']) ? $_GET['filter'] : 'showAll';

  if (!array_key_exists($default_value, $options)) {
    $default_value = 'showAll';
  }

  $form['filter'] = array(
    '#type' => 'radios',
    '#title' => t('Filter by'),
    '#options' => $options,
    '#default_value' => $default_value,
    '#attributes' => array('onchange' => 'this.form.submit();'),
  );

  return $form;
}

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
