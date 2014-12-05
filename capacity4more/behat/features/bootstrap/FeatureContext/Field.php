<?php
/**
 * @file
 * Context methods about Fields (global functionality).
 */

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Guzzle\Service\Client;
use Behat\Behat\Context\Step;


trait FeatureContext_Field {
  /**
   * @Given /^I should see a "([^"]*)" field$/
   */
  public function iShouldSeeAField($field) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    switch($field) {
      case 'Author':
        $locator = '.region-content .username';
        break;
      case 'Comment':
        $locator = '.region-content .comment-wrapper';
        break;
      case 'Download':
        $locator = '.region-content .download-link';
        break;
      case 'Preview':
        $locator = '.region-content .view-mode-c4m_preview';
        break;
      case 'Title':
        $locator = '.main-container .page-header';
        break;
    }

    if (!empty($locator)) {
      $element = $page->findAll('css', $locator);
    }

    if (!count($element)) {
      throw new Exception("No $field field found.");
    }
  }

  /**
   * @Given /^I should see a "([^"]*)" field group$/
   */
  public function iShouldSeeAFieldGroup($fieldgroup) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    switch($fieldgroup) {
      case 'Details':
        $class = 'group-node-details';
        break;
    }
    if (!empty($class)) {
      $element = $page->findAll('css', '.region-content .' . $class);
    }

    if (!count($element)) {
      throw new Exception("No $fieldgroup field group found.");
    }
  }
}
