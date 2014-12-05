<?php
/**
 * Behat context file to support the test scenario's.
 */

use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Guzzle\Service\Client;
use Behat\Behat\Context\Step;

require 'vendor/autoload.php';


// Split FeatureContext in smaller chunks.
require __DIR__ . '/FeatureContext/Activity.php';
require __DIR__ . '/FeatureContext/Debug.php';
require __DIR__ . '/FeatureContext/Discussion.php';
require __DIR__ . '/FeatureContext/Document.php';
require __DIR__ . '/FeatureContext/Field.php';
require __DIR__ . '/FeatureContext/File.php';
require __DIR__ . '/FeatureContext/Group.php';
require __DIR__ . '/FeatureContext/GroupDashboard.php';
require __DIR__ . '/FeatureContext/Highlights.php';
require __DIR__ . '/FeatureContext/Node.php';
require __DIR__ . '/FeatureContext/NodeJs.php';
require __DIR__ . '/FeatureContext/Overview.php';
require __DIR__ . '/FeatureContext/PageAccess.php';
require __DIR__ . '/FeatureContext/QuickPost.php';
require __DIR__ . '/FeatureContext/Search.php';
require __DIR__ . '/FeatureContext/User.php';
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
class FeatureContext extends Drupal\DrupalExtension\Context\DrupalContext {

  /**
   * Split context file in smaller parts to make merging easier.
   */
  use FeatureContext_Activity;
  use FeatureContext_Debug;
  use FeatureContext_Discussion;
  use FeatureContext_Document;
  use FeatureContext_Field;
  use FeatureContext_File;
  use FeatureContext_Group;
  use FeatureContext_GroupDashboard;
  use FeatureContext_Highlights;
  use FeatureContext_Node;
  use FeatureContext_NodeJs;
  use FeatureContext_Overview;
  use FeatureContext_PageAccess;
  use FeatureContext_QuickPost;
  use FeatureContext_Search;
  use FeatureContext_User;
  use FeatureContext_Wait;

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
  }
}
