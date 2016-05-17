<?php

/**
 * @file
 * Drupal site-specific configuration file to override or complement the
 * configuration in the config.inc file.
 *
 * TST
 */

/**
 * Error logging
 ******************************************************************************/
$conf['error_level'] = 2;
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);
error_reporting(E_ALL);

/**
 * Database settings
 ******************************************************************************/
$databases = array (
  'default' => array (
    'default' => array (
      'database' => 'capacity4more_tst',
      'username' => 'cap4more_tst',
      'password' => 'qE64WOsyR-6vX-TSdMOSloPfyf1zO3b2',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

/**
 * Cache settings
 ******************************************************************************/
$conf['cache'] = FALSE;
$conf['block_cache'] = FALSE;
$conf['page_compression'] = FALSE;
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;
$conf['cache_lifetime'] = 0;
$conf['page_cache_maximum_age'] = 0;

// Memcache settings
unset($conf['cache_default_class']);
unset($conf['cache_class_cache_form']);
unset($conf['memcache_servers']);
unset($conf['page_cache_invoke_hooks']);
unset($conf['page_cache_without_database']);
unset($conf['memcache_stampede_protection']);
unset($conf['lock_inc']);
unset($conf['cache_backends']);

/**
 * Search settings
 ******************************************************************************/
$conf["c4m_search_server_overrides"]['c4m_solr']['options']['path'] = "/solr/capacity4more-tst";
$conf["search_api_attachments_tika_path"] = "/var/www/capacity4more-tst.dev.amplexor.com/bin";

/**
 * Overrides
 ******************************************************************************/
$drupal_hash_salt = 'GOeRBREQzQt2bhtYPlCJ3iZp5hAQj9cAIcggmfkxxZQ';
