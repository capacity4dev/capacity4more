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
   * Dump the session to HTML & screenshot after each successfull test.
   *
   * @param \Behat\Behat\Event\StepEvent $event
   */
  public function debugDumpSessionAfterEachStep(\Behat\Behat\Event\StepEvent $event) {
    if (!$this->debug['dump_all_steps']) {
      return;
    }

    // Errors are dumped separately.
    if ($event->getResult() === $event::FAILED) {
      return;
    }

    // Build the information text.
    $stepInfo = sprintf('Debug step (%s):', $event->getStep()->getText());

    $this->_debugDumpSession(
      array($stepInfo),
      $this->debug['dump_html'],
      $this->debug['dump_screenshot']
    );
  }

  /**
   * @AfterStep
   *
   * Save the output HTML & a screenshot after a failed test.
   *
   * @param \Behat\Behat\Event\StepEvent $event
   */
  public function debugDumpAfterFailedStep(\Behat\Behat\Event\StepEvent $event) {
    if ($event->getResult() !== $event::FAILED) {
      return;
    }

    // Build the information text.
    $stepInfo = sprintf('Debug FAILED step (%s):', $event->getStep()->getText());

    $this->_debugDumpSession(
      array($stepInfo),
      $this->debug['dump_html'],
      $this->debug['dump_screenshot']
    );
  }

  /**
   * Force the system to produce session dumps to html and/or screenshot.
   *
   * @param mixed $messages
   *   Optional string or array of messages to add to the output screen.
   * @param bool $dump_html
   *   Should the html output be saved as file?
   * @param bool $dump_screenshot
   *   Should a screenshot be saved?
   */
  public function debugDumpSession(
    $messages = array(),
    $dump_html = true,
    $dump_screenshot = true
  ) {
    if (!is_array($messages)) {
      $messages = array($messages);
    }

    $messages = array('Debug Dump Session:') + $messages;
    $this->_debugDumpSession($messages, $dump_html, $dump_screenshot);
  }

  /**
   * Helper to create & dump the actual debug information.
   *
   * @param array $messages
   *   Optional array of messages to add to the output screen.
   * @param bool $dump_html
   *   Should the html output be saved as file?
   * @param bool $dump_screenshot
   *   Should a screenshot be saved?
   */
  private function _debugDumpSession(
    array $messages = array(),
    $dump_html = true,
    $dump_screenshot = true
  ) {
    // Check if we need to dump output.
    if (!$dump_html && !$dump_screenshot) {
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

    // Save HTML output.
    if ($dump_html) {
      $html = array(
        '<!--',
        '  HTML dump from BEHAT',
        sprintf('  Date : %s', date('Y-m-d H:i:s')),
        sprintf('  Url  : %s', $session->getCurrentUrl()),
        '-->',
        $page->getContent(),
      );
      file_put_contents($fileName . '.html', implode(PHP_EOL, $html));
      $messages[] = sprintf('HTML saved to: %s', $fileName . '.html');
    }

    // Take & save a screenshot.
    if ($dump_screenshot
      && $driver instanceof \Behat\Mink\Driver\Selenium2Driver
    ) {
      $screenshot = $driver->getScreenshot();
      file_put_contents($fileName . '.png', $screenshot);
      $messages[] = sprintf('Screenshot saved to: %s', $fileName . '.png');
    }
    elseif ($dump_screenshot) {
      var_dump($driver);
    }

    // Output the messages on screen.
    $this->printDebug(implode("\n", $messages));
  }
}
