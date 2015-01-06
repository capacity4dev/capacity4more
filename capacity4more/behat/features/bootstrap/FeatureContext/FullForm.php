<?php
/**
 * @file
 * Context methods about full form.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait FullForm {

  /**
   * @When /^I create a discussion full form with title "([^"]*)" and body "([^"]*)" in "([^"]*)"$/
   */
  public function iCreateDiscussionFullForm($title, $body, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I press the "discussions" button');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I press the "idea" button');
    $steps[] = new Step\When('I fill editor "body" with "' . $body . '"');
    $steps[] = new Step\When('I click "Create in full form"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should see "Edit Discussion New discussion"');

    return $steps;
  }

  /**
   * @When /^I fill the full form$/
   */
  public function iFillFullForm() {
    $steps = array();
    $steps[] = new Step\When('I check the "c4m_related_topic" checkbox with value "Earth"');
    $steps[] = new Step\When('I check the "categories" checkbox with value "Masters Tournaments"');
    $steps[] = new Step\When('I check the "c4m_vocab_date" checkbox with value "2000"');
    $steps[] = new Step\When('I check the "c4m_vocab_language" checkbox with value "French"');
    $steps[] = new Step\When('I press the "Save" button');
    $steps[] = new Step\When('I wait');

    return $steps;
  }

  /**
   * @Then /^I should see the entity details$/
   */
  public function iShouldSeeFullFormEntityDetails() {
    $steps = array();
    $steps[] = new Step\When('I should see "Earth"');
    $steps[] = new Step\When('I should see "Masters Tournaments"');
    $steps[] = new Step\When('I should see "2000"');
    $steps[] = new Step\When('I should see "French"');

    return $steps;
  }
}
