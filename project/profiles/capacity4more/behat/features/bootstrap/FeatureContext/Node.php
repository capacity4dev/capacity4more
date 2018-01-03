<?php
/**
 * @file
 * Context methods about Nodes (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


/**
 * DO NOT USE THIS TRAIT FOR FUNCTIONALITY ABOUT QUICK POST.
 */
trait Node {

  /**
   * @When /^I visit "([^"]*)" node page of type "([^"]*)" with status "([^"]*)"$/
   */
  public function iVisitNodePageOfTypeWithStatus($title, $type, $status) {
    $query = new \entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', strtolower($type))
      ->propertyCondition('title', $title)
      ->propertyCondition('status', $status)
      ->range(0, 1)
      ->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
        '@status' => $status,
      );
      throw new \Exception(format_string("@status node @title of @type with not found.", $params));
    }

    $nid = key($result['node']);
    // Use Drupal Context 'I am at'.
    return new Given("I go to \"node/$nid\"");
  }

  /**
   * @When /^I visit "([^"]*)" node of type "([^"]*)"$/
   */
  public function iVisitNodePageOfType($title, $type) {
    return $this->iVisitNodePageOfTypeWithStatus($title, $type, NODE_PUBLISHED);
  }

  /**
   * @When /^I start editing "([^"]*)" node$/
   */
  public function iStartEditingNode($title) {
    $q = new \entityFieldQuery();
    $q->entityCondition('entity_type', 'node');
    $q->propertyCondition('title', $title);
    $q->range(0, 1);

    $result = $q->execute();

    if (empty($result['node'])) {
      $params = array(
        '@title' => $title,
      );
      throw new \Exception(format_string("Node with title '@title' not found.", $params));
    }

    $nid = key($result['node']);

    return new Given("I go to \"node/$nid/edit\"");
  }

  /**
   * @Then /^I should not be allowed to create a "([^"]*)"$/
   */
  public function iShouldNotBeAllowedToCreateA($type) {

    return array(
      new Step\When('I go to "node/add/'.$type.'"'),
      new Step\Then('I should see "Access denied"'),
    );
  }

  /**
   * @Then /^I should be allowed to create a "([^"]*)" in group "([^"]*)"$/
   */
  public function iShouldBeAllowedToCreateA($type, $group) {

    return array(
      new Step\When('I go to "' . $this->humanToMachineReadable($group, '-') . '/node/add/'.$type.'"'),
      new Step\Then('I should not see "Access denied"'),
    );
  }

  /**
   * @Given /^a "([^"]*)" is created with title "([^"]*)" in the group "([^"]*)"$/
   */
  public function aNodeIsCreatedWithTitleInTheGroup($type, $title, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit "node/add/' . $type . '"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in ckeditor field "edit-c4m-body-und-0-value" with "Some text"');
    $steps[] = new Step\When('I select "' . $group . '" from "edit-og-group-ref-und-0-default"');
    $steps[] = new Step\When('I press "Publish"');
    $steps[] = new Step\When('I should see "has been created."');
    return $steps;
  }

  /**
   * @Given /^a "([^"]*)" is created with title "([^"]*)" and topic "([^"]*)" in the group "([^"]*)"$/
   */
  public function aNodeIsCreatedWithTitleAndTopicInTheGroup($type, $title, $topic, $group) {
    $steps = array();
    $steps[] = new Step\When('I visit "' . $this->humanToMachineReadable($group, '-') . '/node/add/' . $type . '"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in ckeditor field "edit-c4m-body-und-0-value" with "Some text"');
    $steps[] = new Step\When('I check the related topic checkbox with "' . $topic . '"');
    $steps[] = new Step\When('I press "Publish"');
    $steps[] = new Step\When('I should see "has been created."');
    return $steps;
  }

  /**
   * @Given /^I update a "([^"]*)" with title "([^"]*)" with new title "([^"]*)" in group "([^"]*)"$/
   */
  public function iUpdateAWithTitleInTheGroupWithNewTitle($type, $title, $new_title, $group) {
    $steps = array();

    $query = new \entityFieldQuery();
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
      throw new \Exception(format_string("Node @title of @type not found.", $params));
    }

    $nid = key($result['node']);

    $steps[] = new Step\When('I visit "' . $this->humanToMachineReadable($group, '-') . '/node/' .  $nid . '/edit"');
    $steps[] = new Step\When('I fill in "title" with "' . $new_title . '"');
    $steps[] = new Step\When('I check the box "edit-post-activity"');
    $steps[] = new Step\When('I press "Save"');
    return $steps;
  }

  /**
   * @Given /^I update a "([^"]*)" with title "([^"]*)" with new title "([^"]*)" "([^"]*)" times$/
   */
  public function iUpdateAWithTitleInTheGroupWithNewTitleTimes($type, $title, $new_title, $times) {
    $steps = array();

    $query = new \entityFieldQuery();
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
      throw new \Exception(format_string("Node @title of @type not found.", $params));
    }

    $nid = key($result['node']);

    for ($i = 1; $i <= $times; $i++) {
      $steps[] = new Step\When('I visit "node/' .  $nid . '/edit"');

      if ($i == $times) {
        $steps[] = new Step\When('I fill in "title" with "' . $new_title . '"');
      }
      else {
        $steps[] = new Step\When('I fill in "title" with "Some new title' . $i . '"');
      }

      $steps[] = new Step\When('I check the box "edit-post-activity"');
      $steps[] = new Step\When('I press "Save"');
    }
    return $steps;
  }

  /**
   * @Given /^I update a "([^"]*)" with title "([^"]*)" with new title "([^"]*)" after "([^"]*)"$/
   */
  public function iUpdateAWithTitleInTheGroupWithNewTitleAfter($type, $title, $new_title, $time) {
    // Loading node of current content type and with current title.
    $query = new \entityFieldQuery();
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
      throw new \Exception(format_string("Node @title of @type not found.", $params));
    }

    $nid = key($result['node']);

    // Loading the previous message for the current node.
    $query = new \EntityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', 'message')
      ->propertyCondition('type', 'c4m_insert__node__' . $type)
      ->fieldCondition('field_node', 'target_id', $nid)
      ->propertyOrderBy('timestamp', 'desc')
      ->range(0, 1)
      ->execute();

    if (empty($result['message'])) {
      throw new \Exception(format_string("Previous message not found."));
    }

    $id = key($result['message']);
    $message = message_load($id);
    // Changing timestamp of the previous message to earlier (minus current time).
    $message->timestamp = strtotime('now - ' . $time);
    $message->save();

    $node = node_load($nid);
    // Changing the current node title.
    $node->title = $new_title;

    // Adding a revision to create a new message on the activity stream.
    $node->revision = TRUE;
    node_save($node);
  }

  /**
   * Convert a human readable title to a machine readable name.
   *
   * The function replaces anything other than letters, numbers and underscores
   * in the $title string with the $delimiter and converts capital to lowercase.
   *
   * @return string
   */
  public function humanToMachineReadable($title, $delimiter) {
    return preg_replace('@[^a-z0-9_]+@', $delimiter, strtolower(trim($title)));
  }

  /**
   * @Then /^I should not be able to see the edit link$/
   */
  public function iShouldNotBeAbleToSeeTheEditLink() {
    try {
      $this->assertLinkRegion('Edit', 'primary tabs');
    }
    catch (\Exception $e) {
      // The edit link was not found on the page.
      return;
    }

    throw new \Exception('The edit link was found on this page.');
  }

  /**
   * @Given /^I should validate the (body) field format of "([^"]*)" (discussion) (node) is "([^"]*)"$/
   */
  public function iValidateEntityFieldFormat($field, $title, $bundle, $type, $format) {
    $query = new \entityFieldQuery();
    $result = $query
      ->entityCondition('entity_type', $type)
      ->entityCondition('bundle', $bundle)
      ->propertyCondition('title', $title)
      ->range(0, 1)
      ->execute();

    if (empty($result[$type])) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
        '@bundle' => $bundle,
      );
      throw new \Exception(format_string("@title @bundle of @type with not found.", $params));
    }

    $id = key($result[$type]);
    $wrapper = entity_metadata_wrapper($type, $id);

    $actual_format = $wrapper->{"c4m_$field"}->format->value();
    if ($actual_format != $format) {
      $params = array(
        '@title' => $title,
        '@field' => $field,
        '@format' => $format,
        '@actual_format' => $actual_format,
      );
      throw new \Exception(format_string("'@title' @field field format should be '@format' but actual format is '@actual_format'.", $params));
    }
  }

}
