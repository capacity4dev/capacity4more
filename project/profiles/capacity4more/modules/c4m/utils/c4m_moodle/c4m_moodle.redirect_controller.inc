<?php

/**
 * @file
 * C4M Moodle Redirect Controller class.
 */

/**
 * Class C4mMoodleRedirectController.
 *
 * Redirect to a Moodle destination if it's allowed based on a few dependencies
 * of the user.
 *
 * Dependencies:
 *   - user should be logged in
 *   - user should have an organisation assigned to it's profile
 */
class C4mMoodleRedirectController extends stdClass {

  /**
   * Contains the user object.
   *
   * @var object
   */
  protected $user;

  /**
   * Contains the Moodle destination URL.
   *
   * @var string
   */
  protected $destination;

  /**
   * C4mMoodleRedirectController constructor.
   *
   * @param object $user
   *   The user object.
   * @param string $destination
   *   The Moodle destination URL.
   */
  public function __construct($user, $destination) {
    $this->user = $user;
    $this->destination = $destination;
  }

  /**
   * Returns the Moodle destination URL.
   *
   * @return string
   *   Moodle destination URL.
   */
  protected function getDestination() {
    return $this->destination;
  }

  /**
   * Returns the redirect URL based on the user's dependencies.
   *
   * @return string
   *   The redirect URL.
   */
  public function getRedirect() {
    // Check if the user has an organisation.
    $organisation = $this->getUserOrganisation();
    if (empty($organisation)) {
      return $this->getRedirectProfile();
    }

    return $this->destination;
  }

  /**
   * Returns the redirect URL to the user's profile edit form.
   *
   * @return string
   *   The redirect URL.
   */
  private function getRedirectProfile() {
    // The user object is not valid, so the user must login first.
    if (!((bool) $this->user->uid)) {
      return $this->getRedirectLogin();
    }

    $moodle_redirect_url = $this->getMoodleRedirectUrl();

    return url('user/' . $this->user->uid . '/edit', array(
      'query' => array(
        'destination' => $moodle_redirect_url,
      ),
      'absolute' => TRUE,
    ));
  }

  /**
   * Returns the redirect URL to the user login form.
   *
   * @return string
   *   The redirect URL.
   */
  private function getRedirectLogin() {
    $moodle_redirect_url = $this->getMoodleRedirectUrl();

    return url('user/login', array(
      'query' => array(
        'destination' => $moodle_redirect_url,
      ),
      'absolute' => TRUE,
    ));
  }

  /**
   * Returns the organisation of the user object.
   *
   * @return string | bool
   *   The user's organisation or FALSE if none can be found.
   */
  private function getUserOrganisation() {
    if ($user_wrapper = entity_metadata_wrapper('user', $this->user)) {
      if ($organisation = $user_wrapper->c4m_organisation->value()) {
        return $organisation;
      }
    }

    return FALSE;
  }

  /**
   * Returns the Moodle Redirect Controller URL.
   *
   * @return string
   *   The Moodle Redirect URL.
   */
  private function getMoodleRedirectUrl() {
    return url('moodle/redirect', array(
      'query' => array(
        'moodle_destination' => rawurlencode($this->destination),
      ),
    ));
  }

}
