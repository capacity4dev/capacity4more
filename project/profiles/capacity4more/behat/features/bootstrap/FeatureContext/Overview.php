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

  /**
   * @Then /^I should( not)? see "([^"]*)" on that overview$/
   */
  public function iShouldSeeOnThatOverview($should_not_see = FALSE, $text) {
    $last_page = FALSE;

    while (!$last_page) {
      try {
        // Check if the text exists on the page.
        $this->assertPageContainsText($text);

        if ($should_not_see) {
          // Found, but should not, set as last page cause found anyway.
          $last_page = TRUE;

          $message = sprintf('The text "%s" appears in the text of this page, but it should not.', $text);
          throw new ResponseTextException($message, $this->session);
        }

        // Text has found and should be found.
        return;
      }
      catch (\Exception $text_exception) {
        // Might be in case we should not see the text but we did.
        if ($should_not_see && $last_page) {
          throw $text_exception;
        }

        try {
          $this->clickLink('Next');
        }
        catch (\Exception $e) {
          // We are in the last page, stop the loop.
          $last_page = TRUE;
        }
      }
    }

    // Text was not found, as expected.
    if ($should_not_see) {
      return;
    }

    // Text was not found, but should have.
    throw $text_exception;
  }

  /**
   * @Then /^I should( not)? see "([^"]*)" on the "([^"]*)" overview$/
   */
  public function iShouldSeeOnTheOverview($not = FALSE, $text, $uri) {
    $see = $not ? ' not' : '';

    $steps[] = new Step\When('I visit "' . $uri . '"');
    $steps[] = new Step\When('I should' . $see . ' see "' . $text . '" on that overview');

    return $steps;
  }

}
