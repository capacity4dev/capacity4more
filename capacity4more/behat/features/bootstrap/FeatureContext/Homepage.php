<?php
/**
 * @file
 * Context methods about Group dashboard.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Homepage {
  /**
   * @When /^I visit the site homepage$/
   */
  public function iVisitTheSiteHomepage() {
    return new Given('I go to "/"');
  }

  /**
   * @Then /^I should see the site homepage$/
   */
  public function iShouldSeeTheSiteHomepage() {
    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('Main menu item "Home" should be active');

    return $steps;
  }

  /**
   * @Then /^I should see the homepage introduction video block$/
   */
  public function iShouldSeeTheHomepageIntroductionVideoBlock() {
    $page = $this->getSession()->getPage();
    $blocks = $page->findAll('css', '#block-c4m-features-homepage-intro-video');

    if (!count($blocks)) {
      throw new \Exception('Intro block is not on the homepage.');
    }
  }

  /**
   * @Then /^I should not see the homepage introduction video block$/
   */
  public function iShouldNotSeeTheHomepageIntroductionVideoBlock() {
    $page = $this->getSession()->getPage();
    $blocks = $page->findAll('css', '#block-c4m-features-homepage-intro-video');

    if (count($blocks)) {
      throw new \Exception('Intro block should not be on the homepage.');
    }
  }
}
