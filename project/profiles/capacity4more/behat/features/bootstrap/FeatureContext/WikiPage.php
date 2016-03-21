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
    $steps[] = new Step\When('I should see a Wiki "table of contents" in the "left" bar');
    $steps[] = new Step\When('I should see a Wiki "navigation" in the "right" bar');
    $steps[] = new Step\When('I should see child of current Wiki page expanded in "table of contents" in the "left" bar');
    $steps[] = new Step\When('I should not see the grandchild of current Wiki page expanded in "table of contents" in the "left" bar');
    return $steps;
  }

  /**
   * @Then /^I should see an unpublished Wiki detail page$/
   */
  public function iShouldSeeAnUnpublishedWikiDetailPage() {
    $steps[] = new Step\When('I should see a "Title in right region" field');
    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a Wiki "table of contents" in the "left" bar');
    return $steps;
  }

  /**
   * @Then /^I should see the wiki create links$/
   */
  public function iShouldSeeTheWikiCreateLinks() {
    $steps[] = new Step\When('I should see a Wiki "add links" in the "left" bar');
    return $steps;
  }

  /**
   * @Then /^I should not see the wiki create links$/
   */
  public function iShouldNotSeeTheWikiCreateLinks() {
    $steps[] = new Step\When('I should not see a Wiki "add links" in the "left" bar');
    return $steps;
  }


  /**
   * @Given /^I should see a Wiki "([^"]*)" in the "([^"]*)" bar$/
   */
  public function iShouldSeeAWikiInTheBar($wrapper, $region) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    $wrapper_class = '.book-';

    switch ($wrapper) {
      case 'table of contents':
        $wrapper_class .= 'toc';
        break;

      case 'navigation':
        $wrapper_class .= 'navigation';
        break;

      case 'add links':
        $wrapper_class = '.wiki-add-links';
        break;
    }

    $locator = '.region-content .group-' . $region . ' ' . $wrapper_class;

    if (!empty($locator)) {
      $element = $page->findAll('css', $locator);
    }

    if (!count($element)) {
      throw new \Exception("No Wiki $wrapper found in $region region.");
    }
  }

  /**
   * @Given /^I should not see a Wiki "([^"]*)" in the "([^"]*)" bar$/
   */
  public function iShouldNotSeeAWikiInTheBar($wrapper, $region) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    $wrapper_class = '.book-';

    switch ($wrapper) {
      case 'table of contents':
        $wrapper_class .= 'toc';
        break;

      case 'navigation':
        $wrapper_class .= 'navigation';
        break;

      case 'add links':
        $wrapper_class = '.wiki-add-links';
        break;
    }

    $locator = '.region-content .group-' . $region . ' ' . $wrapper_class;

    if (!empty($locator)) {
      $element = $page->findAll('css', $locator);
    }

    if (count($element)) {
      throw new \Exception("Wiki $wrapper found in $region region.");
    }
  }

  /**
   * @Given /^I should see child of current Wiki page expanded in "([^"]*)" in the "([^"]*)" bar$/
   */
  public function iShouldSeeChildOfCurrentWikiPageExpandedInInTheBar($wrapper, $region) {
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

    $locator = '.region-content .group-' . $region . ' ' . $wrapper_class .
      ' li.expanded.active ul.collapse.in li.expanded a';

    if (!empty($locator)) {
      $element = $page->find('css', $locator);
    }

    if ($element === null ||
        strpos($element->getText(), 'Diplomas', 0) === FALSE) {
      throw new \Exception("No expanded child of Wiki page found.");
    }
  }

  /**
   * @Given /^I should not see the grandchild of current Wiki page expanded in "([^"]*)" in the "([^"]*)" bar$/
   */
  public function iShouldNotSeeTheGrandchildOfCurrentWikiPageExpandedInInTheBar($wrapper, $region) {
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

    $locator = '.region-content .group-' . $region . ' ' . $wrapper_class .
      ' li.expanded.active ul.collapse.in li.expanded ul.collapse.in li.expanded a';

    if (!empty($locator)) {
      $element = $page->find('css', $locator);
    }

    if ($element !== null) {
      throw new \Exception("Expanded grandchild of Wiki page found where it should not.");
    }
  }

  /**
   * @Given /^I should see the "([^"]*)" link on the group menu wiki navigation$/
   */
  public function iShouldSeeTheLinkOnTheGroupMenuWikiNavigation($text) {
    $page = $this->getSession()->getPage();
    $locator = '#c4m-og-menu > ul > li.dropdown > div.dropdown-menu > ul > li > a';
    $links = $page->findAll('css', $locator);
    $found = FALSE;
    foreach ($links as $link) {
      if (strpos($link->getText(), $text) !== FALSE) {
        $found = TRUE;
        break;
      }
    }

    if (!$found) {
      throw new \Exception("No $text link found on group menu.");
    }

  }

  /**
   * @Given /^I should not see the "([^"]*)" link on the group menu wiki navigation$/
   */
  public function iShouldNotSeeTheLinkOnTheGroupMenuWikiNavigation($text) {
    $page = $this->getSession()->getPage();
    $locator = '#c4m-og-menu > ul > li.dropdown > div.dropdown-menu > ul > li > a';
    $links = $page->findAll('css', $locator);
    $found = FALSE;
    foreach ($links as $link) {
      if (strpos($link->getText(), $text) !== FALSE) {
        $found = TRUE;
        break;
      }
    }

    if ($found) {
      throw new \Exception("$text link found on group menu but should not be found in there.");
    }
  }
}
