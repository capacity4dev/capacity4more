<?php

/**
 * Theme function for website statistics summary block.
 * @param $variables
 * @return string
 */
function theme_c4m_website_statistics_summary($variables) {
  $output = '';

  if ($statistics = $variables['data']) {
    foreach ($statistics as $key => $stat) {
      if ($stat) {
        $list[$key] = array(
          'data'        => (isset($stat['count']) ? $stat['count'] . ' ' : '') .
                            (isset($stat['title']) ? $stat['title'] : ''),
          'class' => array('statistics-item', 'stats-' . $key),
        );
      }
    }

    $summary = array(
      '#theme'      => 'item_list',
      '#items'      => $list,
      '#attributes' => array(
        'class' => array('statistics-list'),
      ),
    );

    $output = render($summary);
  }

  return $output;
}
