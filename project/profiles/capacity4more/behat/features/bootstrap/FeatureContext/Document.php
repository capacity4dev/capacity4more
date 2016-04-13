<?php
/**
 * @file
 * Context methods about Documents (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait Document {
  /**
   * @When /^I visit the documents overview of group "([^"]*)"$/
   */
  public function iVisitTheDocumentsOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'documents');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @Then /^I should see the documents overview$/
   */
  public function iShouldSeeTheDocumentsOverview() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('I should be able to sort the overview');
    $steps[] = new Step\When('I should see the sidebar search');
    $steps[] = new Step\When('I should see the sidebar facet with title "Type"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Topics"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Categories"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Language"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Regions & Countries"');
    $steps[] = new Step\When('I should see the sidebar facet with title "Tags"');

    return $steps;
  }

  /**
   * @When /^I visit the documents overview of group "([^"]*)" in "([^"]*)" view$/
   */
  public function iVisitTheDocumentsOverviewOfGroupInView($title, $page) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $path = '';
    switch ($page) {
      case 'list':
        $path = 'documents';
        break;
      case 'table':
        $path = 'documents/table';
    }
    $uri = $this->createUriWithGroupContext($group, $path);
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @When /^I visit the filtered list view of the documents of group "([^"]*)"$/
   */
  public function iVisitTheFilteredListViewOfTheDocumentsOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    // Filter by
    // Topic: 'Earth'
    // Search term: 'Nobel'
    $options = array(
      'query' => array(
        'search_api_views_fulltext' => 'Nobel',
        'f[0]' => 'c4m_vocab_topic:1',
      )
    );
    $uri = $this->createUriWithGroupContext($group, 'documents', $options);
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @Given /^I switch to "([^"]*)" view$/
   */
  public function iSwitchToView($icon_type) {
    $page = $this->getSession()->getPage();
    $link = $page->find('css', '.region-content .view-header .' .
      $icon_type . '-teaser-view');
    $link->click();
    if (!count($link)) {
      throw new \Exception("No $icon_type overview icon found.");
    }

  }

  /**
   * @Then /^I should still have retained search filters$/
   */
  public function iShouldStillHaveRetainedSearchFilters() {
    $url = $this->getSession()->getCurrentUrl();
    $parsed_url = drupal_parse_url($url);
    // Check if we still have ...
    // Topic: 'Earth'
    // Search term: 'Nobel'
    if (empty($parsed_url['query']['search_api_views_fulltext']) ||
      'Nobel' != $parsed_url['query']['search_api_views_fulltext'] ||
      empty($parsed_url['query']['f']['0']) ||
      'c4m_vocab_topic:1' != $parsed_url['query']['f']['0']) {
      throw new \Exception("I am not on table view retaining filters and search
        term.");
    }
  }

  /**
   * @Then /^I should see the document detail page$/
   */
  public function iShouldSeeTheDocumentDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a "Comment" field');
    $steps[] = new Step\When('I should see a "Title" field');
    $steps[] = new Step\When('I should see a "Download" field');
    $steps[] = new Step\When('I should see a "Details" field group');

    return $steps;
  }

  /**
   * @Given /^I should be able to see the "([^"]*)" icon$/
   */
  public function iShouldBeAbleToSeeTheIcon($icon_type) {
    $page = $this->getSession()->getPage();
    $icon = $page->findAll('css', '.region-content .view-header .' .
      $icon_type . '-teaser-view');

    if (!count($icon)) {
      throw new \Exception("No $icon_type overview icon found.");
    }
  }
}
