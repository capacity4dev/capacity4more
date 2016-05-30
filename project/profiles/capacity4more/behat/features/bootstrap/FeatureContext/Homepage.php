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
   * @Then /^I should see the suggested groups video block$/
   */
  public function iShouldEmbeddedVideoBlock() {
    $steps[] = new Step\When('I should see "You\'re not yet a member of any group." in the "div.video-preview-wrapper" element');
    $steps[] = new Step\When('I should see "Learn how to learn and share knowledge by joining a group" in the "div.video-preview-wrapper" element');

    return $steps;
  }

  /**
   * @Then /^I should wait not to see "([^"]*)"$/
   */
  public function iShouldWaitNotToSee($text) {
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should not see "' . $text . '"');

    return $steps;
  }

  /**
   * @Then /^I should wait not to see "([^"]*)" in the "([^"]*)" element$/
   */
  public function iShouldWaitNotToSeeInElement($text, $element) {
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should not see "' . $text . '" in the "' . $element . '" element');

    return $steps;
  }

  /**
   * @Then /^I should wait to see "([^"]*)"$/
   */
  public function iShouldWaitToSee($text) {
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should see "' . $text . '"');

    return $steps;
  }

  /**
   * @Then /^I should see the carousel and all the slides$/
   */
  public function iShouldSeeFunctioningCarousel() {
    $steps[] = new Step\When('I should wait to see "VOICES & VIEWS"');
    $steps[] = new Step\When('I should see "See more"');
    $steps[] = new Step\When('I should see an ".owl-carousel" element');
    $steps[] = new Step\When('I should see an "p.intro-text" element');

    // Flip to the next slide (If the test can't execute the function, an error will appear).
    $nextButton = $this->getSession()->getPage()->find('css', '.owl-next');
    if (!$nextButton) {
      throw new \Exception("Couldn't find the next button in the owl carousel on the homepage.");
    }
    $nextButton->press();

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
    $blocks = $page->findAll('css', '.node-event.view-mode-block_list');

    if (count($blocks) > $events_no) {
      throw new \Exception(sprintf('There\'s more than %d Upcoming event showing.', $events_no));
    }
    elseif (count($blocks) < $events_no) {
      throw new \Exception(sprintf('There\'s less than %d Upcoming event showing.', $events_no));
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
