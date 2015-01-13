<?php
/**
 * @file
 * Context methods about Events (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait Event {
  /**
   * @When /^I visit the upcoming events overview of group "([^"]*)"$/
   */
  public function iVisitTheUpcomingEventsOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'events/upcoming');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @When /^I visit the past events overview of group "([^"]*)"$/
   */
  public function iVisitThePastEventsOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'events/past');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @Then /^I should see the upcoming events overview$/
   */
  public function iShouldSeeTheUpcomingEventsOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Categories"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Language"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Regions & Countries"');
    $steps[] = new Step\When('I should see a "Organiser" field on an item in the overview');

    return $steps;
  }

  /**
   * @Then /^I should see the past events overview$/
   */
  public function iShouldSeeThePastEventsOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Categories"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Language"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Regions & Countries"');
    $steps[] = new Step\When('I should see a "Organiser" field on an item in the overview');

    return $steps;
  }

  /**
   * @Then /^I should see the event detail page$/
   */
  public function iShouldSeeTheEventDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Title" field');
    $steps[] = new Step\When('I should see a "Comment" field');
    $steps[] = new Step\When('I should see a "Documents" field group');
    $steps[] = new Step\When('I should see a "Organiser" field group');
    $steps[] = new Step\When('I should see a "Location" field group');
    $steps[] = new Step\When('I should see a "Details" field group');

    return $steps;
  }
}
