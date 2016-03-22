<?php
/**
 * @file
 * Context methods about Group dashboard.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait MainMenu {
  /**
   * @Given /^Main menu item "([^"]*)" should be active$/
   */
  public function mainMenuItemShouldBeActive($label) {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', '#navbar ul.menu a.active');
    if ($el === null) {
      throw new \Exception('The main menu has no active items.');
    }

    if ($el->getText() !== $label) {
      $params = array('@label' => $label);
      throw new \Exception(format_string('Active menu item is not "@label".', $params));
    }
  }
}
