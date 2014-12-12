<?php
/**
 * @file
 * Context methods about Wiki Pages (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait WikiPage {

  /**
   * @Then /^I should see the Wiki detail page$/
   */
  public function iShouldSeeTheWikiDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Title" field');
    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a "Comment" field');

    return $steps;
  }

}
