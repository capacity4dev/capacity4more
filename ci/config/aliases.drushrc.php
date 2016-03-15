<?php
# Drush alias settings used during Travis-CI builds.

$aliases['capacity4more'] = array(
  'uri' => 'http://127.0.0.1:8080',
  'root' => '/home/travis/build/capacity4dev/capacity4more/web',
  'db-url' => 'mysql://root:@127.0.0.1/drupal',
);
