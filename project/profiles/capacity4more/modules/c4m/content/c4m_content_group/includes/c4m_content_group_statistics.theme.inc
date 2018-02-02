<?php

/**
 * @file
 * Display suite field to display the group statistics.
 */

/**
 * Display function to display the group statistics.
 */
function c4m_content_group_statistics($field) {
  $data = c4m_content_get_current_group_statistics();
  if (empty($data)) {
    return;
  }

  $group = c4m_og_current_group();
  $options = array(
    'absolute' => TRUE,
    'purl' => array('enabled' => TRUE),
  );
  $path = 'group/node/' . $group->nid . '/admin/statistics';
  $more_link = l(t("See more"), $path, $options);

  $statistics = array(
    '#theme' => 'c4m_website_statistics_summary',
    '#data' => $data,
    '#more_link' => $more_link,
  );
  return render($statistics);
}
