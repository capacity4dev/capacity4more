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
}
