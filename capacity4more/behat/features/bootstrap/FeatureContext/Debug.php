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
   * Save the output HTML & a screenshot after a failed test.
   *
   * @param StepEvent $event
   */
  public function debugDumpAfterFailedStep(\Behat\Behat\Event\StepEvent $event) {
    if ($event->getResult() !== $event::FAILED) {
      return;
    }

    // Check if we need to dump output.
    if (!$this->debug['dump_html'] && !$this->debug['dump_screenshot']) {
      return;
    }

    // Check if the path to dump the output was set.
    if (!$this->debug['dump_path']) {
      return;
    }

    // Get the file path.
    $filePath = $this->debug['dump_path'];
    if (!file_exists($filePath)) {
      if (!mkdir($filePath)) {
        return;
      }
    }

    // Unique filename.
    $fileName = rtrim(realpath($filePath), DIRECTORY_SEPARATOR)
      . DIRECTORY_SEPARATOR
      . date('YmdHis') . '_' . uniqid();

    // Get the objects needed to extract the debug information.
    $session   = $this->getSession();
    $page      = $session->getPage();
    $driver    = $session->getDriver();
    $exception = $event->getException();

    // Put the exception messages in an array.
    $message = array($exception->getMessage());

    // Save HTML output.
    if ($this->debug['dump_html']) {
      $html = array(
        '<!--',
        '  HTML dump from BEHAT',
        sprintf('  Date : %s', date('Y-m-d H:i:s')),
        sprintf('  Url  : %s', $session->getCurrentUrl()),
        '-->',
        $page->getContent(),
      );
      file_put_contents($fileName . '.html', implode(PHP_EOL, $html));
      $message[] = sprintf('HTML saved to: %s', $fileName . '.html');
    }

    // Take & save a screenshot.
    if ($this->debug['dump_screenshot']
      && $driver instanceof \Behat\Mink\Driver\Selenium2Driver
    ) {
      $screenshot = $driver->getScreenshot();
      file_put_contents($fileName . '.png', $screenshot);
      $message[] = sprintf('Screenshot saved to: %s', $fileName . '.png');
    }

    // Add the debug information to the step exception message.
    $reflectionObject = new \ReflectionObject($exception);
    $reflectionObjectProp = $reflectionObject->getProperty('message');
    $reflectionObjectProp->setAccessible(true);
    $reflectionObjectProp->setValue(
      $exception,
      implode(PHP_EOL, $message)
    );
  }
}
