<?php

/**
 * @file
 * Drupal site-specific configuration file to override or complement the
 * configuration in the config.inc file.
 *
 * PRD
 */

/**
 * Database settings
 ******************************************************************************/
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'drupal',
      'username' => 'root',
      'password' => '',
      'host' => '127.0.0.1',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

/**
 * Search settings
 ******************************************************************************/
$conf["search_api_attachments_tika_path"] = "/home/travis/build/capacity4dev/capacity4more/tika/";
