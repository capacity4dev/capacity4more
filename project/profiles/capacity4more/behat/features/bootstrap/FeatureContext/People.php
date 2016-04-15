<?php
/**
 * @file
 * Context methods about Discussions (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * Steps about People.
 */
trait People {
  /**
   * @When /^I visit the people list overview$/
   */
  public function iVisitThePeopleListOverview() {
    return new Given('I go to "people"');
  }

  /**
   * @Then /^I should see the people list overview$/
   */
  public function iShouldSeeThePeopleListOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Organisation type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Organisation"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics of Expertise"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Country of residence"');

    return $steps;
  }

}
