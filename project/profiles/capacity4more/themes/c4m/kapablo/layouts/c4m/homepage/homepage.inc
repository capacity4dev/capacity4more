<?php
/**
 * @file
 * Bootstrap plugin definition.
 */

$plugin = array(
  'title' => t('Homepage'),
  'category' => t('Bootstrap'),
  'icon' => 'home_anonymous.png',
  'theme' => 'homepage',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left'),
    'right' => t('Right'),
    'bottom' => t('Bottom'),
  ),
);
