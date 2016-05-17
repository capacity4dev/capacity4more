<?php

/**
 * @file
 * Drupal master config file.
 */

/**
 * Error logging
 ******************************************************************************/
$conf['error_level'] = 0;
ini_set('display_errors', FALSE);
ini_set('display_startup_errors', FALSE);

/**
 * PHP settings
 ******************************************************************************/
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);

/**
 * Database settings
 ******************************************************************************/
$databases = array();

/**
 * File system config
 ******************************************************************************/
$conf['file_temporary_path'] = '/tmp';
$conf['file_public_path'] = 'sites/default/files';
$conf['file_private_path'] = 'sites/default/files/private';

/**
 * Cache settings
 ******************************************************************************/
$conf['cache'] = TRUE;
$conf['block_cache'] = TRUE;
$conf['page_compression'] = TRUE;
$conf['preprocess_css'] = TRUE;
$conf['preprocess_js'] = TRUE;
$conf['cache_lifetime'] = 0;
$conf['page_cache_maximum_age'] = 10 * 60; // 10 minutes

// Memcache settings
$conf["cache_default_class"] = "MemCacheDrupal";
$conf["cache_backends"][] = "sites/all/modules/contrib/memcache/memcache.inc";
$conf["lock_inc"] = "sites/all/modules/contrib/memcache/memcache-lock.inc";
$conf["memcache_stampede_protection"] = TRUE;
$conf["cache_class_cache_form"] = "DrupalDatabaseCache";
$conf["page_cache_without_database"] = TRUE;
$conf["page_cache_invoke_hooks"] = FALSE;
$conf["memcache_servers"] = array("localhost:11211" => "default");

/**
 * Search settings
 ******************************************************************************/
$conf["c4m_search_server_overrides"] = array(
  'c4m_solr' => array(
    'name' => t('Solr Server'),
    'options' => array(
      'host' => "127.0.0.1",
      'port' => "8983",
      'path' => "",
    ),
  ),
);
$conf["search_api_attachments_tika_jar"] = "tika-app-1.12.jar";

/**
 * Drupal settings
 ******************************************************************************/
$update_free_access = FALSE;
$conf['theme_debug'] = FALSE;
$drupal_hash_salt = 'xKBlaoUWeBTAyBssjckSpt4hVfnwW-h2UpjY4Omk51M';
$conf['site_mail'] = 'no-reply@capacity4dev.eu';

/**
 * Other settings
 ******************************************************************************/
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';
