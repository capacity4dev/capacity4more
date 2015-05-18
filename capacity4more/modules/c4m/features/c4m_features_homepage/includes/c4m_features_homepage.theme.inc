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
        $text = format_plural($stat['count'], $stat['title'][0], $stat['title'][1]);
        $list[$key] = array(
          'data'        => $stat['count'] . ' ' . $text,
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
