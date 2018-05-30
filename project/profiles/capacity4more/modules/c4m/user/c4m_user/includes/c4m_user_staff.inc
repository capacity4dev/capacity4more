<?php

/**
 * @file
 * Code to handle Organisation User integration.
 */

/**
 * Class to manage Staff User integration.
 */
class C4mStaffUser {

  /**
   * Email address.
   *
   * @var string
   */
  protected $email;

  /**
   * Recognized as a staff email address.
   *
   * @var bool
   */
  protected $staffEmail;

  /**
   * The domain of the emailaddress.
   *
   * @var string
   */
  protected $domain;

  /**
   * List of pre-defined domains that correspond to EC staff members.
   *
   * @var array
   */
  protected static $staffDomains = [
    'ec.europa.eu' => 'ec.europa.eu',
    'echofield.eu' => 'echofield.eu',
    'eeas.europa.eu' => 'eeas.europa.eu',
    'ext.ec.europa.eu' => 'ext.ec.europa.eu',
    'ext.eeas.europa.eu' => 'ext.eeas.europa.eu',
    'ext.jrc.ec.europa.eu' => 'ext.jrc.ec.europa.eu',
    'jrc.ec.europa.eu' => 'jrc.ec.europa.eu',
  ];

  /**
   * Constructor.
   */
  public function __construct($email) {
    $this->email = $email;
    if (valid_email_address($this->email)) {
      preg_match('/@(.*)/', $this->email, $matches);
      $this->domain = $matches[1];

      $this->staffEmail = array_key_exists($this->domain, self::$staffDomains);
    }
  }

  /**
   * Check if a user has a valid EC staff mail domain.
   *
   * @return bool
   *   Whether the user belongs to a pre-defined staff domain.
   */
  public function isValidStaff() {
    return $this->staffEmail;
  }

  /**
   * Retrieve the domain the user was recognized in.
   *
   * @return string
   *   Domain (part after the @) of the mail address.
   */
  public function getDomain() {
    return $this->domain;
  }

}
