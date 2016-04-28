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
    if (!$this->validEmail) {
      return FALSE;
    }

    $result = db_query('SELECT name FROM {c4m_domain} WHERE name = :name', array(
      ':name' => $this->domain,
    ))->fetchCol();
    return !empty($result);
  }

  /**
   * Checks if the email address is whitelisted.
   *
   * @return bool
   *   TRUE if the email address has a corresponding email domain.
   */
  public function isWhiteListed() {
    if (!$this->validEmail) {
      return FALSE;
    }

    $result = db_query("SELECT name FROM {c4m_domain} WHERE whitelist LIKE :pattern", array(
      ':pattern' => '%' . db_like($this->email) . '%',
    ))->fetchCol();
    return !empty($result);
  }

}
