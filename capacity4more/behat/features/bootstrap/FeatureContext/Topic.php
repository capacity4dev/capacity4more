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
    $steps = array();
    $steps[] = new Step\When('I check the related topic checkbox with "Fire"');

    return $steps;
  }

  /**
   * @Given /^I check the related topic checkbox with "([^"]*)"$/
   */
  public function iCheckRelatedTopicWith($topic) {
    $steps = array();
    $steps[] = new Step\When('I press "c4m_vocab_topic"');
    $steps[] = new Step\When('I check the box "' . $topic . '"');

    return $steps;
  }
}