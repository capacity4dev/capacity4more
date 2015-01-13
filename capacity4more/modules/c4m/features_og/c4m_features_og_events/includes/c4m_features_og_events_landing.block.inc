<?php
/**
 * Override facet blocks
 *
 * We are currently only using the facet blocks to have the item counts.
 * We replace the facet links with links to the views of
 * upcoming events: events/upcoming
 * past events: events/past
 *
 * but we keep the counts of course.
 *
 * @param array $data
 *   The render array.
 * @param stdClass $block
 *   The block information for who the block is being displayed.
 */
function _c4m_features_og_events_landing_block_view_alter(&$data, $block) {
return;
  $info = array(
    'Facet API: Search service: Search Nodes : Date » Start date' => 'upcoming',
    'Facet API: Search service: Search Nodes : Date » End date' => 'past',
  );
  if (!empty($block->info) &&
      array_key_exists($block->info, $info)) {
    // We will alter the facet block title too.
    $block_title = '';
    // We only use these facets for the counts. Retrieve the count and
    // recreate the links.
    // Pattern to retrieve the count. Looking for a decimal between parentheses.
    $pattern = '/(.*)\(([^(|)]d*?)\)(.*)$/';
    switch ($info[$block->info]) {
      case 'upcoming':
        $date_field = 'c4m_datetime_end:value';
        $link_title = t('Upcoming');
        $block_title = t('Overview');
        $link_options = array(
          'attributes' => array(
            'class' => array(
              'upcoming-events')
          )
        );
        break;
      case 'past':
        $date_field = 'c4m_datetime_end:value2';
        $link_title = t('Past');
        $link_options = array(
          'attributes' => array(
            'class' => array(
              'past-events')
          )
        );
        break;
    }
    $count = preg_replace($pattern, '$2',
      $data['content'][$date_field]['#items'][0]['data']);
    $data['content'][$date_field]['#items'][0]['data'] =
      l($link_title . ' (' . $count . ')', 'events/' . $info[$block->info],
        $link_options);
    $data['subject'] = $block_title;
  }
}

