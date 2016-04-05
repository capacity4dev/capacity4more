<?php
/**
 * @file
 * Pager functionality.
 */

/**
 * Returns HTML for a query pager.
 *
 * Menu callbacks that display paged query results should call theme('pager') to
 * retrieve a pager control so that users can view other results. Format a list
 * of nearby pages with additional query results.
 *
 * @param array $variables
 *   An associative array containing:
 *   - tags: An array of labels for the controls in the pager.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *   - quantity: The number of pages in the list.
 *
 * @return string
 *   The rendered pager.
 *
 * @ingroup themeable
 */
function kapablo_pager(array $variables) {
  $tags = array(
    t('First'),
    t('Previous'),
    t('Next'),
    t('Last'),
  );

  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  $li_first = theme(
    'pager_first',
    array(
      'text' => (isset($tags[0]) ? $tags[0] : t('« first')),
      'element' => $element,
      'parameters' => $parameters,
    )
  );
  $li_previous = theme(
    'pager_previous',
    array(
      'text' => (isset($tags[1]) ? $tags[1] : t('previous')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    )
  );
  $li_next = theme(
    'pager_next',
    array(
      'text' => (isset($tags[2]) ? $tags[2] : t('next')),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters,
    )
  );
  $li_last = theme(
    'pager_last',
    array(
      'text' => (isset($tags[3]) ? $tags[3] : t('last »')),
      'element' => $element,
      'parameters' => $parameters,
    )
  );

  if ($pager_total[$element] > 1) {
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }

      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme(
              'pager_previous',
              array(
                'text' => $i,
                'element' => $element,
                'interval' => ($pager_current - $i),
                'parameters' => $parameters,
              )
            ),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme(
              'pager_next',
              array(
                'text' => $i,
                'element' => $element,
                'interval' => ($i - $pager_current),
                'parameters' => $parameters,
              )
            ),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }

    $list = theme(
      'item_list',
      array(
        'items' => $items,
        'attributes' => array(
          'class' => array(
            'pager',
            'list-inline',
            'text-center',
          ),
        ),
      )
    );
    $output = array(
      '<div class="row pager--wrapper">',
      '  <h2 class="element-invisible">' . t('Pages') . '</h2>',
      '  <div class="hidden-xs hidden-sm col-md-2 pager-first">' . $li_first . '</div>',
      '  <div class="col-xs-2 col-md-2 pager-previous">' . $li_previous . '</div>',
      '  <div class="col-xs-8 col-md-4 pager-content">' . $list . '</div>',
      '  <div class="col-xs-2 col-md-2 pager-next">' . $li_next . '</div>',
      '  <div class="hidden-xs hidden-sm col-md-2 pager-last">' . $li_last . '</div>',
      '</div>',
    );

    return implode(PHP_EOL, $output);
  }
}
