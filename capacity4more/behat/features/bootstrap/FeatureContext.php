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
    $url = strtolower(str_replace(' ', '_', trim($title)));

    $steps = array();
    $steps[] = new Step\When('I am logged in as user "'. $username .'"');
    $steps[] = new Step\When('I visit "node/add/group"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-value" with "This is default summary."');
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
    $steps[] = new Step\When('I press "Request"');

    // Check there was no error.
    $steps[] = new Step\When('I should not see "Group access"');
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
    $steps[] = new Step\When('I press the "idea" button');
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
   * @Given /^a "([^"]*)" is created with title "([^"]*)" and body "([^"]*)" in the group "([^"]*)" with group manager "([^"]*)"$/
   */
  public function aDiscussionIsCreatedWithTitleAndBodyInTheGroup($type, $title, $body, $group, $user) {
    $steps = array();
    $steps[] = new Step\When('I am logged in as user "' . $user . '"');
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
   * @Then /^I should see "([^"]*)" in the activity stream of the group "([^"]*)" when i am logged in as "([^"]*)"$/
   */
  public function iShouldSeeInTheActivityStreamOfTheGroup($text, $group, $user) {
    $steps = array();
    $steps[] = new Step\When('I am logged in as user "' . $user . '"');
    $steps[] = new Step\When("I visit the dashboard of group \"$group\"");
    $steps[] = new Step\When('I should see "' . $text . '" in the "div.pane-activity-stream" element');

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
    $steps = array();
    $steps[] = new Step\When("I visit the dashboard of group \"$group\"");
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should not see "posted Information" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "updated the Information" in the "div.pane-activity-stream" element');

    return $steps;
  }

  /**
   * @Given /^I should see a new message for "([^"]*)" in the activity stream of the group "([^"]*)"$/
   */
  public function iShouldSeeANewMessageForInTheActivityStreamOfTheGroup($title, $group) {
    $steps = array();
    $steps[] = new Step\When("I visit the dashboard of group \"$group\"");
    $steps[] = new Step\When('I should see "' . $title . '" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "posted Information" in the "div.pane-activity-stream" element');
    $steps[] = new Step\When('I should see "updated the Information" in the "div.pane-activity-stream" element');

    return $steps;
  }

  /**
   * @When /^I visit the dashboard of group "([^"]*)"$/
   */
  public function iVisitTheDashboardOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, '<front>');

    return new Given("I go to \"$uri\"");
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
    $el = $page->find('css', '#block-menu-c4m-og-menu a.active');
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

  /**
   * @When /^I start creating "([^"]*)" in full form with title "([^"]*)" in group "([^"]*)"$/
   */
  public function iStartCreatingInFullFormWithTitle($bundle, $title, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit the dashboard of group "' . $group . '"');

    $uri = strtolower(str_replace(' ', '-', trim($group)));

    $steps[] = new Step\When('I visit "' . $uri . '/node/js-add/' . $bundle . '"');
    $steps[] = new Step\When('I fill in "label" with "' . $title . '"');
    $steps[] = new Step\When('I fill editor "body" with "Some text in the body"');
    return $steps;
  }

  /**
   * @When /^I visit the discussions overview of group "([^"]*)"$/
   */
  public function iVisitTheDiscussionsOverviewOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'discussions');
    return new Given('I go to "' . $uri . '"');
  }

  /**
   * @Then /^I should see the discussions overview$/
   */
  public function iShouldSeeTheDiscussionsOverview() {
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
    $steps[] = new Step\When('I should see a "Author" field on an item in the overview');

    return $steps;
  }

  private function waitForXpathNode($xpath, $appear) {
    $this->waitFor(function($context) use ($xpath, $appear) {
      try {
        $nodes = $context->getSession()->getDriver()->find($xpath);
        if (count($nodes) > 0) {
          $visible = $nodes[0]->isVisible();
          return $appear ? $visible : !$visible;
        } else {
          return !$appear;
        }
      } catch (WebDriver\Exception $e) {
        if ($e->getCode() == WebDriver\Exception::NO_SUCH_ELEMENT) {
          return !$appear;
        }
        throw $e;
      }
    });
  }

  /**
   * @Given /^I wait for text "([^"]+)" to (appear|disappear) in "([^"]+)"$/
   */
  public function iWaitForText($text, $appear, $element_name) {
    $this->waitForXpathNode(".//*[contains(@name, \"$element_name\")]//*[contains(normalize-space(string(text())), \"$text\")]", $appear == 'appear');
  }

  private function waitFor($fn, $timeout = 30000) {
    $start = microtime(true);
    $end = $start + $timeout / 1000.0;
    while (microtime(true) < $end) {
      if ($fn($this)) {
        return;
      }
    }
    throw new \Exception("waitFor timed out");
  }

  /**
   * @Given /^I upload the file "([^"]*)"$/
   */
  public function iUploadTheFile($file) {
    $file_path = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR.$file;

    $fileInputXpath = './/div[contains(@name, "discussion-document-upload")]/input[contains(@type, "file")]';

    $fields = $this->getSession()->getDriver()->find($fileInputXpath);
    $field = count($fields) > 0 ? $fields[0] : NULL;
    if (null === $field) {
      throw new Exception("File input is not found");
    }
    $this->getSession()->resizeWindow(1440, 900, 'current');

    // Attaching file is working only if input is visible.
    $this->getSession()->getDriver()->evaluateScript(
      "jQuery('#document_file').css('display', 'block');"
    );
    $field->attachFile($file_path);
    // Make input hidden after attaching the file.
    $this->getSession()->getDriver()->evaluateScript(
      "jQuery('#document_file').css('display', 'none');"
    );
  }

  /**
   * @Given /^I save document with title "([^"]*)" for a discussion$/
   */
  public function iSaveDocumentWithTitleForADiscussion($title) {
    $label_xpath = ".//*[contains(@name, \"documentForm\")]//input[contains(@name, \"label\")]";
    $save_xpath = ".//*[contains(@name, \"documentForm\")]//button[contains(@id, \"quick-submit\")]";

    $fields = $this->getSession()->getDriver()->find($label_xpath);
    $fields[0]->setValue($title);

    $javascript = "angular.element('form[name=\"documentForm\"]').find('textarea#body').scope().data.body = 'Some document text';";
    $this->getSession()->executeScript($javascript);

    $fields = $this->getSession()->getDriver()->find($save_xpath);
    $fields[0]->press();
  }


  /**
   * @Given /^I upload the file "([^"]*)" in the field "([^"]*)"$/
   */
  public function iUploadTheFileInTheField($file, $fieldname) {
    // Attaching file is working only if input is visible.
    $file_path = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR.$file;

    $fileInputXpath = './/div[contains(@name, "' . $fieldname . '")]/input[contains(@type, "file")]';

    $fields = $this->getSession()->getDriver()->find($fileInputXpath);
    $field = count($fields) > 0 ? $fields[0] : NULL;
    if (null === $field) {
        throw new Exception("File input is not found");
    }
    $field->attachFile($file_path);
  }

  /**
   * @Then /^I should not see the "([^"]*)" link above the overview$/
   */
  public function iShouldNotSeeTheLinkAboveTheOverview($label) {
    $page = $this->getSession()->getPage();
    $links = $page->findAll('css', '.region-content .view-header .node-create');
    foreach ($links as $link) {
      if ($link->getText() !== $label) {
        continue;
      }

      $params = array(
        '@label' => $label,
      );
      throw new Exception(format_string("Link @label should NOT be above the overview.", $params));
    }
  }

  /**
   * @Then /^I should see the "([^"]*)" link above the overview$/
   */
  public function iShouldSeeTheLinkAboveTheOverview($label) {
    $page = $this->getSession()->getPage();
    $links = $page->findAll('css', '.region-content .view-header .node-create');

    $found = false;
    foreach ($links as $link) {
      if ($link->getText() !== $label) {
        continue;
      }

      $found = TRUE;
      break;
    }

    if (!$found) {
      $params = array(
        '@label' => $label,
      );
      throw new Exception(format_string("Link @label is not found above the overview.", $params));
    }
  }

  /**
   * @Then /^I should be able to sort the overview$/
   */
  public function iShouldBeAbleToSortTheOverview() {
    $page = $this->getSession()->getPage();
    $sorts = $page->findAll('css', '.region-content .view-header .search-api-sorts li');

    if (!count($sorts)) {
      throw new Exception("No sort options found.");
    }
  }

  /**
   * @Then /^I should see the sidebar search$/
   */
  public function iShouldSeeTheSidebarSearch() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', '.region-sidebar-first #edit-search-api-views-fulltext');
    if ($el === null) {
      throw new Exception('The Sidebar Search block is not visible.');
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
      throw new Exception(format_string("Facet with @title not found.", $params));
    }
  }

  /**
   * Helper to get the group based on the title & type.
   *
   * @param string $title
   *   The group title.
   * @param string $type
   *   The group node type.
   *
   * @return stdClass
   *   The group (if any) or NULL.
   *
   * @throws Exception
   */
  private function loadGroupByTitleAndType($title, $type) {
    $query = new entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $type)
      ->propertyCondition('title', $title)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new Exception(format_string("Group @title not found (type @type).", $params));
    }

    $gid = (int) key($result['node']);
    $group = node_load($gid);
    if (!$group) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new Exception(format_string("Group @title not found (type @type).", $params));
    }

    return $group;
  }

  /**
   * Helper to create a uri within a group context.
   *
   * @param stdClass $group
   *   The group context.
   * @param string $path
   *   The path part.
   * @param array $options
   *   Options to pass to url.
   *
   * @return string
   */
  protected function createUriWithGroupContext($group, $path = '<front>', $options = array()) {
    $purl = array(
      'provider' => "og_purl|node",
      'id' => $group->nid,
    );
    $options = array_merge($options, array('purl' => $purl));
    $uri = ltrim(url($path, $options), '/');

    return $uri;
  }

  /**
   * @AfterStep
   *
   * Take a screenshot after failed steps.
   */
  public function takeScreenshotAfterFailedStep($event) {
    if ($event->getResult() != 4) {
      // Step didn't fail.
      return;
    }
    if (!($this->getSession()->getDriver() instanceof \Behat\Mink\Driver\Selenium2Driver)) {
      // Not a Selenium driver (e.g. PhantomJs).
      return;
    }

    $file_name = rtrim(realpath($this->getMinkParameter('files_path')), DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR . 'behat-failed-step.png';
    $screenshot = $this->getSession()->getDriver()->getScreenshot();
    file_put_contents($file_name, $screenshot);
    print "Screenshot for failed step created in $file_name";
  }

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
   * @Given /^I should be able to see the "([^"]*)" icon$/
   */
  public function iShouldBeAbleToSeeTheIcon($icon_type) {
    $page = $this->getSession()->getPage();
    $icon = $page->findAll('css', '.region-content .view-header .' .
      $icon_type . '-teaser-view');

    if (!count($icon)) {
      throw new Exception("No $icon_type overview icon found.");
    }
  }

  /**
   * @Given /^I should see a "([^"]*)" field on an item in the overview$/
   */
  public function iShouldSeeAFieldOnAnItemInTheOverview($field) {
    $page = $this->getSession()->getPage();
    switch($field) {
      case 'Author':
        $class = 'username';
        break;
    }
    $element = $page->findAll('css', '.region-content .view-content .' . $class);

    if (!count($element)) {
      throw new Exception("No $field found in the overview.");
    }
  }

  /**
   * @When /^I visit the group "([^"]*)" detail page "([^"]*)"$/
   */
  public function iVisitTheGroupDetailPage($type, $title) {
    return $this->iVisitNodePageOfType($title, $type);
  }

  /**
   * @Then /^I should see the discussion detail page$/
   */
  public function iShouldSeeTheDiscussionDetailPage() {
    $steps = array();

    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a "Comment" field');
    $steps[] = new Step\When('I should see a "Title" field');
    $steps[] = new Step\When('I should see a "Details" field group');

    return $steps;
  }

  /**
   * @Given /^I should see a "([^"]*)" field$/
   */
  public function iShouldSeeAField($field) {
    $element = NULL;
    $page = $this->getSession()->getPage();

    switch($field) {
      case 'Author':
        $class = 'username';
        break;
      case 'Comment':
        $class = 'comment-wrapper';
        break;
      case 'Title':
        $class = 'field-name-title';
        break;
    }

    if (!empty($class)) {
      $element = $page->findAll('css', '.region-content .' . $class);
    }

    if (!count($element)) {
      throw new Exception("No $field field found.");
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
    }
    if (!empty($class)) {
      $element = $page->findAll('css', '.region-content .' . $class);
    }

    if (!count($element)) {
      throw new Exception("No $fieldgroup field group found.");
    }
  }
}

