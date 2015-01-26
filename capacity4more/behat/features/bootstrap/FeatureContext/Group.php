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
    $steps[] = new Step\When('I check the related topic checkbox');
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
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $steps = array();
    $steps[] = new Step\When('I visit "node/' . $group->nid . '/edit"');
    $steps[] = new Step\When('I select the radio button "' . $access . '"');
    $steps[] = new Step\When('I press "Save"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should not see "Group access"');
    $steps[] = new Step\When('I should not see "There was an error"');
    return $steps;
  }

  /**
   * @Given /^I change access of group "([^"]*)" to Restricted with "([^"]*)" restriction$/
   */
  public function iChangeAccessOfGroupToRestrictedWithRestriction($title, $domain) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $steps = array();
    $steps[] = new Step\When('I visit "node/' . $group->nid . '/edit"');
    $steps[] = new Step\When('I select the radio button "Restricted"');
    $steps[] = new Step\When('I fill in "restricted_by_domain" with "' . $domain . '"');
    $steps[] = new Step\When('I select the radio button "Moderated - Any member of capacity4dev who has access to this Group can request membership. The Group owner or one of the Group administrators needs to approve the request."');
    $steps[] = new Step\When('I press "Save"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should not see "Group access"');
    $steps[] = new Step\When('I should not see "There was an error"');

    return $steps;
  }

  /**
   * @Given /^I check the related topic checkbox$/
   */
  public function iCheckRelatedTopic() {
    $steps = array();
    $steps[] = new Step\When('I press "c4m_related_topic"');
    $steps[] = new Step\When('I check the box "Fire"');

    $javascript = "
      var target = jQuery('input[type=checkbox][title=\"Fire\"]').data('target');
      jQuery('input[type=checkbox][value=' + target + ']').prop(\"checked\", true);
    ";
    $this->getSession()->executeScript($javascript);

    return $steps;
  }

  /**
   * @Given /^I should see the Group Details$/
   */
  public function iShouldSeeTheGroupDetails() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', 'div.pane-c4m-content-group');
    if ($el === null) {
      throw new \Exception('The Group Details pane is not visible.');
    }

    $steps = array();

    $steps[] = new Step\When('I should see a "Description" field');
    $steps[] = new Step\When('I should see a "Group type" field');
    $steps[] = new Step\When('I should see a "Group dashboard details" field group');
    $steps[] = new Step\When('I should see a "Author" field');
    $steps[] = new Step\When('I should see a "Topics" field');
    $steps[] = new Step\When('I should see a "Regions & Countries" field');

    return $steps;
  }

  /**
   * @Given /^I should see the Group Header with banner$/
   */
  public function iShouldSeeTheGroupHeaderWithBanner() {
    $page = $this->getSession()->getPage();
    $el = $page->find('css', '#block-c4m-content-group-header-name-banner');
    if ($el === null) {
      throw new \Exception('The Group Header block is not visible.');
    }

    $steps = array();

    $steps[] = new Step\When('I should see a "Group title" field');
    $steps[] = new Step\When('I should see a "Group banner" field');

    return $steps;
  }

  /**
   * @Then /^I should see the group menu$/
   */
  public function iShouldSeeTheGroupMenu() {
    $steps = array();

    $steps[] = new Step\When('I should have access to the page');
    $steps[] = new Step\When('Group menu item "Home" should be active');
    $steps[] = new Step\When('I should see the "Wiki" link on the group menu');
    $steps[] = new Step\When('I should see the "Award Process" link on the group menu wiki navigation');
    $steps[] = new Step\When('I should not see the "Nominations" link on the group menu wiki navigation');

    return $steps;
  }

  /**
   * @Given /^I should see the "([^"]*)" link on the group menu$/
   */
  public function iShouldSeeTheLinkOnTheGroupMenu($text) {
    $page = $this->getSession()->getPage();
    $locator = '#c4m-og-menu > ul > li > a';
    $links = $page->findAll('css', $locator);
    $found = FALSE;
    foreach ($links as $link) {
      if ($link->getText() === $text) {
        $found = TRUE;
        break;
      }
    }

    if (!$found) {
      throw new \Exception("No $text link found on group menu.");
    }
  }
}
