<?php

/**
 * Database settings
 ******************************************************************************/
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'xxx',
      'username' => 'xxx',
      'password' => 'xxx',
      'host' => 'xxx',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

/**
 * Search settings
 ******************************************************************************/
$conf["c4m_search_server_overrides"] = array(
  'c4m_solr' => array(
    'name' => t('Solr Server'),
    'options' => array(
      'host' => "xxx",
      'port' => "xxx",
      'path' => "xxx",
    ),
  ),
);
$conf["search_api_attachments_tika_path"] = "xxx";

/**
 * Drupal settings
 ******************************************************************************/
$conf['site_mail'] = 'xxx';
$conf['file_temporary_path'] = 'xxx';
$conf['file_private_path'] = 'xxx';
$drupal_hash_salt = 'xxx';

/**
 * Migration settings (c4d source)
 ******************************************************************************/
$conf["c4d_migrate_db_hostname"] = "xxx";
$conf["c4d_migrate_db_database"] = "xxx";
$conf["c4d_migrate_db_username"] = "xxx";
$conf["c4d_migrate_db_password"] = "xxx";
$conf["c4d_migrate_files_root"] = "xxx";
