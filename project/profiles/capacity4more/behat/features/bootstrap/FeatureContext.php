<?php
/**
 * Behat context file to support the test scenario's.
 */

use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\Step;

require 'vendor/autoload.php';


// Split FeatureContext in smaller chunks.
require __DIR__ . '/FeatureContext/Activity.php';
require __DIR__ . '/FeatureContext/Article.php';
require __DIR__ . '/FeatureContext/Contact.php';
require __DIR__ . '/FeatureContext/Debug.php';
require __DIR__ . '/FeatureContext/Discussion.php';
require __DIR__ . '/FeatureContext/Document.php';
require __DIR__ . '/FeatureContext/Event.php';
require __DIR__ . '/FeatureContext/Field.php';
require __DIR__ . '/FeatureContext/File.php';
require __DIR__ . '/FeatureContext/Group.php';
require __DIR__ . '/FeatureContext/GroupDashboard.php';
require __DIR__ . '/FeatureContext/GroupManagement.php';
require __DIR__ . '/FeatureContext/GroupMembers.php';
require __DIR__ . '/FeatureContext/GroupMerge.php';
require __DIR__ . '/FeatureContext/Highlights.php';
require __DIR__ . '/FeatureContext/Homepage.php';
require __DIR__ . '/FeatureContext/Learning.php';
require __DIR__ . '/FeatureContext/HelpBook.php';
require __DIR__ . '/FeatureContext/MainMenu.php';
require __DIR__ . '/FeatureContext/Node.php';
require __DIR__ . '/FeatureContext/NodeJs.php';
require __DIR__ . '/FeatureContext/Overview.php';
require __DIR__ . '/FeatureContext/PageAccess.php';
require __DIR__ . '/FeatureContext/People.php';
require __DIR__ . '/FeatureContext/Project.php';
require __DIR__ . '/FeatureContext/QuickPost.php';
require __DIR__ . '/FeatureContext/Search.php';
require __DIR__ . '/FeatureContext/Topic.php';
require __DIR__ . '/FeatureContext/User.php';
require __DIR__ . '/FeatureContext/WikiPage.php';
require __DIR__ . '/FeatureContext/Wait.php';


/**
 * DO NOT ADD ANY CODE TO THIS CONTEXT FILE!
 *
 * All code should go into one of the existing traits or by adding an extra
 * trait.
 *
 * Add a new Trait:
 * - Create a file in the /FeatureContext subfolder.
 * - Add the file to the list of requires (just above this class).
 * - Add the trait to the context class by adding it to the "use" list.
 */
class FeatureContext extends DrupalContext {
  /**
   * Split context file in smaller parts to make merging easier.
   */
  use FeatureContext\Activity;
  use FeatureContext\Article;
  use FeatureContext\Contact;
  use FeatureContext\Debug;
  use FeatureContext\Discussion;
  use FeatureContext\Document;
  use FeatureContext\Event;
  use FeatureContext\Field;
  use FeatureContext\File;
  use FeatureContext\Group;
  use FeatureContext\GroupDashboard;
  use FeatureContext\GroupManagement;
  use FeatureContext\GroupMembers;
  use FeatureContext\GroupMerge;
  use FeatureContext\Highlights;
  use FeatureContext\Homepage;
  use FeatureContext\Learning;
  use FeatureContext\HelpBook;
  use FeatureContext\MainMenu;
  use FeatureContext\Node;
  use FeatureContext\NodeJs;
  use FeatureContext\Overview;
  use FeatureContext\PageAccess;
  use FeatureContext\People;
  use FeatureContext\Project;
  use FeatureContext\QuickPost;
  use FeatureContext\Search;
  use FeatureContext\Topic;
  use FeatureContext\User;
  use FeatureContext\WikiPage;
  use FeatureContext\Wait;

  /**
   * Initializes context.
   *
   * Every scenario gets its own context object.
   *
   * @param array $parameters.
   *   Context parameters (set them up through behat.yml or behat.local.yml).
   */
  public function __construct(array $parameters) {
    if (!empty($parameters['drupal_users'])) {
      $this->drupal_users = $parameters['drupal_users'];
    }

    // Debug config.
    $this->debug = array(
      'dump_html' => empty($parameters['debug']['dump_html'])
        ? false
        : (bool) $parameters['debug']['dump_html'],
      'dump_screenshot' => empty($parameters['debug']['dump_screenshot'])
        ? false
        : (bool) $parameters['debug']['dump_screenshot'],
      'dump_path' => empty($parameters['debug']['dump_path'])
        ? false
        : $parameters['debug']['dump_path'],
      'dump_all_steps' => empty($parameters['debug']['dump_all_steps'])
        ? false
        : $parameters['debug']['dump_all_steps'],
    );
  }

  /**
   * @Given /^The window is maximized$/
   */
  public function theWindowIsMaximized() {
    $this->getSession()->getDriver()->resizeWindow(1200, 1200, 'current');
  }

  /**
   * @When /^I focus on "([^"]*)" element$/
   */
  public function iFocusOnElement($locator) {
    $field = $this->getSession()->getPage()->findField($locator);
    $field->focus();
  }

  /**
   * @Given /^I should see the "([^"]*)" element$/
   */
  public function iShouldSeeTheElement($selector) {
    $element = $this->getSession()->getPage()->find('css', $selector);

    if (!$element) {
      throw new \Exception("{$selector} was not found.");
    }
  }

  /**
   * @Then /^I should not see the "([^"]*)" element$/
   */
  public function iShouldNotSeeTheElement($selector) {
    $element = $this->getSession()->getPage()->find('css', $selector);

    if ($element) {
      throw new \Exception("{$selector} was found, but it should not.");
    }
  }

  /**
   * @Then /^I click the "([^"]*)" element$/
   */
  public function iClickOn($selector) {
    $page = $this->getSession()->getPage();
    $element = $page->find('css', $selector);

    if (!$element) {
      throw new Exception("$selector could not be found");
    }

    $element->click();
  }
}
