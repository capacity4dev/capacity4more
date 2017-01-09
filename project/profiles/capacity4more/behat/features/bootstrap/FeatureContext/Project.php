<?php
/**
 * @file
 * Context methods about Projects (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step;


trait Project {

  /**
   * @Given /^The project "([^"]*)" status is changed by admin to "([^"]*)"$/
   */
  public function theProjectStatusIsChangedByAdminTo($group_title, $status) {
    $steps = array();

    $group = $this->loadGroupByTitleAndType($group_title, 'project');
    $steps[] = new Step\When('I am logged in as user "admin"');
    $steps[] = new Step\When('I visit "/node/' . $group->nid . '/edit"');
    $steps[] = new Step\When('I select "' . $status . '" from "edit-c4m-og-status-und"');
    $steps[] = new Step\When('I press "Save"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should see "Project ' . $group_title . ' has been updated."');

    return $steps;
  }
}
