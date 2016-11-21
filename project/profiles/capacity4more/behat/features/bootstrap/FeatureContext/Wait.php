<?php
/**
 * @file
 * Context methods to just wait or to wait until something is available.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Wait {
  /**
   * @Given /^I wait$/
   */
  public function iWait() {
    sleep(10);
  }

  /**
   * Helper to wait until a specific dom element is available.
   *
   * @param string $xpath
   * @param string $appear
   *
   * @return bool
   *
   * @throws Exception
   */
  public function waitForXpathNode($xpath, $appear) {
    $this->waitFor(function($context) use ($xpath, $appear) {
        try {
          $nodes = $context->getSession()->getDriver()->find($xpath);
          if (count($nodes) > 0) {
            $visible = $nodes[0]->isVisible();
            return $appear ? $visible : !$visible;
          } else {
            return !$appear;
          }
        } catch (WebDriver\Exception $e) {
          if ($e->getCode() == WebDriver\Exception::NO_SUCH_ELEMENT) {
            return !$appear;
          }
          throw $e;
        }
      });
  }

  /**
   * @Given /^I wait for text "([^"]+)" to (appear|disappear) in "([^"]+)"$/
   */
  public function iWaitForText($text, $appear, $element_name) {
    $this->waitForXpathNode(".//*[contains(@name, \"$element_name\")]//*[contains(normalize-space(string(text())), \"$text\")]", $appear == 'appear');
  }

  /**
   * @Given /^I wait for the text "([^"]+)" to (appear|disappear) (in|from) "([^"]+)" (id|class|name)$/
   *
   * Ths $syntax is not really important, but Behat requires it to be a
   * parameter because of the choice in|from.
   */
  public function iWaitForTextLookByProperty($text, $appear, $syntax, $element_name, $property) {
    $this->waitForXpathNode(".//*[contains(@$property, \"$element_name\")]//*[contains(normalize-space(string(text())), \"$text\")]", $appear == 'appear');
  }

  private function waitFor($fn, $timeout = 30000) {
    $start = microtime(true);
    $end = $start + $timeout / 1000.0;
    while (microtime(true) < $end) {
      if ($fn($this)) {
        return;
      }
    }
    throw new \Exception("waitFor timed out");
  }
}
