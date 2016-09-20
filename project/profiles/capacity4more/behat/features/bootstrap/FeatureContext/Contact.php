<?php

/**
 * @file
 * Context methods about Contact pages.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step;

trait Contact {

  /**
   * @When /^I go to user "([^"]*)" contact form$/
   */
  public function iGoToUserContactForm($username) {
    $account = user_load_by_name($username);

    $steps = array();
    $steps[] = new Step\When('I visit "/user/' . $account->uid . '/contact"');

    return $steps;
  }
}
