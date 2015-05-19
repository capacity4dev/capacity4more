<?php

/**
 * Theme function for website statistics summary block.
 * @param $variables
 * @return string
 */
function theme_c4m_website_statistics_summary($variables) {
  $output = '';
  if ($statistics = $variables['data']) {
    $flip = array('even' => 'odd', 'odd' => 'even');
    $class = 'even';
    foreach ($statistics as $key => $stat) {
      if ($stat) {
        $class = $flip [$class];
        $text = format_plural($stat['count'], $stat['title'][0], $stat['title'][1]);
        $list[$key] = array(
          'data'        => $stat['count'] . ' ' . $text,
          'class' => array('statistics-item', 'stats-' . $key, $class),
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
