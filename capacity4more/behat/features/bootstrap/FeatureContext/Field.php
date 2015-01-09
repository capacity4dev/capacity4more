<?php
/**
 * @file
 * Context methods about Fields (global functionality).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Field {
  /**
   * @Given /^I should see a "([^"]*)" field$/
   */
  public function iShouldSeeAField($field) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    switch($field) {
      case 'Author':
        $locator = '.region-content .user-name';
        break;
      case 'Comment':
        $locator = '.region-content .comment-wrapper';
        break;
      case 'Description':
        $locator = '.region-content .field-name-c4m-body';
        break;
      case 'Download':
        $locator = '.region-content .download-link';
        break;
      case 'Group banner':
        $locator = '.region-content-top .group-banner';
        break;
      case 'Group title':
        $locator = '.region-content-top .group-title';
        break;
      case 'Group type':
        $locator = '.region-content .field-name-c4m-ds-group-access-info';
        break;
      case 'Preview':
        $locator = '.region-content .view-mode-c4m_preview';
        break;
      case 'Regions & Countries':
        $locator = '.region-content .field-name-c4m-vocab-geo';
        break;
      case 'Title':
        $locator = '.main-container .page-header, .node .field-name-title';
        break;
      case 'Title in right region':
        $locator = '.main-container .field-name-title';
        break;
      case 'Topics':
        $locator = '.region-content .field-name-c4m-related-topic';
        break;
    }

    if (!empty($locator)) {
      $element = $page->findAll('css', $locator);
    }

    if (!count($element)) {
      throw new \Exception("No $field field found.");
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
      case 'Documents':
        $class = 'group-node-documents';
        break;
      case 'Group dashboard details':
        $class = 'group-details';
        break;
      case 'Location':
        $class = 'group-node-location';
        break;
      case 'Organiser':
        $class = 'group-node-organiser';
        break;
    }
    if (!empty($class)) {
      $element = $page->findAll('css', '.region-content .' . $class);
    }

    if (!count($element)) {
      throw new \Exception("No $fieldgroup field group found.");
    }
  }
}
