<?php
/**
 * @file
 * Context methods about Drupal users.
 */

namespace FeatureContext;


trait User {
  /**
   * Hold the username of the last temporal user that has been created.
   *
   * @var string
   */
  protected $temporal_username;

  /**
   * Authenticates a user with password from configuration.
   *
   * @Given /^I am logged in as user "([^"]*)"$/
   */
  public function iAmLoggedInAsUser($username) {
    $this->user = new \stdClass();
    $this->user->name = $username;
    $this->user->pass = $this->drupal_users[$username];
    $this->login();
  }

  /**
   * @Given /^I am logged in with a temporal user$/
   */
  public function iAmLoggedInWithATemporalUser() {
    $username = 'temporaluser' . REQUEST_TIME;
    $password = 'drupal';

    $temporal_user = (object) array(
      'name' => $username,
      'pass' => $password,
      'mail' => "{$username}@example.com",
      'legal_accept' => 1,
    );
    $this->getDriver()->userCreate($temporal_user);

    $this->user = new \stdClass();
    $this->user->name = $username;
    $this->user->pass = $password;
    $this->login();

    // Keep the username in the object.
    $this->temporal_username = $username;
  }

  /**
   * @Given /^I am logged in with a temporal user again$/
   */
  public function iAmLoggedInWithATemporalUserAgain() {
    $this->user = new \stdClass();
    $this->user->name = $this->getTemporalUsername();
    $this->user->pass = 'drupal';
    $this->login();
  }

  /**
   * Help function.
   *
   * @return string
   *   The last temporal username.
   */
  public function getTemporalUsername() {
    return $this->temporal_username;
  }
}
