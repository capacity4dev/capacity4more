<?php
/**
 * @file
 * Context methods about the Contact page.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;

trait Contact {

  /**
   * @Then /^I should see an enabled "([^"]*)" element$/
   */
  public function iShouldSeeAnEnabledElement($formElement) {
    $page = $this->getSession()->getPage();
    $item = $page->find('css', $formElement);

    if (!isset($item) || $item->hasAttribute('disabled')) {
      $params = array('@element' => $formElement);
      $error = format_string('The form element @element should be enabled', $params);
      throw new \Exception($error);
    }
  }

  /**
   * @Then /^I should see a disabled "([^"]*)" element$/
   */
  public function iShouldSeeADisabledElement($formElement) {
    $page = $this->getSession()->getPage();
    $item = $page->find('css', $formElement);

    if (!isset($item) || !$item->hasAttribute('disabled')) {
      $params = array('@element' => $formElement);
      $error = format_string('The form element @element should be disabled', $params);
      throw new \Exception($error);
    }
  }

}
