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
    $steps[] = new Step\When('I should see "' . $text . '" in the ".entity-message h2" element');

    return $steps;
  }

  /**
   * @Then /^I should see "([^"]*)" with author "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeAuthorFullNameInTheActivityStreamOfTheGroup($text, $author, $group) {
    $url = strtolower(str_replace(' ', '-', trim($group)));
    $steps = array();
    $steps[] = new Step\When("I go to \"$url\"");
    $steps[] = new Step\When('I should see "' . $text . '" in the ".entity-message h2" element');
    $steps[] = new Step\When('I should see "' . $author . '" in the ".activity-stream--operator a" element');

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
    $steps[] = new Step\When('I should see "updated information" in the "div.pane-activity-stream" element');

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
    $steps[] = new Step\When('I should not see "updated information" in the "div.pane-activity-stream" element');

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

  /**
   * @When /^I load more activities$/
   */
  public function iLoadMoreActivities() {
    $steps = array();
    $steps[] = new Step\When('I click "load-more-button"');
    $steps[] = new Step\When('I wait');

    return $steps;
  }

  /**
   * @Given /^I go to the "([^"]*)" group$/
   */
  public function iGoToTheGroup($group) {
    $steps[] = new Step\When("I go to \"$group\"");
  }

  /**
   * @Given /^I do not see "([^"]*)" button$/
   */
  public function iDoNotSeeButton($button) {
    $page = $this->getSession()->getPage();

    // Get all the pin buttons on the page.
    $promoteButtons = $page->find('xpath', '//a/i[contains(@class, "fa fa-thumb-tack")]');

    if (count($promoteButtons)) {
      throw new \Exception("A user that not allowed to see the " . $button . " buttons, sees it.");
    }
  }
}
