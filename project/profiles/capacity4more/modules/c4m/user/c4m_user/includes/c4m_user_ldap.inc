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
    // @todo Add configuration page.
    $this->url = variable_get('c4m_user_ldap_url', 'http://capacity4dev.ec.europa.eu/services/ldap.php');
    $this->apiKey = variable_get('c4m_user_ldap_apikey', '9b4e117f-6734-41a4-9a18-4c09433bffb7');
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
  public function validateEmail($email) {
    $response = $this->queryService($email);
    if (!isset($response->data)) {
      return FALSE;
    }
    $data = simplexml_load_string($response->data);
    return !empty($data->valid);
  }

}
