<?php
/**
 * @file
 * Context methods about Articles (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait Article {
  /**
   * @Then /^I should see the article detail page$/
   */
  public function iShouldSeeTheArticleDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Regions & Countries" field');
    $steps[] = new Step\When('I should see a "Articles" field');
    $steps[] = new Step\When('I should see a "Groups" field');
    $steps[] = new Step\When('I should see a "External Contributors" field');
    $steps[] = new Step\When('I should see a "Internal Contributors" field');

    return $steps;

  }

}
