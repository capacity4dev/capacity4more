<?php

use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Guzzle\Service\Client;
use Behat\Behat\Context\Step;

require 'vendor/autoload.php';

class FeatureContext extends Drupal\DrupalExtension\Context\DrupalContext {

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

  /**
   * Authenticates a user with password from configuration.
   *
   * @Given /^I am logged in as user "([^"]*)"$/
   */
  public function iAmLoggedInAsUser($username) {
    $this->user = new stdClass();
    $this->user->name = $username;
    $this->user->pass = $this->drupal_users[$username];
    $this->login();
  }
  
  /**
   * @Given /^I wait$/
   */
  public function iWait() {
    sleep(10);
  }

  /**
   * @When /^I visit "([^"]*)" node of type "([^"]*)"$/
   */
  public function iVisitNodePageOfType($title, $type) {
    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', strtolower($type))
      ->propertyCondition('title', $title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new Exception(format_string("Node @title of @type not found.", $params));
    }

    $nid = key($result['node']);
    // Use Drupal Context 'I am at'.
    return new Given("I am at \"node/$nid\"");
  }

  /**
   * @Given /^I fill editor "([^"]*)" with "([^"]*)"$/
   */
  public function iFillEditorWith($editor, $value)
  {
    $javascript = "angular.element('text-angular#" . $editor . "').scope().data." . $editor . " = '" . $value . "';";
    $this->getSession()->executeScript($javascript);
  }
}
