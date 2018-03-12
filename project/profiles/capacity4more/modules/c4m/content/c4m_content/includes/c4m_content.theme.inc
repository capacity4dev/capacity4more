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

  $list = array();
  $icons_table = array(
    'article' => 'fa-bullhorn',
    'comment' => 'fa-comments-o',
    'discussion' => 'fa-comments-o',
    // Same icon as in c4m_content_document_c4m_helper_entity_label_info().
    'document' => 'fa-file-o',
    'group' => 'fa-users',
    'photo' => 'fa-picture-o',
    'project' => 'fa-flag-checkered',
    'posts' => 'fa-comments-o',
    'event' => 'fa-calendar',
    'news' => 'fa-newspaper-o',
    'user' => 'fa-user',
    'wiki_page' => 'fa-wikipedia-w',
    'photo' => 'fa-file-image-o',
    'photoalbum' => 'fa-picture-o',
  );

  foreach ($statistics as $key => $stat) {
    if (!$stat) {
      continue;
    }

    // Format single/plural text.
    $text = '<i class="fa ' . $icons_table[$key] . '"></i> <span class="number--larger">' . c4m_content_ec_number_format($stat['count']) . '</span> ' . format_plural(
        $stat['count'],
        $stat['title']['singular'],
        $stat['title']['plural']
      );

    // Show as link?
    if (!empty($stat['link']['path'])) {
      $options = isset($stat['link']['options'])
        ? $stat['link']['options']
        : array();

      $options = array_merge(
        $options,
        array(
          'html' => TRUE,
        )
      );

      $text = l(
        $text,
        $stat['link']['path'],
        $options
      );
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
        implode(',', $stat_classes),
        'text-copy',
        'text-small',
      ),
    );
  }

  if (!empty($variables['more_link'])) {
    $list['more_link'] = [
      'data' => $variables['more_link'] . '<i class="fa fa-angle-right"></i>',
      'class' => ['see-more'],
    ];
  }

  $summary = array(
    '#theme' => 'item_list',
    '#items' => $list,
    '#attributes' => array(
      'class' => array('statistics-list'),
    ),
  );

  return render($summary);
}
