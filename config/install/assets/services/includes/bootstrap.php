<?php

/**
 * @file
 * Bootstrap file for the services.
 */

// Define paths.
define('SERVICES_PATH_INCLUDES', __DIR__);
define('SERVICES_PATH_CONFIG', SERVICES_PATH_INCLUDES . '/../config');
define('SERVICES_PATH_SERVICES', SERVICES_PATH_INCLUDES . '/../services');
define('SERVICES_PATH_TEMPLATES', SERVICES_PATH_INCLUDES . '/../templates');

// Include shared code.
require_once SERVICES_PATH_INCLUDES . '/config.php';
require_once SERVICES_PATH_INCLUDES . '/services.php';
require_once SERVICES_PATH_INCLUDES . '/template.php';
