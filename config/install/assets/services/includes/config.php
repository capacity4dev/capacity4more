<?php

/**
 * @file
 * Code to support loading config variables.
 */

/**
 * Load the config array.
 *
 * @return array
 *   Config array.
 */
function services_config_load() {
  static $config;

  if (!$config) {
    require_once SERVICES_PATH_CONFIG . '/settings.php';
  }

  return $config;
}

/**
 * Get a config variable by its key with default fallback.
 *
 * @return mixed
 *   The config variable.
 */
function services_config_get($key, $default = NULL) {
  $config = services_config_load();

  if (!array_key_exists($key, $config)) {
    return $default;
  }

  return $config[$key];
}
