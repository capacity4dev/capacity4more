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
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait Discussion {
  /**
   * @When /^I visit the discussions overview of group "([^"]*)"$/
   */
  public function iVisitTheDiscussionsOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'discussions');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @Then /^I should see the discussions overview$/
   */
  public function iShouldSeeTheDiscussionsOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Categories"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Language"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Regions & Countries"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Tags"');
    $steps[] = new Step\When('I should see a "Author" field on an item in the overview');

    return $steps;
  }

  /**
   * @Then /^I should see the discussion detail page$/
   */
  public function iShouldSeeTheDiscussionDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a "Comment" field');
    $steps[] = new Step\When('I should see a "Title" field');
    $steps[] = new Step\When('I should see a "Details" field group');

    return $steps;
  }

  /**
   * @Given /^a discussion "([^"]*)" in group "([^"]*)" is created$/
   */
  public function aDiscussionInGroupIsCreated($title, $group_title) {
    $steps = array();

    $steps[] = new Step\When('I visit "' . $this->humanToMachineReadable($group_title, '-') . '/node/add/discussion"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in ckeditor field "edit-c4m-body-und-0-value" with "This is default discussion."');
    $steps[] = new Step\When('I check the related topic checkbox');
    $steps[] = new Step\When('I press "Publish"');

    // Check there was no error.
    $steps[] = new Step\When('I should not see "There was an error"');

    return $steps;
  }
}
