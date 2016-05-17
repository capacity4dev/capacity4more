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
$databases = array ();

/**
 * Search settings
 ******************************************************************************/
$conf["c4m_search_server_overrides"]['c4m_solr']['options']['path'] = "/solr/capacity4more-prd";
$conf["search_api_attachments_tika_path"] = "/var/www/capacity4more-prd.dev.amplexor.com/bin";

/**
 * Overrides
 ******************************************************************************/
$drupal_hash_salt = 'xKBlaoUWeBTAyBssjckSpt4hVfnwW-h2UpjY4Omk51M';

/**
 * Migration settings (c4d source)
 ******************************************************************************/
$conf["c4d_migrate_db_hostname"] = "localhost";
$conf["c4d_migrate_db_database"] = "capacity4more_acc_drupal6";
$conf["c4d_migrate_db_username"] = "cap4more_acc";
$conf["c4d_migrate_db_password"] = "CmljKUgFobpqgpg5xv9vSKvM1iU9gehM";
$conf["c4d_migrate_files_root"] = "/var/www/capacity4more-acc.dev.amplexor.com/shared/d6-files/";
