<?php
/**
 * @file
 * Context methods about Group management dashboard.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait GroupManagement {
  /**
   * @When /^I visit the management dashboard of group "([^"]*)"$/
   */
  public function iVisitTheManagementDashboardOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'manage');

    return new Given("I go to \"$uri\"");
  }

  /**
   * @Then /^I should see the group management dashboard$/
   */
  public function iShouldSeeTheGroupManagementDashboard() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should see the Group Management Details');
    $steps[] = new Step\When('I should see the Group Management Status');

    return $steps;
  }

  /**
   * @When /^I should see the Group Management Details$/
   */
  public function iShouldSeeTheGroupManagementDetails() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-group-details');
    if ($el === null) {
      throw new \Exception('The Group Details pane is not visible.');
    }

    $steps = array();

    $steps[] = new Step\When('I should see "Group details"');
    $steps[] = new Step\When('I should see "Group name"');
    $steps[] = new Step\When('I should see "Group regions & countries"');
    $steps[] = new Step\When('I should see "Group access"');
    $steps[] = new Step\When('I should see "Membership requests"');
    $steps[] = new Step\When('I should see "Categories"');

    return $steps;
  }

  /**
   * @When /^I should see the Group Management Status$/
   */
  public function iShouldSeeTheGroupManagementStatus() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-group-status');
    if ($el === null) {
      throw new \Exception('The Group Status pane is not visible.');
    }

    $steps = array();

    $steps[] = new Step\When('I should see "Group status"');
    $steps[] = new Step\When('I should see "Thumbnail image"');

    return $steps;
  }

  /**
   * @Given /^I visit the people management of group "([^"]*)"$/
   */
  public function iVisitThePeopleManagementOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = "group/node/{$group->nid}/admin/people";

    return new Given("I go to \"$uri\"");
  }

  /**
   * @Then /^I block "([^"]*)" from "([^"]*)"$/
   */
  public function iBlockFrom($username, $group_title) {
    if ($username == 'temporal_user') {
      $username = $this->getTemporalUsername();
    }

    $steps = array();
    $steps[] = new Step\When('I visit the people management of group "' . $group_title . '"');

    // Filter the list of the people by the username.
    $steps[] = new Step\When('I fill in "edit-uid" with "' . $username . '"');
    $steps[] = new Step\When('I press "Apply"');

    $steps[] = new Step\When('I follow "edit"');
    $steps[] = new Step\When('I select "' . OG_STATE_BLOCKED . '" from "edit-state"');
    $steps[] = new Step\When('I press "Update membership"');

    return $steps;
  }

}
