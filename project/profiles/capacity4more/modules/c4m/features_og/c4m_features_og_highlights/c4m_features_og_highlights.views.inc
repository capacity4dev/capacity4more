<?php

/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_data().
 */
function c4m_features_og_highlights_views_data() {
  $data = [];

  $data['views']['c4m_features_og_highlights_handler_area_manage_link'] = [
    'title' => t('Manage highlights link'),
    'help' => t('Shows a link to manage highlights page.'),
    'area' => [
      'handler' => 'c4m_features_og_highlights_handler_area_manage_link',
    ],
  ];

  return $data;
}
