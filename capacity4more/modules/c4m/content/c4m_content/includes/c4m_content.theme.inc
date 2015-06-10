<?php
/**
 * @file
 * Theme functions for the c4m_content module.
 */

/**
 * Theme function for website statistics summary block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_website_statistics_summary(array $variables) {
  $statistics = $variables['data'];
  if (empty($statistics)) {
    return;
  }

  $flip = array('even' => 'odd', 'odd' => 'even');
  $class = 'even';
  $list = array();
  foreach ($statistics as $key => $stat) {
    if (!$stat) {
      continue;
    }

    $class = $flip[$class];

    // Format single/plural text.
    $text = $stat['count'] . ' ' . format_plural(
      $stat['count'],
      $stat['title']['singular'],
      $stat['title']['plural']
    );

    // Show as link?
    if (!empty($stat['link']['path'])) {
      $options = isset($stat['link']['options'])
        ? $stat['link']['options']
        : array();

      $text = l($text, $stat['link']['path'], $options);
    }

    // Add css classes defined in hook.
    $stat_classes = isset($stat['attributes']['class'])
      ? $stat['attributes']['class']
      : array();

    // Create a list item.
    $list[$key] = array(
      'data' => $text,
      'class' => array(
        'statistics-item',
        'stats-' . $key,
        $class,
        implode(',', $stat_classes),
      ),
    );
  }

  $summary = array(
    '#theme'      => 'item_list',
    '#items'      => $list,
    '#attributes' => array(
      'class' => array('statistics-list'),
    ),
  );

  return render($summary);
}

/**
 * Theme function for c4m footer block.
 *
 * @param array $variables
 *   Template variables.
 *
 * @return mixed
 *   Rendered output.
 */
function theme_c4m_footer(array $variables) {
  $output = '';

  // Get c4m footer navigation links.
  $footer_navigation = variable_get('c4m_footer_navigation_links');
  $navigation_html = '<div class="c4m-footer-navigation">';
  foreach ($footer_navigation as $link) {
    $navigation_html .= '<div class="c4m-footer-nav-link">';
    $navigation_html .= l(t($link['title']), $link['url']);
    $navigation_html .= '</div>';
  }
  $navigation_html .= '</div>';
  $output .= $navigation_html;

  // Get c4m footer menu.
  $c4m_footer_menu = menu_tree('c4m-footer');
  $output .= render($c4m_footer_menu);

  // Get c4m social media.
  $social_media = variable_get('c4m_social_media');
  $social_media_html = theme_c4m_social_media($social_media);
  $output .= $social_media_html;

  return $output;
}

/**
 * Function to theme the social media links.
 *
 * @param array $social_media
 *    Array with the social media info.
 *
 * @return string
 *    Rendered html of social media.
 */
function theme_c4m_social_media(array $social_media) {
  $output = '<div class="c4m-social-media">';
  foreach ($social_media as $key => $link) {
    $output .= '<div class="c4m-social-media-item c4m-social-media-' . $key . '">';
    $output .= l(t($link['title']), $link['url'],
                array('attributes' => array('target' => '_blank')));
    $output .= '</div>';
  }
  $output .= '</div>';

  return $output;
}
