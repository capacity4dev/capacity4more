<?php

/**
 * @file
 * LDAP service code.
 */

/**
 * Render a ldap service response.
 *
 * @param mixed $content
 *   Content to return with the proper header.
 *
 * @return mixed
 *   $content with the proper header attached.
 */
function services_ldap_render($content) {
  header('Content-type: text/xml');
  echo $content;
}

/**
 * Render an error message.
 *
 * @param string $error
 *   The error message.
 */
function services_ldap_render_error($error) {
  $data = array('error' => $error);
  $content = services_template_render('ldap/error.xml.php', $data);
  services_ldap_render($content);
}

/**
 * Render a LDAP query result.
 *
 * @param array $data
 *   The data to return.
 */
function services_ldap_render_result(array $data) {
  $content = services_template_render('ldap/response.xml.php', $data);
  services_ldap_render($content);
}

/**
 * Get the email address from the request.
 *
 * @return string
 *   The email address.
 *
 * @throws Exception
 *   - If the email address is not in the request.
 *   - If the email address value is not valid.
 */
function services_ldap_get_email() {
  if (!array_key_exists('email', $_GET)) {
    throw new Exception(
      'No email address in the request.'
    );
  }

  $email = $_GET['email'];

  // Check if we received a valid email format.
  if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    throw new Exception(
      sprintf('Email value "%s" is not a valid address.', $email)
    );
  }

  return $email;
}

/**
 * Get the data from the LDAP based on the email of a user.
 *
 * @param string $email
 *   The email address of the user to get the data for.
 *
 * @return array
 *   The data as found on the LDAP server.
 *
 * @throws Exception
 *   - When something went wrong while searching the LDAP.
 */
function services_ldap_get_data_by_email($email) {
  $filter = sprintf('mail=%s', $email);
  $data = services_ldap_get_data_array();
  $connection = services_ldap_connect();

  $result = services_ldap_seach($filter);

  // Check if there are any result.
  $count = ldap_count_entries($connection, $result);
  if (!$count) {
    return $data;
  }

  // Get the user from the search result.
  $user = service_ldap_get_user_from_search_result($result);

  // Extract the data.
  $record_status = strtolower(
    services_ldap_extract_user_data($user, 'recordstatus')
  );
  $data['valid'] = (int) ($record_status === 'a');
  $data['title'] = services_ldap_extract_user_data($user, 'title');
  $data['userid'] = services_ldap_extract_user_data($user, 'uid');
  $data['firstname'] = services_ldap_extract_user_data($user, 'givenname');
  $data['lastname'] = services_ldap_extract_user_data($user, 'sn');
  $data['email'] = services_ldap_extract_user_data($user, 'mail');
  $data['department'] = services_ldap_extract_user_data($user, 'departmentnumber');
  $data['country_iso'] = services_ldap_extract_user_data($user, 'c');
  $data['country_name'] = services_country_name_by_code($data['country_iso']);
  $data['region'] = services_ldap_extract_user_data($user, 'l');

  return $data;
}

/**
 * Search on the LDAP server.
 *
 * @param string $filter
 *   The filter to search the LDAP server on.
 *
 * @return resource
 *   The result identifier.
 *
 * @throws Exception
 *   When an error occurred during searching within the LDAP server.
 */
function services_ldap_seach($filter) {
  $connection = services_ldap_connect();

  $result = ldap_search(
    $connection,
    services_config_get('ldap_basedn'),
    $filter
  );

  // Check if nothing went wrong.
  if ($result === FALSE) {
    throw new Exception(ldap_error($connection));
  }

  return $result;
}

/**
 * Get a single user from a search result.
 *
 * @param resource $result
 *   Result identifier of a LDAP search.
 *
 * @return array
 *   All user data as found in the LDAP.
 *
 * @throws Exception
 *   When an error occurred during getting the data from the LDAP server.
 */
function service_ldap_get_user_from_search_result($result) {
  $connection = services_ldap_connect();

  // Get the found entries from the LDAP service.
  $entries = ldap_get_entries($connection, $result);

  // Check if nothing went wrong.
  if ($entries === FALSE) {
    throw new Exception(ldap_error($connection));
  }

  // The user data sits in the first entry.
  $user = $entries[0];

  return $user;
}

/**
 * Helper to extract data from the ldap result.
 *
 * @param array $user
 *   The LDAP search result user data.
 * @param string $field
 *   The field to get the data from.
 *
 * @return mixed
 *   The data as found in the result.
 */
function services_ldap_extract_user_data(array $user, $field) {
  if (!isset($user[$field][0])) {
    return NULL;
  }

  return $user[$field][0];
}

/**
 * Create an empty data array to start from.
 *
 * @return array
 *   The data array structure.
 */
function services_ldap_get_data_array() {
  return array(
    'valid' => 0,
    'title' => NULL,
    'userid' => NULL,
    'firstname' => NULL,
    'lastname' => NULL,
    'email' => NULL,
    'department' => NULL,
    'country_iso' => NULL,
    'country_name' => NULL,
    'region' => NULL,
  );
}

/**
 * Get an LDAP connection.
 *
 * @return resource
 *   The LDAP connection resource identifier.
 *
 * @throws Exception
 *   - If the LDAP service could not be contacted.
 *   - If the LDAP login is not successfull.
 */
function services_ldap_connect() {
  static $connection;

  // Create the ldap connection resource.
  if (!$connection) {
    $connection = ldap_connect(
      services_config_get('ldap_host'),
      services_config_get('ldap_port')
    );

    if (!$connection) {
      throw new Exception(
        'LDAP service not available.'
      );
    }

    // Bind and login.
    $bind = @ldap_bind(
      $connection,
      services_config_get('ldap_binddn'),
      services_config_get('ldap_pass')
    );

    if (!$bind) {
      throw new Exception(ldap_error($connection));
    }

    // Make sure that the LDAP connection closes when the script terminates.
    register_shutdown_function('services_ldap_disconnect', $connection);
  }

  return $connection;
}

/**
 * Function to disconnect from the ldap service.
 *
 * Will be registered as an shutdown function.
 *
 * @param resource $connection
 *   The LDAP connection resource identifier.
 */
function services_ldap_disconnect($connection) {
  ldap_unbind($connection);
}
