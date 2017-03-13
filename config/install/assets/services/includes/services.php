<?php

/**
 * @file
 * Shared code for all services.
 */

/**
 * Check the request api key.
 *
 * @return bool
 *   TRUE if the api key check is ok.
 *
 * @throws Exception
 *   - When there is no apikey.
 *   - When the apikey is not valid.
 */
function services_api_key_check() {
  if (!array_key_exists('apikey', $_GET)) {
    throw new Exception(
      'Missing API key.'
    );
  }

  $key = $_GET['apikey'];
  $allowed_keys = services_config_get('api_keys');

  if (!in_array($key, $allowed_keys)) {
    throw new Exception(
      'API key is not valid.'
    );
  }

  return TRUE;
}

/**
 * Send a http response code.
 */
function services_http_response_code($code = NULL) {
  header('X-PHP-Response-Code: ' . $code, TRUE, $code);
}
