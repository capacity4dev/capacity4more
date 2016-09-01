<?php
/**
 * @file
 * Context methods about the Contact page.
 */

namespace FeatureContext;

//use Behat\Behat\Context\Step\Given;
use Behat\Behat\Context\Step;

trait Contact {

  /**
   * @Then /^I should see "([^"]*)" in the status messages$/
   */
  public function iShouldSeeInTheStatusMessages($text) {
    $page = $this->getSession()->getPage();
    $item = $page->find('css', '.messages');

    if (is_null($item)) {
      throw new \Exception("No status messages found.");
    }

    $steps = array();
    $steps[] = new Step\When('I should see "' . $text . '" in the ".messages" element');

    return $steps;
  }

}
