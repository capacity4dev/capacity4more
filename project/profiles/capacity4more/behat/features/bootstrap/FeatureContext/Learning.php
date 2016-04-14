<?php
/**
 * @file
 * Context methods about Learning space.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Learning {
  /**
   * @When /^I visit the learning page$/
   */
  public function iVisitTheLearningPage() {
    return new Given('I go to "/learning"');
  }
}
