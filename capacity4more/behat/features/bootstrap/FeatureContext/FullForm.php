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
    $steps[] = new Step\When('I press the "discussions" button');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I press the "idea" button');
    $steps[] = new Step\When('I fill editor "body" with "' . $body . '"');
    $steps[] = new Step\When('I click "Create in full form"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should see "Edit Discussion ' . $title . '"');

    return $steps;
  }

  /**
   * @When /^I fill the taxonomy in the full form and save$/
   */
  public function iFillFullFormAndSave() {
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
   * @When /^I add a document from the library$/
   */
  public function iAddADocumentToDiscussionInFullForm() {
    $steps = array();
    $steps[] = new Step\When('I click "Select a Document from the library"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I click on the "Nobel Prize in Physics 2014" document');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I press the "Save" button');
    $steps[] = new Step\When('I wait');

    return $steps;
  }

  /**
   * @When /^I click on the "([^"]*)" document$/
   */
  public function iChooseLibrary($title) {
    $javascript = "
      jQuery(Drupal.overlay.activeFrame[0].contentDocument).find('[title=\"$title\"]').slice(0,1).trigger('click');
    ";
    $this->getSession()->executeScript($javascript);
  }

  /**
   * @Then /I should see the following details "([^"]*)"$/
   */
  public function iShouldSeeFullFormEntityDetails($elements) {
    $elements = explode(',', $elements);

    $steps = array();
    foreach ($elements as $element) {
      $steps[] = new Step\When('I should see "' . $element . '"');
    }

    return $steps;
  }

  /**
   * @Given /^I save document in the overlay$/
   */
  public function iSaveDocumentInTheOverlay() {

    $javascript = "
      jQuery(Drupal.overlay.activeFrame[0].contentDocument).find('#save').slice(0,1).trigger('click');
    ";
    $this->getSession()->executeScript($javascript);

    $steps = array();
    $steps[] = new Step\When('I wait');
    return $steps;
  }
}
