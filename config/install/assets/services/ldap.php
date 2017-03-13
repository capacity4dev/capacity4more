<?php

/**
 * @file
 * Proxy service to query the EC LDAP.
 */

require_once 'includes/bootstrap.php';
require_once SERVICES_PATH_INCLUDES . '/country.php';
require_once SERVICES_PATH_SERVICES . '/ldap.php';
require_once SERVICES_PATH_SERVICES . '/ldap-mock.php';


// Check first if the user has access to the service.
try {
  services_api_key_check();
}
catch (Exception $e) {
  services_http_response_code(401);
  services_ldap_render_error($e->getMessage());
}

// Get the email address from the request.
try {
  $email = services_ldap_get_email();
}
catch (Exception $e) {
  services_http_response_code(400);
  services_ldap_render_error($e->getMessage());
}

// Query the LDAP service.
try {
  // Mock.
  if (array_key_exists('mock', $_GET)) {
    $data = services_ldap_mock_get_data_by_email($email);
  }
  // LDAP.
  else {
    $data = services_ldap_get_data_by_email($email);
  }

  services_ldap_render_result($data);
}
// Exceptions will only be thrown when something went wrong with the LDAP
// service.
catch (Exception $e) {
  services_http_response_code(503);

  try {
    services_ldap_render_error($e->getMessage());
  }
  catch (Exception $e) {
    echo $e->getMessage();
  }
}
