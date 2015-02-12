<?php

// Plugin definition
$plugin = array(
  'title' => t('Homepage'),
  'category' => t('Bootstrap'),
  'icon' => 'home_anonymous.png',
  'theme' => 'homepage',
  'regions' => array(
    'content_top' => t('Top'),
    'sidebar_first' => t('Right'),
    'sidebar_second' => t('Left'),
    'content_bottom' => t('Bottom'),
  ),
);
