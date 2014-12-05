<?php
/**
 * @file
 * Context methods to debug tests.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * Methods to help debug problems.
 */
trait Debug {
  /**
   * @Then /^I should print page$/
   */
  public function iShouldPrintPage() {
    $element = $this->getSession()->getPage();
    print_r($element->getContent());
  }

  /**
   * @Then /^I should print page to "([^"]*)"$/
   */
  public function iShouldPrintPageTo($file) {
    $element = $this->getSession()->getPage();
    file_put_contents($file, $element->getContent());
  }

  /**
   * @AfterStep
   *
   * Take a screenshot after failed steps.
   */
  public function takeScreenshotAfterFailedStep($event) {
    if ($event->getResult() != 4) {
      // Step didn't fail.
      return;
    }
    if (!($this->getSession()->getDriver() instanceof \Behat\Mink\Driver\Selenium2Driver)) {
      // Not a Selenium driver (e.g. PhantomJs).
      return;
    }

    $file_name = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR . 'behat-failed-step.png';
    $screenshot = $this->getSession()->getDriver()->getScreenshot();
    file_put_contents($file_name, $screenshot);
    print "Screenshot for failed step created in $file_name";
  }
}
