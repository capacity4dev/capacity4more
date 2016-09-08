<?php
/**
 * @file
 * Context methods about Drupal users.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step;

trait User {

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
   * @When /^I visit the leave platform page of the current user$/
   */
  public function iVisitTheLeavePlatformPageOfTheCurrentUser() {
    $account = user_load_by_name($this->user->name);

    $steps = array();
    $steps[] = new Step\When('I visit "/user/' . $account->uid . '/leave"');

    return $steps;
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
  }

}
