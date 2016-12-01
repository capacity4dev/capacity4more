<?php
/**
 * @file
 * Context methods about Projects (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step;


trait Project {

  /**
   * @Given /^a project "([^"]*)" is created with project manager "([^"]*)"$/
   */
  public function aProjectIsCreatedWithGroupManager($title, $username) {
    $steps = array();
    $steps[] = new Step\When('I am logged in as user "' . $username . '"');
    $steps[] = new Step\When('I visit "node/add/project"');

    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');

    // This is a required tag.
    $steps[] = new Step\When('I check the related topic checkbox');

    $steps[] = new Step\When('I fill in ckeditor field "edit-c4m-body-und-0-value" with "This is default summary."');



    // This is the banner
//
    $steps[] = new Step\When('I press "Request"');

    // Check there was no error.
  //  $steps[] = new Step\When('I should not see "There was an error"');
 //   $steps[] = new Step\When('I should be on the homepage');
    $steps[] = new Step\When('I should see "Project ' . $title . ' has been created."');

//    $steps[] = new Step\When('The group "' . $title . '" status is changed by admin to "Draft"');
//    $steps[] = new Step\When('The group "' . $title . '" status is changed by admin to "Published"');
//    $steps[] = new Step\When('I am logged in as user "' . $username . '"');
    return $steps;
  }
}
