<?php
/**
 * @file
 * Context methods about Wiki Pages (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait WikiPage {

  /**
   * @Then /^I should see the Wiki detail page$/
   */
  public function iShouldSeeTheWikiDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Title in right region" field');
    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a "Comment" field');
    $steps[] = new Step\When('I should see a Wiki "table of contents" in the "left" bar');
    $steps[] = new Step\When('I should see a Wiki "navigation" in the "right" bar');
    return $steps;
  }

  /**
   * @Given /^I should see a Wiki "([^"]*)" in the "([^"]*)" bar$/
   */
  public function iShouldSeeAWikiInTheBar($wrapper, $region) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    $wrapper_class = '.book-';

    switch($wrapper) {
      case 'table of contents':
        $wrapper_class .= 'toc';
        break;
      case 'navigation':
        $wrapper_class .= 'navigation';
        break;
    }

    $locator = '.region-content .group-' . $region . ' ' . $wrapper_class ;

    if (!empty($locator)) {
      $element = $page->findAll('css', $locator);
    }

    if (!count($element)) {
      throw new \Exception("No Wiki $wrapper found in $region region.");
    }
  }

}
