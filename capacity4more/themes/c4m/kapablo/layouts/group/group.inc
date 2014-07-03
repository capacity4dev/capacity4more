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
    'group_owner' => t('Group Owner'),
    'members_count' => t('Members Count'),
    'topics' => t('Topics'),
    'highlights' => t('Highlights'),
  ),
);
