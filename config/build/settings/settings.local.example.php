<?php
// @codingStandardsIgnoreFile

/**
 * @file
 * Drupal config overrides.
 */

/**
 * Error logging
 * Uncomment to enable verbose mode.
 ******************************************************************************/
// $conf['error_level'] = 2;
// ini_set('display_errors', TRUE);
// ini_set('display_startup_errors', TRUE);
// error_reporting(E_ALL);

/**
 * Database settings.
 ******************************************************************************/
$databases = array(
  'default' => array(
    'default' => array(
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
 * Search settings.
 ******************************************************************************/
$conf["c4m_search_server_overrides"] = array(
  'c4m_solr' => array(
    'name' => t('Solr Server'),
    'options' => array(
      'host' => "xxx",
      'port' => "xxx",
// Solr server URI, e.g.: http://solr-server.eu:8983/solr/capacity4more
      'path' => "xxx",
    ),
  ),
);
// The full path to tika directory. All library jars must be in the same directory.
// E.g. /var/apache-tika-4.0/.
$conf["search_api_attachments_tika_path"] = "xxx";

// The name of the tika CLI application jar file, e.g. tika-app-1.4.jar.
$conf["search_api_attachments_tika_jar"] = "xxx";

/**
 * Drupal settings.
 ******************************************************************************/
// FROM mail address for all emails send by the platform.
$conf['site_mail'] = 'capfourdev.amplexor@gmail.com';

// Absolute path.
$conf['file_temporary_path'] = 'xxx';
// Path relative to docroot.
$conf['file_public_path'] = 'xxx';
// Path relative to docroot.
$conf['file_private_path'] = 'xxx';
$conf['cron_key'] = '_cSwoAXUnQ2hBtoh3hbX8yxkhbi609q5QeAB9O_BKPM';
$drupal_hash_salt = 'OMbDvLs285_CoevCU_qHPNLAaq2pj3ZkGPEA2pCooOU';

// Uncomment and configure if Drupal is ran in a subdirectory.
// $base_url = 'http://www.example.com/c4d';

/**
 * Cookie settings.
 * Drupal automatically generates a unique session cookie name for each site
 * based on its full domain name. If you have multiple domains pointing at the
 * same Drupal site, you can either redirect them all to a single domain (see
 * comment in .htaccess), or uncomment the line below and specify their shared
 * base domain. Doing so assures that users remain logged in as they cross
 * between your various domains. Make sure to always start the $cookie_domain
 * with a leading dot, as per RFC 2109.
 ******************************************************************************/
// $cookie_domain = '.example.com';

/**
 * Memcache settings
 * Uncomment if Memcache is installed.
 ******************************************************************************/
// $conf["cache_default_class"] = "MemCacheDrupal";
// $conf["cache_backends"][] = "sites/all/modules/contrib/memcache/memcache.inc";
// $conf["lock_inc"] = "sites/all/modules/contrib/memcache/memcache-lock.inc";
// $conf["memcache_stampede_protection"] = TRUE;
// $conf["cache_class_cache_form"] = "DrupalDatabaseCache";
// $conf["page_cache_without_database"] = TRUE;
// $conf["page_cache_invoke_hooks"] = FALSE;
