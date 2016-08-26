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
$conf["search_api_attachments_tika_jar"] = "xxx";

/**
 * Drupal settings
 ******************************************************************************/
$conf['site_mail'] = 'capfourdev.amplexor@gmail.com';
$conf['file_temporary_path'] = 'xxx';
$conf['file_public_path'] = 'xxx';
$conf['file_private_path'] = 'xxx';
$conf['cron_key'] = '_cSwoAXUnQ2hBtoh3hbX8yxkhbi609q5QeAB9O_BKPM';
$drupal_hash_salt = 'OMbDvLs285_CoevCU_qHPNLAaq2pj3ZkGPEA2pCooOU';

/**
 * Memcache settings
 * Comment out if Memcache is installed.
 ******************************************************************************/
//$conf["cache_default_class"] = "MemCacheDrupal";
//$conf["cache_backends"][] = "sites/all/modules/contrib/memcache/memcache.inc";
//$conf["lock_inc"] = "sites/all/modules/contrib/memcache/memcache-lock.inc";
//$conf["memcache_stampede_protection"] = TRUE;
//$conf["cache_class_cache_form"] = "DrupalDatabaseCache";
//$conf["page_cache_without_database"] = TRUE;
//$conf["page_cache_invoke_hooks"] = FALSE;
