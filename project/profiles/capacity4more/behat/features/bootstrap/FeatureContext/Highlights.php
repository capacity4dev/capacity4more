<?php
/**
 * @file
 * Context methods about Highlights (view, add/remove from highlights).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Highlights {
  /**
   * @Given /^I should see the Highlights$/
   */
  public function iShouldSeeTheHighlights() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-c4m-overview-og-highlights');
    if ($el === null) {
      throw new \Exception('The Highlights pane is not visible.');
    }

    // Check if promoted node 'Photoalbum 3' is there.
    $node_title = 'Photoalbum 3';
    if (strpos($el->getText(), $node_title) === FALSE) {
      $params = array('@node_title' => $node_title);
      throw new \Exception(format_string('Node "@node_title" should be on the' .
          ' Highlights but is missing.',
          $params));
    }
  }

  /**
   * @Then /^I should be able to toggle the (group|project) highlight link$/
   */
  public function iShouldBeAbleToToggleTheHighlightLink($type) {
    $page = $this->getSession()->getPage();
    $link = $page->find('css', ".c4m-$type-node-highlight a");
    if ($link === null) {
      throw new \Exception('The Highlight link is missing.');
    }

    $promoted = $page->find('css', ".c4m-$type-node-highlight a .fa-star");

    $link->click();

    // Since we toggle the link, we dependent on the previous state of it,
    // hence the class to appear should be relative the previous one.
    // 'fa-star' for promoted node, and 'fa-star-o' for non promoted one.
    $class = 'fa-star';
    if ($promoted) {
      $class .= '-o';
    }

    $this->waitForXpathNode("//div[contains(@class, \"c4m-$type-node-highlight\")]//i[contains(@class, \"$class\")]", TRUE);
  }

}
