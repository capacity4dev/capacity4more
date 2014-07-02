<?php

// Plugin definition
$plugin = array(
  'title' => t('Group page'),
  'category' => t('C4M'),
  'icon' => 'group.png',
  'theme' => 'group',
  'regions' => array(
    'title' => t('Title'),
    'image' => t('Image'),
    'created' => t('Created'),
    'description' => t('Description'),
    'activity_stream' => t('Activity Stream'),
  ),
);
