<?php
/**
 * @file
 * Context methods about Page Access.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait PageAccess {
  /**
   * @Given /^I should not have access to the page$/
   */
  public function iShouldNotHaveAccessToThePage() {
    $steps = array();
    $steps[] = new Step\When('I should get a "403" HTTP response');

    return $steps;
  }

  /**
   * @Given /^I should have access to the page$/
   */
  public function iShouldHaveAccessToThePage() {
    $steps = array();
    $steps[] = new Step\When('I should get a "200" HTTP response');

    return $steps;
  }

  /**
   * @Then /^I should see in the header "([^"]*)":"([^"]*)"$/
   */
  public function iShouldSeeInTheHeader($header, $value) {
    $headers = $this->getSession()->getResponseHeaders();
    if (!isset($headers[$header]) || $headers[$header][0] != $value) {
      throw new \Exception(sprintf("Did not see %s with value %s.", $header, $value));
    }
  }
}
