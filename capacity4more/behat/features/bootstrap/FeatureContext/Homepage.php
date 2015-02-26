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
   * @Then /^I should see the featured block$/
   */
  public function iShouldFeaturedBlock() {
    $steps[] = new Step\When('I should see "Featured block"');
    $steps[] = new Step\When('I should see "Nobel Foundation" in the "div.pane-featured-block" element');
    $steps[] = new Step\When('I should see "Nobel Banquet" in the "div.pane-featured-block" element');
    $steps[] = new Step\When('I should see "Second Prize" in the "div.pane-featured-block" element');

    return $steps;
  }

  /**
   * @Then /^I should see the carousel and all the slides$/
   */
  public function iShouldSeeFunctioningCarousel() {
    $steps[] = new Step\When('I should see "VOICES & VIEWS"');
    $steps[] = new Step\When('I should see "Read all"');
    $steps[] = new Step\When('I should see "Gene Therapy Achieves Major Success" in the "div.carousel" element');
    $steps[] = new Step\When('I should see "The First Neutrinos from Outside the Solar System" in the "div.carousel" element');
    $steps[] = new Step\When('I should see "Recovery of Oldest Human DNA" in the "div.carousel" element');

    // Flip to the next slide (If the test can't execute the function, an error will appear).
    $this->getSession()->executeScript("angular.element('.rn-carousel-control').scope().nextSlide()");

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
   * @Then /^I should see only "([^"]*)" events$/
   */
  public function iShouldSeeOnlyOneEvent($events_no) {
    $page = $this->getSession()->getPage();
    $blocks = $page->findAll('css', '.view-mode-upcoming_event');

    if (count($blocks) <> $events_no) {
      throw new \Exception('There\'s more than one Upcoming event showing.');
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
