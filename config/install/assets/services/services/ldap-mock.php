<?php

/**
 * @file
 * Code to support the LDAP mock service.
 */

/**
 * Get the data from the MOCK based on the email of a user.
 *
 * @param string $email
 *   The email address of the user to get the data for.
 *
 * @return array
 *   The data as found by the Mock.
 */
function services_ldap_mock_get_data_by_email($email) {
  $data = services_ldap_get_data_array();
  $email_parts = services_ldap_get_random_mock_email_parts($email);
  if (!$email_parts) {
    return $data;
  }

  if (!services_ldap_mock_email_is_valid($email)
    || !services_ldap_mock_domain_is_valid($email_parts['domain'])
  ) {
    return $data;
  }

  // Create the dummy answer.
  $userid = $email_parts['userid'];
  $name = services_ldap_get_random_mock_data_name($userid);
  $location = services_ldap_get_random_mock_data('country');

  $data['valid'] = 1;
  $data['title'] = services_ldap_get_random_mock_data('title');
  $data['userid'] = $userid;
  $data['firstname'] = $name['first'];
  $data['lastname'] = $name['last'];
  $data['email'] = $email;
  $data['department'] = services_ldap_get_random_mock_data('department');
  $data['country_iso'] = $location['iso'];
  $data['country_name'] = $location['name'];
  $data['region'] = $location['region'];

  return $data;
}

/**
 * Helper to detect if the email address is forced to be not valid.
 *
 * @param string $email
 *     The email address to check.
 *
 * @return bool
 *     Is forced invalid.
 */
function services_ldap_mock_email_is_valid($email) {
  $pattern = services_config_get('ldap_mock_invalid');
  return (bool) !preg_match($pattern, $email);
}

/**
 * Validate if it is a valid email domain.
 *
 * @param string $domain
 *     The email address to check.
 *
 * @return bool
 *     Is valid domain.
 */
function services_ldap_mock_domain_is_valid($domain) {
  $domains = services_config_get('ldap_mock_domains');
  return in_array($domain, $domains);
}

/**
 * Get the dummy data.
 *
 * @return array
 *   Array of dummy data.
 */
function services_ldap_mock_get_dummy_data() {
  static $data;

  if (!$data) {
    include SERVICES_PATH_CONFIG . '/ldap-mock-data.php';
    $data = $ldap_mock_data;
  }

  return $data;
}

/**
 * Get a random valud from the mock array.
 *
 * @param string $field
 *   The field to get the value from.
 *
 * @return mixed
 *   The randdum value.
 */
function services_ldap_get_random_mock_data($field) {
  $data = services_ldap_mock_get_dummy_data();

  $values = $data[$field];

  $key = array_rand($values);
  if (empty($values[$key])) {
    return;
  }

  return $values[$key];
}

/**
 * Get the email parts.
 *
 * @param string $email
 *   The email to split in parts.
 *
 * @return array
 *   The email parts (userid, domain).
 */
function services_ldap_get_random_mock_email_parts($email) {
  $split = explode('@', $email);
  if (count($split) !== 2) {
    return FALSE;
  }

  return array(
    'userid' => $split[0],
    'domain' => $split[1],
  );
}

/**
 * Get the name parts out of the userid..
 *
 * @param string $userid
 *     The email address to extract the last name from.
 *
 * @return array
 *     An array containing the parts:
 *     - first name
 *     - last name
 */
function services_ldap_get_random_mock_data_name($userid) {
  $parts = explode('.', $userid, 2);

  $firstname = array_shift($parts);
  $lastname  = array_shift($parts);
  $lastname  = str_replace('.', ' ', $lastname);

  return array(
    'first' => $firstname,
    'last'  => $lastname,
  );
}
