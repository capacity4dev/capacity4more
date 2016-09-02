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
   * @When /^I visit the leave platform page of "([^"]*)"$/
   */
  public function iVisitTheLeavePlatformPageOf($username) {
    $users = user_load_multiple(array(), array('name' => $username, 'status' => '1'));
    $account = reset($users);

    $steps = array();
    $steps[] = new Step\When('I visit "/user/' . $account->uid . '/leave"');

    return $steps;
  }

  /**
   * @Given /^I am logged in with a temporal user$/
   */
  public function iAmLoggedInWithATemporalUser() {
    $account = new \stdClass();
    $account->status = TRUE;

    $edit['name'] = 'temporaluser';
    $edit['pass'] = 'drupal';
    $edit['mail'] = 'temporaluser@example.com';
    $edit['status'] = 1;
    $edit['legal_accept'] = 1;

    $account = user_save($account, $edit);

    $this->user = new \stdClass();
    $this->user->name = 'temporaluser';
    $this->user->pass = 'drupal';
    $this->login();
  }

}
