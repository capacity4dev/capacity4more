<?php
/**
 * @file
 * Context methods about Quick Post form.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait QuickPost {
  /**
   * @Given /^I should see the Quick Post form$/
   */
  public function iShouldSeeTheQuickPostForm() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-quick-form');
    if ($el === null) {
      throw new \Exception('The Quick Post pane is not visible.');
    }
  }

  /**
   * @Given /^I fill editor "([^"]*)" with "([^"]*)"$/
   */
  public function iFillEditorWith($editor, $value) {
    // Using javascript script to fill the textAngular editor,
    // We have to enter the value directly to the scope.
    $javascript = "angular.element('textarea#" . $editor . "').scope().data." . $editor . " = '" . $value . "';";
    $this->getSession()->executeScript($javascript);
  }

  /**
   * @Given /^I fill label with "([^"]*)" in "([^"]*)"$/
   */
  public function iFillLabelWith($value, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I press the "discussions" button');
    $steps[] = new Step\When('I fill in "label" with "' . $value . '"');

    return $steps;
  }

  /**
   * @When /^I create a discussion quick post with title "([^"]*)" and body "([^"]*)" in "([^"]*)"$/
   */
  public function iCreateDiscussionQuickPost($title, $body, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I press the "discussions" button');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I press the "idea" button');
    $steps[] = new Step\When('I fill editor "body" with "' . $body . '"');
    $steps[] = new Step\When('I press the "quick-submit" button');
    $steps[] = new Step\When('I wait');
    // Check that the form has collapsed.
    $steps[] = new Step\When('I should not see "Type of Discussion" in the "div#quick-post-fields" element');

    return $steps;
  }

  /**
   * @When /^I create an event quick post with title "([^"]*)" and body "([^"]*)" that starts at "([^"]*)" and ends at "([^"]*)" in "([^"]*)"$/
   */
  public function iCreateEventQuickPost($title, $body, $start_date, $end_date, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I press the "events" button');
    $steps[] = new Step\When('I press the "Meeting" button');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I fill editor "body" with "' . $body . '"');
    $steps[] = new Step\When('I fill in "startDate" with "' . $start_date . '"');
    $steps[] = new Step\When('I fill in "endDate" with "' . $end_date . '"');

    // Fill location
    $steps[] = new Step\When('I fill in "street" with "Brener 5"');
    $steps[] = new Step\When('I fill in "postal_code" with "6382624"');
    $steps[] = new Step\When('I fill in "city" with "Tel-Aviv"');
    $steps[] = new Step\When('I fill in "country_name" with "Israel"');

    $steps[] = new Step\When('I press the "quick-submit" button');
    $steps[] = new Step\When('I wait');
    // Check that the form has collapsed.
    $steps[] = new Step\When('I should not see "Type of Event" in the "div#quick-post-fields" element');

    return $steps;
  }
}
