<?php
/**
 * @file
 * Context methods about Group dashboard.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait GroupDashboard {
  /**
   * @When /^I visit the dashboard of group "([^"]*)"$/
   */
  public function iVisitTheDashboardOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, '<front>');

    return new Given("I go to \"$uri\"");
  }

  /**
   * @Then /^I should see the group dashboard (with|without) quick post form$/
   */
  public function iShouldSeeTheGroupDashboard($quick_post_show) {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('Group menu item "Home" should be active');
    if ($quick_post_show == 'with') {
      $steps[] = new Step\When('I should see the Quick Post form');
    }
    $steps[] = new Step\When('I should see the Activity stream');
    $steps[] = new Step\When('I should see the Highlights');
    $steps[] = new Step\When('I should see the Group Details');
    $steps[] = new Step\When('I should see the Group Header with banner');
    $steps[] = new Step\When('I should see the Recent Members');

    return $steps;
  }

  /**
   * @Given /^Group menu item "([^"]*)" should be active$/
   */
  public function groupMenuItemShouldBeActive($label) {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', '#block-menu-c4m-og-menu a.active');
    if ($el === null) {
      throw new \Exception('The group menu has no active items.');
    }

    if ($el->getText() !== $label) {
      $params = array('@label' => $label);
      throw new \Exception(format_string('Active menu item is not "@label".', $params));
    }
  }
}
