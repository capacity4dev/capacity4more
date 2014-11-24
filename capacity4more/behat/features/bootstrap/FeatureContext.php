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
   * @Then /^I should print page$/
   */
  public function iShouldPrintPage() {
    $element = $this->getSession()->getPage();
    print_r($element->getContent());
  }

  /**
   * @Then /^I should print page to "([^"]*)"$/
   */
  public function iShouldPrintPageTo($file) {
    $element = $this->getSession()->getPage();
    file_put_contents($file, $element->getContent());
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
    return new Given("I go to \"node/$nid\"");
  }

  /**
   * @Given /^a moderated group "([^"]*)" with "([^"]*)" organization restriction is created with group manager "([^"]*)"$/
   */
  public function aModeratedGroupWithOrganizationRestrictionIsCreatedWithGroupManager($title, $organization, $username) {
    return $this->aGroupWithAccessIsCreatedWithGroupManager($title, 'Restricted', $username, NULL, TRUE, array($organization));
  }

  /**
   * @Given /^a moderated group "([^"]*)" with "([^"]*)" restriction is created with group manager "([^"]*)"$/
   */
  public function aModeratedGroupWithRestrictionIsCreatedWithGroupManager($title, $domains, $username) {
    return $this->aGroupWithAccessIsCreatedWithGroupManager($title, 'Restricted', $username, $domains, TRUE);
  }

  /**
   * @Given /^I fill editor "([^"]*)" with "([^"]*)"$/
   */
  public function iFillEditorWith($editor, $value) {
    // Using javascript script to fill the textAngular editor,
    // We have to enter the value directly to the scope.
    $javascript = "angular.element('textarea#" . $editor . "').scope().data." . $editor . " = '" . $value . "';";
    $this->getSession()->executeScript($javascript);
  }

  /**
   * @Given /^I fill label with "([^"]*)" in "([^"]*)"$/
   */
  public function iFillLabelWith($value, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I press the "discussions" button');
    $steps[] = new Step\When('I fill in "label" with "' . $value . '"');

    return $steps;
  }

  /**
   * @Given /^a group "([^"]*)" with "([^"]*)" access is created with group manager "([^"]*)"$/
   */
  public function aGroupWithAccessIsCreatedWithGroupManager($title, $access, $username, $domains = NULL, $moderated = FALSE, $organizations = array()) {
    // Generate URL from title.
    $url = strtolower(str_replace(' ', '-', trim($title)));

    $steps = array();
    $steps[] = new Step\When('I am logged in as user "'. $username .'"');
    $steps[] = new Step\When('I visit "node/add/group"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-summary" with "This is default summary."');
    $steps[] = new Step\When('I fill in "edit-purl-value" with "' . $url .'"');
    $steps[] = new Step\When('I select the radio button "' . $access . '"');
    if ($access == 'Restricted') {
      if ($domains) {
        $steps[] = new Step\When('I fill in "edit-restricted-by-domain" with "' . $domains .'"');
      }
      if ($organizations) {
        foreach ($organizations as $organization) {
          $steps[] = new Step\When('I check the box "' . $organization . '"');
        }
      }
    }
    if ($moderated) {
      $steps[] = new Step\When('I select the radio button "Moderated - Any member of capacity4dev who has access to this Group can request membership. The Group owner or one of the Group administrators needs to approve the request."');
    }

    // This is a required tag.
    $steps[] = new Step\When('I check the box "Fire"');
    $steps[] = new Step\When('I press "Save"');

    // Check there was no error.
    $steps[] = new Step\When('I should not see "There was an error"');
    return $steps;
  }

  /**
   * @Given /^a discussion "([^"]*)" in group "([^"]*)" is created$/
   */
  public function aDiscussionInGroupIsCreated($title, $group_title) {
    $steps = array();
    $steps[] = new Step\When('I visit "node/add/discussion"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-value" with "This is default discussion."');
    $steps[] = new Step\When('I select "' . $group_title . '" from "edit-og-group-ref-und-0-default"');
    $steps[] = new Step\When('I press "Save"');

    // Check there was no error.
    $steps[] = new Step\When('I should not see "There was an error"');

    return $steps;
  }

  /**
   * @When /^I create a discussion quick post with title "([^"]*)" and body "([^"]*)" in "([^"]*)"$/
   */
  public function iCreateDiscussionQuickPost($title, $body, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I press the "discussions" button');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I fill editor "body" with "' . $body . '"');
    $steps[] = new Step\When('I press the "quick-submit" button');
    $steps[] = new Step\When('I wait');
    // Check that the form has collapsed.
    $steps[] = new Step\When('I should not see "Type of Discussion" in the "div#quick-post-fields" element');

    return $steps;
  }

  /**
   * @Given /^I should not have access to the page$/
   */
  public function iShouldNotHaveAccessToThePage() {
    $steps = array();
    $steps[] = new Step\When('I should get a "403" HTTP response');

    return $steps;
  }

  /**
   * @Given /^I should have access to the page$/
   */
  public function iShouldHaveAccessToThePage() {
    $steps = array();
    $steps[] = new Step\When('I should get a "200" HTTP response');

    return $steps;
  }

  /**
   * @When /^I create an event quick post with title "([^"]*)" and body "([^"]*)" that starts at "([^"]*)" and ends at "([^"]*)" in "([^"]*)"$/
   */
  public function iCreateEventQuickPost($title, $body, $start_date, $end_date, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');
    $steps[] = new Step\When('I press the "events" button');
    $steps[] = new Step\When('I press the "Meeting" button');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I fill editor "body" with "' . $body . '"');
    $steps[] = new Step\When('I fill in "startDate" with "' . $start_date . '"');
    $steps[] = new Step\When('I fill in "endDate" with "' . $end_date . '"');
    $steps[] = new Step\When('I press the "quick-submit" button');
    $steps[] = new Step\When('I wait');
    // Check that the form has collapsed.
    $steps[] = new Step\When('I should not see "Type of Event" in the "div#quick-post-fields" element');

    return $steps;
  }

  /**
   * @Given /^a "([^"]*)" is created with title "([^"]*)" and body "([^"]*)" in the group "([^"]*)"$/
   */
  public function aDiscussionIsCreatedWithTitleAndBodyInTheGroup($type,  $title, $body, $group) {

    $steps = array();
    $steps[] = new Step\When('I visit "node/add/' . $type . '"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-value" with "' . $body . '"');
    $steps[] = new Step\When('I select "' . $group . '" from "edit-og-group-ref-und-0-default"');
    $steps[] = new Step\When('I press "Save"');
    return $steps;
  }

  /**
   * @Given /^I update a "([^"]*)" with title "([^"]*)" with new title "([^"]*)"$/
   */
  public function iUpdateAWithTitleInTheGroupWithNewTitle($type, $title, $new_title) {
    $steps = array();

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

    $steps[] = new Step\When('I visit "node/' .  $nid . '/edit"');
    $steps[] = new Step\When('I fill in "title" with "' . $new_title . '"');
    $steps[] = new Step\When('I press "Save"');
    return $steps;
  }

  /**
   * @Given /^I update a "([^"]*)" with title "([^"]*)" with new title "([^"]*)" after "([^"]*)"$/
   */
  public function iUpdateAWithTitleInTheGroupWithNewTitleAfter($type, $title, $new_title, $time) {
    // Loading node of current content type and with current title.
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

    // Loading the previous message for the current node.
    $query = new EntityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'message')
      ->propertyCondition('type', 'c4m_insert__node__' . $type)
      ->fieldCondition('field_node', 'target_id', $nid)
      ->propertyOrderBy('timestamp', 'desc')
      ->range(0, 1)
      ->execute();

    if (empty($result['message'])) {
      throw new Exception(format_string("Previous message not found."));
    }

    $id = key($result['message']);
    $message = message_load($id);
    // Changing timestamp of the previous message to earlier (minus current time).
    $message->timestamp = strtotime('now - ' . $time);
    $message->save();

    $node = node_load($nid);
    // Changing the current node title.
    $node->title = $new_title;
    node_save($node);
  }

  /**
   * @Then /^I should see "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeInTheActivityStreamOfTheGroup($text, $group) {
    // Generate URL from title.
    $url = str_replace(' ', '-', strtolower(trim($group)));

    $steps = array();
    $steps[] = new Step\When('I visit "group/' . $url . '"');

    $steps[] = new Step\When('I should see "' . $text . '" in the "div.view-group-activity-stream" element');

    return $steps;
  }

  /**
   * @Then /^I should not be allowed to create a "([^"]*)"$/
   */
  public function iShouldNotBeAllowedToCreateA($type) {

    return array(
      new Step\When('I go to "node/add/'.$type.'"'),
      new Step\Then('the response status code should be 403'),
    );
  }

  /**
   * @Then /^I should be allowed to create a "([^"]*)"$/
   */
  public function iShouldBeAllowedToCreateA($type) {

    return array(
      new Step\When('I go to "node/add/'.$type.'"'),
      new Step\Then('the response status code should be 200'),
    );
  }

  /**
   * @Given /^I should see an updated message for "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeAnUpdatedMessageForInTheActivityStreamOfTheGroup($title, $group) {
    // Generate URL from title.
    $url = str_replace(' ', '-', strtolower(trim($group)));

    $steps = array();

    $steps[] = new Step\When('I visit "group/' . $url . '"');
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.view-group-activity-stream" element');
    $steps[] = new Step\When('I should not see "posted Information" in the "div.view-group-activity-stream" element');
    $steps[] = new Step\When('I should see "updated the Information" in the "div.view-group-activity-stream" element');

    return $steps;
  }

  /**
   * @Given /^I should see a new message for "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeANewMessageForInTheActivityStreamOfTheGroup($title, $group) {
    // Generate URL from title.
    $url = str_replace(' ', '-', strtolower(trim($group)));

    $steps = array();

    $steps[] = new Step\When('I visit "group/' . $url . '"');
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.view-group-activity-stream" element');
    $steps[] = new Step\When('I should see "posted Information" in the "div.view-group-activity-stream" element');
    $steps[] = new Step\When('I should see "updated the Information" in the "div.view-group-activity-stream" element');

    return $steps;
  }

  /**
   * @When /^I visit the dashboard of group "([^"]*)"$/
   */
  public function iVisitTheDashboardOfGroup($title) {
    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'group')
      ->propertyCondition('title', $title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
      );
      throw new Exception(format_string("Group @title not found.", $params));
    }

    $gid = (int) key($result['node']);
    $purl = array(
      'provider' => "og_purl|node",
      'id' => $gid,
    );
    $url = ltrim(url('<front>', array('purl' => $purl, 'absolute' => TRUE)));

    return new Given("I go to \"$url\"");
  }

  /**
   * @Then /^I should see the group dashboard$/
   */
  public function iShouldSeeTheGroupDashboard() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('Group menu item "Home" should be active');
    $steps[] = new Step\When('I should see the Quick Post form');
    $steps[] = new Step\When('I should see the Activity stream');

    return $steps;
  }

  /**
   * @Given /^Group menu item "([^"]*)" should be active$/
   */
  public function groupMenuItemShouldBeActive($label) {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', '#block-menu-menu-group-menu a.active');
    if ($el === null) {
      throw new Exception('The group menu has no active items.');
    }

    if ($el->getText() !== $label) {
      $params = array('@label' => $label);
      throw new Exception(format_string('Active menu item is not "@label".', $params));
    }
  }

  /**
   * @Given /^I should see the Quick Post form$/
   */
  public function iShouldSeeTheQuickPostForm() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-quick-form');
    if ($el === null) {
      throw new Exception('The Quick Post pane is not visible.');
    }
  }

  /**
   * @Given /^I should see the Activity stream$/
   */
  public function iShouldSeeTheActivityStream() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-activity-stream');
    if ($el === null) {
      throw new Exception('The Activity Stream pane is not visible.');
    }
  }
}
