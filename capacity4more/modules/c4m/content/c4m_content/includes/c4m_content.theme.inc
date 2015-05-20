<?php
/**
 * @file
 * Theme functions for the c4m_content module.
 */

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
        $class = $flip[$class];
        // Format single/plural text.
        $text = format_plural($stat['count'],
                              $stat['title']['singular'],
                              $stat['title']['plural']);
        // Add css classes defined in hook.
        $stat_classes = isset($stat['attributes']['class']) ? $stat['attributes']['class']
                                                            : array();
        // Create a list item.
        $list[$key] = array(
          'data'        => $stat['count'] . ' ' . $text,
          'class' => array('statistics-item',
                            'stats-' . $key,
                            $class,
                            implode(',', $stat_classes)),
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
