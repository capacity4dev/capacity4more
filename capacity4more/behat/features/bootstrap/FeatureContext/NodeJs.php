<?php
/**
 * @file
 * Context methods about Nodes accessed trough JS (js-add, js-edit).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 *
 * @TODO : This functionality should be removed in favor of native Drupal forms.
 */
trait NodeJs {
  /**
   * @When /^I start creating "([^"]*)" in full form with title "([^"]*)" in group "([^"]*)"$/
   */
  public function iStartCreatingInFullFormWithTitle($bundle, $title, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');

    $uri = strtolower(str_replace(' ', '-', trim($group)));

    $steps[] = new Step\When('I visit "' . $uri . '/node/add/' . $bundle . '"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-value" with "Some text in the body"');
    return $steps;
  }
}
