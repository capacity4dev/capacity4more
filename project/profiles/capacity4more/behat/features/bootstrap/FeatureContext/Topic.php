<?php
/**
 * @file
 * Context methods about Topics.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Topic {

  /**
   * @Given /^I check the related topic checkbox$/
   */
  public function iCheckRelatedTopic() {
    $steps = [];
    $steps[] = new Step\When('I check the related topic checkbox with "Fire"');

    return $steps;
  }

  /**
   * @Given /^I check the related topic checkbox with "([^"]*)"$/
   */
  public function iCheckRelatedTopicWith($topic) {
    $steps = [];
    $steps[] = new Step\When('I press the "Select Topics" button');
    $steps[] = new Step\When('I check the "' . $topic . '" topic on creation form');
    $steps[] = new Step\When('I press the "Select Topics" button');

    return $steps;
  }

  /**
   * @Given /^I check the "([^"]*)" topic on creation form/
   */
  public function iCheckTheTopicsField($title) {
    // Using javascript script to check the checkbox over Angular to invoke its
    // change callback.
    $js_to_check_topic = "jQuery('.c4m_vocab_topic .popover-content [title=\"$title\"] input').click()";
    $this->getSession()->executeScript($js_to_check_topic);
    // Apparently the first time doesn't trigger it.
    $this->getSession()->executeScript($js_to_check_topic);
  }
}