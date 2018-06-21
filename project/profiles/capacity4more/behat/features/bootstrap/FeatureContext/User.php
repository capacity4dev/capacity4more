<?php
/**
 * @file
 * Context methods about Drupal users.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step;

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
    if (!empty($this->user->name) && $this->user->name == $username && $this->loggedIn()) {
      // $username is already logged in.
      return;
    }

    $this->user = new \stdClass();
    $this->user->name = $username;

    try {
      $password = $this->drupal_users[$username];
    }
    catch (\Exception $e) {
      // For cases like when temporal user try to login.
      $password = 'drupal';
    }

    $this->user->pass = $password;
    $this->login();
  }

  /**
   * @When /^I visit the leave platform page of the current user$/
   */
  public function iVisitTheLeavePlatformPageOfTheCurrentUser() {
    $account = user_load_by_name($this->user->name);

    $steps = array();
    $steps[] = new Step\When('I visit "/user/' . $account->uid . '/leave"');

    return $steps;
  }

  /**
   * @Given /^I am logged in with a temporal user( with email domain "([^"]*)")?$/
   */
  public function iAmLoggedInWithATemporalUser($with_email_domain = NULL, $domain = 'example.com') {
    $username = 'temporaluser' . md5(microtime());
    $password = 'drupal';

    $temporal_user = array(
      'name' => $username,
      'pass' => $password,
      'mail' => "{$username}@{$domain}",
      'status' => 1,
      'legal_accept' => 1,
    );
    user_save(NULL, $temporal_user);

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
    // The role property must be present on this object.
    $this->user->role = NULL;
    $this->login();
  }

  /**
   * @Given /^I should not be able to log in with the temporal user again$/
   */
  public function iShouldNotBeAbleToLogInWithTheTemporalUserAgain() {
    try {
      $this->iAmLoggedInWithATemporalUserAgain();
    }
    catch (\Exception $e) {
      // The temporal user should not be able to log in again.
      return;
    }
    throw new \Exception("Temporal user should not be able to log in.");
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
