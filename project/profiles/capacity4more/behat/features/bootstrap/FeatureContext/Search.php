<?php
/**
 * @file
 * Context methods about Search functionality.
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Search {
  /**
   * @Then /^I should be able to sort the overview$/
   */
  public function iShouldBeAbleToSortTheOverview() {
    $page = $this->getSession()->getPage();
    $sorts = $page->findAll('css', '.region-content .view-header .search-api-sorts li');

    if (!count($sorts)) {
      throw new \Exception("No sort options found.");
    }
  }

  /**
   * @Then /^I should see the sidebar search$/
   */
  public function iShouldSeeTheSidebarSearch() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', '.region-sidebar-first #edit-text');
    if ($el === null) {
      throw new \Exception('The Sidebar Search block is not visible.');
    }
  }

  /**
   * @Then /^I should see the sidebar facet with title "([^"]*)"$/
   */
  public function iShouldSeeTheSidebarFacet($title) {
    $page = $this->getSession()->getPage();
    $facets = $page->findAll('css', '.region-sidebar-first .block-facetapi');

    $found = FALSE;
    foreach ($facets as $facet) {
      $block_title = $facet->find('css', '.block-title');
      if (!$block_title || $block_title->getText() !== $title) {
        continue;
      }

      $found = TRUE;
      break;
    }

    if (!$found) {
      $params = array(
        '@title' => $title,
      );
      throw new \Exception(format_string("Facet with @title not found.", $params));
    }
  }
}
