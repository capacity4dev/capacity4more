<?php
/**
 * @file
 * Context methods about Activity messages and Activity streams.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Activity {
  /**
   * @Given /^I should see the Activity stream$/
   */
  public function iShouldSeeTheActivityStream() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-activity-stream');
    if ($el === null) {
      throw new \Exception('The Activity Stream pane is not visible.');
    }
  }

  /**
   * @Then /^I should see "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeInTheActivityStreamOfTheGroup($text, $group) {
    $url = strtolower(str_replace(' ', '-', trim($group)));
    $steps = array();
    $steps[] = new Step\When("I go to \"$url\"");
    $steps[] = new Step\When('I should see "' . $text . '" in the "div.message-title" element');

    return $steps;
  }

  /**
   * @Given /^I should see an updated message for "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeAnUpdatedMessageForInTheActivityStreamOfTheGroup($title, $group) {
    $url = strtolower(str_replace(' ', '-', trim($group)));
    $steps = array();
    $steps[] = new Step\When("I go to \"$url\"");
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should not see "posted Information" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "updated the Information" in the "div.pane-activity-stream" element');

    return $steps;
  }

  /**
   * @Given /^I should see a creation message for "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeACreationMessageForInTheActivityStreamOfTheGroup($title, $group) {
    // Generate URL from title.
    $url = strtolower(str_replace(' ', '-', trim($group)));

    $steps = array();
    $steps[] = new Step\When("I go to \"$url\"");
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "posted Information" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should not see "updated the Information" in the "div.pane-activity-stream" element');

    return $steps;
  }

  /**
   * @Given /^I should see a new message for "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeANewMessageForInTheActivityStreamOfTheGroup($title, $group) {
    $url = strtolower(str_replace(' ', '-', trim($group)));
    $steps = array();
    $steps[] = new Step\When("I go to \"$url\"");
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "posted Information" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "updated the Information" in the "div.pane-activity-stream" element');

    return $steps;
  }
}
