<?php
/**
 * @file
 * Context methods about Help book.
 */

namespace FeatureContext;

trait HelpBook {
  /**
   * @When /^I define the main help book page$/
   */
  public function iDefineTheMainHelpBookPage() {
    $main_help_page = $this->loadGroupByTitleAndType('Help & Guidance', 'book');
    variable_set('c4m_help_and_guidance_main_book', $main_help_page->nid);
  }
}
