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
trait GroupMembers {
  /**
   * @When /^I visit the members list overview of group "([^"]*)"$/
   */
  public function iVisitTheMembersListOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'members');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @When /^I visit the members table overview of group "([^"]*)"$/
   */
  public function iVisitTheMembersTableOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'members/table');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @Then /^I should see the group members list overview$/
   */
  public function iShouldSeeTheGroupMembersListOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Group membership type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Organisation type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics of Expertise"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Country of residence"');

    return $steps;
  }

  /**
   * @Then /^I should see the group members table overview$/
   */
  public function iShouldSeeTheGroupMembersTableOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Group membership type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Organisation type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics of Expertise"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Country of residence"');

    return $steps;
  }

}
