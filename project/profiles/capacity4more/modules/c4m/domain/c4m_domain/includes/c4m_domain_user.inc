<?php
/**
 * @file
 * Code to handle Email Domain User integration.
 */

/**
 * Class to manage Email Domain User integration.
 */
class C4mDomainUser {
  /**
   * Email address.
   *
   * @var string
   */
  protected $email;

  /**
   * Valid email address.
   *
   * @var string
   */
  protected $validEmail;

  /**
   * Domain.
   *
   * @var string
   */
  protected $domain;

  /**
   * Constructor.
   */
  public function __construct($email) {
    $this->email = $email;
    $this->validEmail = valid_email_address($this->email);
    if ($this->validEmail) {
      preg_match('/@(.*)/', $this->email, $matches);
      $this->domain = $matches[1];
    }
  }

  /**
   * Checks if there is a Email domain for this email address.
   *
   * @return bool
   *   TRUE if the email address has a corresponding email domain.
   */
  public function hasEmailDomain() {
    $result = $this->getEmailDomainByName();
    return !empty($result);
  }

  /**
   * Get the Email domain for this email address.
   *
   * @return bool|object
   *   Email domain object or FALSE.
   */
  public function getEmailDomainByName() {
    if (!$this->validEmail) {
      return FALSE;
    }

    $result = db_query('SELECT id FROM {c4m_domain} WHERE name = :name', array(
      ':name' => $this->domain,
    ))->fetchCol();
    if (empty($result)) {
      return FALSE;
    }
    return $this->getEmailDomain($result[0]);
  }

  /**
   * Checks if the email address is whitelisted.
   *
   * @return bool
   *   TRUE if the email address has a corresponding email domain.
   */
  public function isWhiteListed() {
    $result = $this->getEmailDomainByWhitelist();
    return !empty($result);
  }

  /**
   * Get the domain in which this email is whitelisted.
   *
   * @return bool|object
   *   Email domain object or FALSE.
   */
  public function getEmailDomainByWhitelist() {
    if (!$this->validEmail) {
      return FALSE;
    }

    $result = db_query("SELECT id FROM {c4m_domain} WHERE whitelist LIKE :pattern", array(
      ':pattern' => '%' . db_like($this->email) . '%',
    ))->fetchCol();
    if (empty($result)) {
      return FALSE;
    }
    return $this->getEmailDomain($result[0]);
  }

  /**
   * Loads the domain.
   *
   * @return bool|object
   *   Email domain object or FALSE.
   */
  protected function getEmailDomain($id) {
    $domain = entity_load('c4m_domain', array(intval($id)));
    return array_shift($domain);
  }

}
