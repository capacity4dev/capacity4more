<?php

/**
 * @file
 * Drupal site-specific configuration file to override or complement the
 * configuration in the config.inc file.
 *
 * ACC
 */

/**
 * Database settings
 ******************************************************************************/
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'capacity4more_acc',
      'username' => 'cap4more_acc',
      'password' => 'CmljKUgFobpqgpg5xv9vSKvM1iU9gehM',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

/**
 * Search settings
 ******************************************************************************/
$conf["c4m_search_server_overrides"]['c4m_solr']['options']['path'] = "/solr/capacity4more-acc";
$conf["search_api_attachments_tika_path"] = "/var/www/capacity4more-acc.dev.amplexor.com/bin";

/**
 * Overrides
 ******************************************************************************/
$drupal_hash_salt = 'OdKhlPGLWxDWKBmAZ2tjjECMu6j-llKxWFr7UFZwux4';

/**
 * Migration settings (c4d source)
 ******************************************************************************/
$conf["c4d_migrate_db_hostname"] = "localhost";
$conf["c4d_migrate_db_database"] = "capacity4more_acc_drupal6";
$conf["c4d_migrate_db_username"] = "cap4more_acc";
$conf["c4d_migrate_db_password"] = "CmljKUgFobpqgpg5xv9vSKvM1iU9gehM";
$conf["c4d_migrate_files_root"] = "/var/www/capacity4more-acc.dev.amplexor.com/shared/d6-files/";
