<?php
/**
 * @file
 * Context methods about Groups (view, create, update, delete).
 */

namespace FeatureContext;

use Behat\Behat\Context\Step\Given;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Context\Step;


trait Group {
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
    $query = new \entityFieldQuery();
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
      throw new \Exception(format_string("Group @title not found (type @type).", $params));
    }

    $gid = (int) key($result['node']);
    $group = node_load($gid);
    if (!$group) {
      $params = array(
        '@title' => $title,
        '@type' => $type,
      );
      throw new \Exception(format_string("Group @title not found (type @type).", $params));
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
   * @When /^I visit the group "([^"]*)" detail page "([^"]*)"$/
   */
  public function iVisitTheGroupDetailPage($type, $title) {
    return $this->iVisitNodePageOfType($title, $type);
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
   * @Given /^a group "([^"]*)" with "([^"]*)" access is created with group manager "([^"]*)"$/
   */
  public function aGroupWithAccessIsCreatedWithGroupManager($title, $access, $username, $domains = NULL, $moderated = FALSE, $organizations = array()) {
    // Generate URL from title.
    $url = strtolower(str_replace(' ', '_', trim($title)));

    $steps = array();
    $steps[] = new Step\When('I am logged in as user "'. $username .'"');
    $steps[] = new Step\When('I visit "node/add/group"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
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

    $steps[] = new Step\When('I fill in "edit-c4m-body-und-0-value" with "This is default summary."');

    // This is a required tag.
    $steps[] = new Step\When('I check the box "Fire"');
    $steps[] = new Step\When('I press "Request"');

    // Giving time for saving.
    $steps[] = new Step\When('I wait');

    // Check there was no error.
    $steps[] = new Step\When('I should not see "Group access"');
    $steps[] = new Step\When('I should not see "There was an error"');
    return $steps;
  }

  /**
   * @When /^I change access of group "([^"]*)" to "([^"]*)"$/
   */
  public function iChangeAccessOfGroupTo($title, $access) {
//    throw new PendingException();
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $url = strtolower(str_replace(' ', '_', trim($title)));
    drupal_static_reset();
    $steps = array();
    $steps[] = new Step\When('I visit "node/' . $group->nid . '/edit"');
    $steps[] = new Step\When('I select the radio button "' . $access . '"');
    $steps[] = new Step\When('I press "Save"');
    $steps[] = new Step\When('I wait');
//    $steps[] = new Step\When('I should see "has been updated."');
    return $steps;
  }

}
