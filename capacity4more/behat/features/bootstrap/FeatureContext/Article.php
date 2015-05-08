<?php
/**
 * @file
 * Context methods about Articles (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait Article {


  /**
   * @Given /^An article is created with title "([^"]*)"$/
   */
  public function anArticleIsCreatedWithTitle($title) {
    $steps = array();
    $steps[] = new Step\When('I am logged in as user "mariecurie"');
    $steps[] = new Step\When('I visit "node/add/article"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-value" with "Some text"');
    $steps[] = new Step\When('I press "c4m_related_topic"');
    $steps[] = new Step\When('I check the box "Fire"');
    $steps[] = new Step\When('I press "Publish"');
    $steps[] = new Step\When('I should see "has been created."');
    return $steps;
  }
}