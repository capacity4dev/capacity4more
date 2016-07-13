<?php
/**
 * @file
 * Context methods about (shared) Overview functionality.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Overview {
  /**
   * @Then /^I should not see the "([^"]*)" link above the overview$/
   */
  public function iShouldNotSeeTheLinkAboveTheOverview($label) {
    $page = $this->getSession()->getPage();
    $links = $page->findAll('css', '.region-content .view-header .node-create');
    foreach ($links as $link) {
      if ($link->getText() !== $label) {
        continue;
      }

      $params = array(
        '@label' => $label,
      );
      throw new \Exception(format_string("Link @label should NOT be above the overview.", $params));
    }
  }

  /**
   * @Then /^I should see the "([^"]*)" link above the overview$/
   */
  public function iShouldSeeTheLinkAboveTheOverview($label) {
    $page = $this->getSession()->getPage();
    $links = $page->findAll('css', '.region-content .view-header .node-create');

    $found = false;
    foreach ($links as $link) {
      if ($link->getText() !== $label) {
        continue;
      }

      $found = TRUE;
      break;
    }

    if (!$found) {
      $params = array(
        '@label' => $label,
      );
      throw new \Exception(format_string("Link @label is not found above the overview.", $params));
    }
  }

  /**
   * @Given /^I should see a "([^"]*)" field on an item in the overview$/
   */
  public function iShouldSeeAFieldOnAnItemInTheOverview($field) {
    $page = $this->getSession()->getPage();
    switch($field) {
      case 'Author':
        $class = 'user-name';
        break;
      case 'Organiser':
        $class = 'organiser';
        break;

    }
    $element = $page->findAll('css', '.region-content .view-content .' . $class);

    if (!count($element)) {
      throw new \Exception("No $field found in the overview.");
    }
  }
}
