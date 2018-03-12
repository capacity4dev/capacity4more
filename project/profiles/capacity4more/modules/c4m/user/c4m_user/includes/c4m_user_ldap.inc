<?php

/**
 * @file
 * Code to handle LDAP integration.
 */

/**
 * Class to manage LDAP integration.
 */
class C4mLDAPUser {
  /**
   * LDAP service URL.
   *
   * @var string
   */
  protected $url;

  /**
   * LDAP service API key.
   *
   * @var string
   */
  protected $apiKey;

  /**
   * Constructor.
   */
  public function __construct() {
    $url = variable_get('c4m_ldap_url');
    $apiKey = variable_get('c4m_ldap_apikey');
    if ($url && $apiKey) {
      $this->url = variable_get('c4m_ldap_url');
      $this->apiKey = variable_get('c4m_ldap_apikey');
    }
    else {
      throw new Exception('LDAP configuration not available.');
    }
  }

  /**
   * Queries the LDAP service.
   *
   * @param string $email
   *   Email address to be validated.
   *
   * @return array
   *   Response array.
   *
   * @see drupal_http_request()
   */
  protected function queryService($email) {
    $data = array(
      'apikey' => $this->apiKey,
      'email' => $email,
    );
    $full_url = url($this->url, array('query' => $data));
    return drupal_http_request($full_url);
  }

  /**
   * Checks the availability of LDAP service.
   *
   * @return bool
   *   Service is accessible.
   */
  public function isUp() {
    $response = $this->queryService('test@test.com');
    return $response->status_message == 'OK';
  }

  /**
   * Validates an email address in LDAP.
   *
   * @param string $email
   *   Email address to be validated.
   *
   * @return bool
   *   Email is valid.
   */
  public function isValidEmail($email) {
    $data = $this->getInfo($email);
    return !empty($data['valid']);
  }

  /**
   * Get LDAP information for an email address.
   *
   * @param string $email
   *   Email address to be validated.
   *
   * @return array
   *   LDAP information.
   */
  public function getInfo($email) {
    $response = $this->queryService($email);

    // Check if it's a successful request.
    if ($response->status_message != 'OK') {
      return FALSE;
    }

    $xml = simplexml_load_string($response->data);
    $data = (array) $xml;
    // We expect to have the valid field.
    if (!isset($data['valid'])) {
      return $data;
    }

    // Country is a special case: '<country iso="BE"/>'.
    if (isset($data['country']['iso'])) {
      $data['country'] = (array) $data['country']['iso'];
    }
    else {
      // Try the xml way:
      $attr = $xml->country[0]->attributes();
      $data['country'] = (array) $attr['iso'];
    }

    $data['country'] = array_shift($data['country']);

    return $data;
  }

}
