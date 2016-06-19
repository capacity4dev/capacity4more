<?php
/**
 * @file
 * Context methods about Drupal users.
 */

namespace FeatureContext;

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
   * Create a new user and associate with an organization by email domain.
   *
   * @Given /^I create a new user "([^"]*)" with the "([^"]*)" email domain$/
   */
  public function iCreateANewUser($username, $sld) {
    return;
  }
}
