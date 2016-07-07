<?php

/**
 * @file
 * Code to handle Organisation User integration.
 */

/**
 * Class to manage Organisation User integration.
 */
class C4mOrganisationUser {
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
   * Checks if there is an Organisation with a domain for this user.
   *
   * @return bool
   *   TRUE if the email address has a corresponding Organisation.
   */
  public function hasOrganisation() {
    $list = $this->getOrganisations();
    return !empty($list);
  }

  /**
   * Returns the list of Organisations the user belongs to.
   *
   * @return bool|array
   *   Array of Organisation node objects. FALSE if no organisations available.
   */
  public function getOrganisationsInfo() {
    $list = $this->getOrganisations();
    if (!$list) {
      return FALSE;
    }
    $list = node_load_multiple(array_keys($list));
    return $list;
  }

  /**
   * Returns the list of branding Organisations the user belongs to.
   *
   * @return array
   *   Array of Organisation node objects.
   */
  public function getBrandingOrganisationsInfo() {
    $list = $this->getOrganisations(TRUE);
    $list = node_load_multiple(array_keys($list));
    return $list;
  }

  /**
   * Returns the list of Organisations the user belongs to.
   *
   * @param bool $brand
   *   (optional) TRUE if the list should contain only the branding
   *   organisations.
   *
   * @return array
   *   Array of Organisation node objects.
   */
  protected function getOrganisations($brand = FALSE) {
    if (!$this->validEmail) {
      return FALSE;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'organisation')
      ->fieldCondition('c4m_domain', 'domain', $this->domain, '=', 0);
    if ($brand) {
      $query->fieldCondition('c4m_domain', 'icon', 1, '=', 0);
    }
    $result = $query->execute();
    if ($result) {
      return $result['node'];
    }
    return $result;
  }

}
