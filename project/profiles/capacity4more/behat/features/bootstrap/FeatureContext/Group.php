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
    $options = array_merge($options, array('purl' => $purl, 'absolute' => TRUE));
    $uri = ltrim(url($path, $options), '/');

    return $uri;
  }

  /**
   * @When /^I visit the page "([^"]*)" in the group "([^"]*)"$/
   */
  public function iVisitPageInGroup($page, $title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, $page);

    return new Given("I go to \"$uri\"");
  }

  /**
   * @When /^I rename the category "([^"]*)" to "([^"]*)" under the type "([^"]*)"$/
   */
  public function iRenameTheCategoryToUnderTheType($oldCategoryName, $newCategoryName, $categoryType) {
    // Open edit window for the category.
    $page = $this->getSession()->getPage();
    $editLink = $page->find('xpath', '//a[text()="' . $oldCategoryName . '"]/following::a[text()="Edit"][1]');
    if (null === $editLink) {
      throw new \Exception('The edit link for the category ' . $oldCategoryName . ' not found');
    }
    $editLink->click();

    // Change name of the category.
    $termName = $page->find('xpath', '//*[@id="edit-name"]');
    if (null === $termName) {
      throw new \Exception('The "Term name" input not found');
    }
    $termName->setValue($newCategoryName);

    // Click "Save" button.
    $this->pressButton("Save");
  }

  /**
   * @Then /^I should see the category "([^"]*)" under the type "([^"]*)"$/
   */
  public function iShouldSeeTheCategoryUnderTheType($categoryName, $typeName) {
    // Find the category in specific type.
    $page = $this->getSession()->getPage();
    $category = $page->find('xpath', '//h3[text()="' . $typeName . '"]/following::a[text()="' . $categoryName . '"]');
    if (null === $category) {
      throw new \Exception('The category ' . $categoryName . ' not exist in the type ' . $typeName);
    }
  }

  /**
   * @When /^I change the type of category to "([^"]*)" for the category "([^"]*)"$/
   */
  public function iChangeTheTypeOfCategoryToForTheCategory($typeName, $categoryName) {
    // Open edit window for the category.
    $page = $this->getSession()->getPage();
    $editLink = $page->find('xpath', '//a[text()="' . $categoryName . '"]/following::a[text()="Edit"][1]');
    if (null === $editLink) {
      throw new \Exception('The edit link for the category ' . $categoryName . ' not found');
    }
    $editLink->click();

    // Change type of category to new type by change radio button.
    $radioType = $page->find('xpath', '//label[contains(.,"' . $typeName . '")]/input');
    if (null === $radioType) {
      throw new \Exception('The radio button with text ' . $typeName . ' not found');
    }
    $radioType->click();

    // Click "Save" button.
    $this->pressButton("Save");
  }

  /**
   * @Given /^I should see the category type "([^"]*)"$/
   */
  public function iShouldSeeTheCategoryType($categoryType) {
    return $this->assertPageContainsText($categoryType);
  }

  /**
   * @Given /^I should not see the category type "([^"]*)"$/
   */
  public function iShouldNotSeeTheCategoryType($categoryType) {
    return !$this->assertPageContainsText($categoryType);
  }

  /**
   * @When /^I change the category type from "([^"]*)" to "([^"]*)"$/
   */
  public function iChangeTheCategoryTypeFromTo($oldCategoryType, $newCategoryType) {
    // Open edit window for the category type.
    $page = $this->getSession()->getPage();
    $editLink = $page->find('xpath', '//h3[text()="' . $oldCategoryType . '"]/following::a[text()="Edit"][1]');
    if (null === $editLink) {
      throw new \Exception('The edit link for the category ' . $oldCategoryType . ' not found');
    }
    $editLink->click();

    // Change name of category type.
    $termName = $page->find('xpath', '//*[@id="edit-name"]');
    if (null === $termName) {
      throw new \Exception('The "Term name" input not found');
    }
    $termName->setValue($newCategoryType);

    // Click "Save" button.
    $this->pressButton("Save");
  }

  /**
   * @When /^I delete category "([^"]*)" under the type "([^"]*)"$/
   */
  public function iDeleteCategoryUnderTheType($category, $categoryType) {
    // Open delete window for the category.
    $page = $this->getSession()->getPage();
    $editLink = $page->find('xpath', '//h3[text()="' . $categoryType . '"]/following::a[text()="' . $category . '"]/following::a[text()="Delete"][1]');
    if (null === $editLink) {
      throw new \Exception('The delete link for the category ' . $category . ' not found');
    }
    $editLink->click();

    // Click "Delete" button.
    $this->pressButton("Delete");
  }

  /**
   * @Then /^I should not see the category "([^"]*)" under the type "([^"]*)"$/
   */
  public function iShouldNotSeeTheCategoryUnderTheType($category, $categoryType) {
    // Find the category in specific type.
    $page = $this->getSession()->getPage();
    $category = $page->find('xpath', '//h3[text()="' . $categoryType . '"]/following::a[text()="' . $category . '"]');
    if (null !== $category) {
      throw new \Exception('The category ' . $category . ' exist in the type ' . $categoryType);
    }
  }

  /**
   * @When /^I delete all categories for category type "([^"]*)"$/
   */
  public function iDeleteAllCategoriesForCategoryType($categoryType) {
    // Open delete window for category type.
    $page = $this->getSession()->getPage();
    $editLink = $page->find('xpath', '//h3[text()="' . $categoryType . '"]/following::a[text()="Delete"][1]');
    if (null === $editLink) {
      throw new \Exception('The delete link for the category type ' . $categoryType . ' not found');
    }
    $editLink->click();

    // Click "Delete" button.
    $this->pressButton("Delete");
  }

  /**
   * @When /^I visit the group "([^"]*)" detail page "([^"]*)" with status "([^"]*)"$/
   */
  public function iVisitTheGroupDetailPageWithStatus($type, $title, $status) {
    return $this->iVisitNodePageOfTypeWithStatus($title, $type, $status);
  }

  /**
   * @When /^I visit the group "([^"]*)" detail page "([^"]*)"$/
   */
  public function iVisitTheGroupDetailPage($type, $title) {
    return $this->iVisitTheGroupDetailPageWithStatus($type, $title, NODE_PUBLISHED);
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
          $node = $this->loadGroupByTitleAndType($organization, 'organisation');
          $steps[] = new Step\When('I check the box "edit-restricted-organisations-' . $node->nid . '"');
        }
      }
    }
    if ($moderated) {
      $steps[] = new Step\When('I select the radio button "Moderated - Any member of capacity4dev who has access to this Group can request membership. The Group owner or one of the Group administrators needs to approve the request."');
    }

    $steps[] = new Step\When('I fill in ckeditor field "edit-c4m-body-und-0-value" with "This is default summary."');

    // This is a required tag.
    $steps[] = new Step\When('I check the related topic checkbox');

    // This is the required banner
    $steps[] = new Step\When('I attach the file to the field banner');

    // This is the required message to admin.
    $steps[] = new Step\When('I fill in "edit-field-message-to-site-admin-und-0-value" with "This is default message to admin."');

    $steps[] = new Step\When('I press "Request"');

    // Giving time for saving.
    $steps[] = new Step\When('I wait');

    // Check there was no error.
    $steps[] = new Step\When('I should not see "Group access"');
    $steps[] = new Step\When('I should not see "There was an error"');
    $steps[] = new Step\When('I should be on the homepage');
    $steps[] = new Step\When('I should see "The group you requested is pending review by one of the administrators."');

    $steps[] = new Step\When('The group "' . $title . '" status is changed by admin to "Draft"');
    $steps[] = new Step\When('The group "' . $title . '" status is changed by admin to "Published"');
    $steps[] = new Step\When('I am logged in as user "'. $username .'"');
    return $steps;
  }

  /**
   * @When /^I change access of group "([^"]*)" to "([^"]*)"$/
   */
  public function iChangeAccessOfGroupTo($title, $access, $domains = NULL) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $steps = array();
    $steps[] = new Step\When('I visit "node/' . $group->nid . '/edit"');
    $steps[] = new Step\When('I select the radio button "' . $access . '"');

    if ($access == 'Restricted') {
      if ($domains) {
        $steps[] = new Step\When('I fill in "edit-restricted-by-domain" with "' . $domains . '"');
      }
    }

    $steps[] = new Step\When('I fill in "edit-field-message-to-site-admin-und-0-value" with "This is default message to admin."');

    $steps[] = new Step\When('I press "Save"');
    $steps[] = new Step\When('I wait');
    $steps[] = new Step\When('I should not see "Group access"');
    $steps[] = new Step\When('I should not see "There was an error"');
    return $steps;
  }

  /**
   * @When /^I change access of group "([^"]*)" to "([^"]*)" to domain "([^"]*)"$/
   */
  public function iChangeAccessOfGroupToDomain($title, $access, $domains) {
    return $this->iChangeAccessOfGroupTo($title, $access, $domains);
  }

  /**
   * @Then /^I should see the groups and the user "([^"]*)" in the group management table$/
   */
  public function iShouldSeeGroupTable($username) {
    $steps = array();
    $steps[] = new Step\When('I should see "Name"');
    $steps[] = new Step\When('I should see "Architecture"');
    $steps[] = new Step\When('I should see "Status"');
    $steps[] = new Step\When('I should see "Owner"');
    $steps[] = new Step\When('I should see "' . $username . '"');
    $steps[] = new Step\When('I should see "edit"');

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
   * @Given /^I should see the Recent Members$/
   */
  public function iShouldSeeTheRecentMembers() {
    $page = $this->getSession()->getPage();
    $el = $page->find(
      'css',
      '.pane-c4m-overview-og-members .view-id-c4m_overview_og_members.view-display-id-block_1'
    );
    if ($el === null) {
      throw new \Exception('The Recent Members block is not visible.');
    }

    $subel = $page->find(
      'css',
      '.pane-c4m-overview-og-members .view-id-c4m_overview_og_members.view-display-id-block_1 .no-avatar.initials,
       .pane-c4m-overview-og-members .view-id-c4m_overview_og_members.view-display-id-block_1 img.user-image'
    );

    if ($subel === null) {
      throw new \Exception('No users found in the Recent Members block.');
    }
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

  /**
   * @Given /^I should not see the "([^"]*)" link on the group menu$/
   */
  public function iShouldNotSeeTheLinkOnTheGroupMenu($text) {
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

    if ($found) {
      throw new \Exception("$text link found on group menu.");
    }
  }

  /**
   * @When /^I start creating "([^"]*)" "([^"]*)" in group "([^"]*)" (with|without) file field "([^"]*)"$/
   */
  public function iStartCreatingInGroup($bundle, $title, $group_title, $condition, $file_field) {
    $steps = array();

    $group = $this->loadGroupByTitleAndType($group_title, 'group');
    $uri = $this->createUriWithGroupContext($group, '<front>');

    $steps[] = new Step\When('I visit "' . $uri . '/node/add/' . $bundle . '"');
    $steps[] = new Step\When('I fill in "title" with "' . $title . '"');
    $steps[] = new Step\When('I fill in ckeditor field "edit-c4m-body-und-0-value" with "This is default discussion."');
    if ($condition == 'with') {
      $steps[] = new Step\When('I upload the file "doc1.doc" in the field with id "' . $file_field . '"');
    }

    return $steps;
  }

  /**
   * @When /^I start editing "([^"]*)" "([^"]*)" in group "([^"]*)"$/
   */
  public function iStartEditingInGroup($bundle, $title, $group_title) {
    $steps = array();

    $group = $this->loadGroupByTitleAndType($group_title, 'group');
    $uri = $this->createUriWithGroupContext($group, '<front>');

    $nodes = entity_load('node', FALSE, array('type' => $bundle, 'title' => $title));
    $node = reset($nodes);
    $nid = $node->nid;

    $steps[] = new Step\When('I visit "' . $uri . '/node/' . $nid . '/edit"');

    return $steps;
  }

  /**
   * @Given /^I start editing group "([^"]*)"$/
   */
  public function iStartEditingGroup($group_title) {
    $steps = array();

    $group = $this->loadGroupByTitleAndType($group_title, 'group');
    $steps[] = new Step\When('I visit "/node/' . $group->nid . '/edit"');

    return $steps;
  }

  /**
   * @Then /^I should not be allowed to edit a group "([^"]*)"$/
   */
  public function iShouldNotBeAllowedToEditAGroup($group_title) {
    $group = $this->loadGroupByTitleAndType($group_title, 'group');
    return array(
      new Step\When('I go to "/node/' . $group->nid . '/edit"'),
      new Step\Then('I should get a "403" HTTP response'),
    );
  }

  /**
   * @Then /^I should be allowed to edit a group "([^"]*)"$/
   */
  public function iShouldBeAllowedToEditAGroup($group_title) {
    $group = $this->loadGroupByTitleAndType($group_title, 'group');
    return array(
      new Step\When('I go to "/node/' . $group->nid . '/edit"'),
      new Step\Then('I should get a "200" HTTP response'),
    );
  }


  /**
   * @Given /^The group "([^"]*)" status is changed by admin to "([^"]*)"$/
   */
  public function theGroupStatusIsChangedByAdminTo($group_title, $status) {
    $steps = array();

    $group = $this->loadGroupByTitleAndType($group_title, 'group');
    $steps[] = new Step\When('I am logged in as user "admin"');
    $steps[] = new Step\When('I visit "/node/' . $group->nid . '/edit"');
    $steps[] = new Step\When('I select "' . $status . '" from "edit-c4m-og-status-und"');
    $steps[] = new Step\When('I press "Save"');
    $steps[] = new Step\When('I wait');
    return $steps;
  }

  /**
   * @Given /^I enable the group feature "([^"]*)"$/
   */
  public function iEnableGroupFeature($feature) {
    $steps = array();
    $steps[] = new Step\When('I check the box "edit-variables-c4m-og-c4m-og-features-group-c4m-features-og-' . $feature . '"');
    return $steps;
  }

  /**
   * @Given /^I disable the group feature "([^"]*)"$/
   */
  public function iDisableGroupFeature($feature) {
    $steps = array();
    $steps[] = new Step\When('I uncheck the box "edit-variables-c4m-og-c4m-og-features-group-c4m-features-og-' . $feature . '"');
    return $steps;
  }

  /**
   * @When /^I manage the features of group "([^"]*)"$/
   */
  public function iManageFeaturesOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'manage/features');

    return new Given("I go to \"$uri\"");
  }

  /**
   * @When /^I manage the categories of group "([^"]*)"$/
   */
  public function iManageTheCategoriesOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'manage/categories');

    return new Given("I go to \"$uri\"");
  }

  /**
   * @When /^I manage the categories types of group "([^"]*)"$/
   */
  public function iManageTheCategoriesTypesOfGroup($title) {
    $group = $this->loadGroupByTitleAndType($title, 'group');
    $uri = $this->createUriWithGroupContext($group, 'manage/categories/types');

    return new Given("I go to \"$uri\"");
  }

  /**
   * @Given /^I move category "([^"]*)" under "([^"]*)"$/
   */
  public function iMoveCategoryUnder($category1, $category2) {
    $javascript = '
    var category1 = jQuery("tr.draggable").has("a:contains(\'' . $category1 . '\')");
    var category2 = jQuery("tr.draggable").has("a:contains(\'' . $category2 . '\')");
    category1.insertAfter(category2);
    ';
    $this->getSession()->executeScript($javascript);
  }

  /**
   * @Then /^I should see "([^"]*)" under "([^"]*)"$/
   */
  public function iShouldSeeUnder($category1, $category2) {
    $page = $this->getSession()->getPage();
    $el1 = $page->find('xpath', '//tr[descendant::a[contains(text(),\'' . $category2 . '\')]]/following-sibling::tr[1]');
    $el2 = $page->find('xpath', '//tr[descendant::a[contains(text(),\'' . $category1 . '\')]]');
    if ($el1->getText() != $el2->getText()) {
      throw new \Exception("order is wrong");
    }
  }

  /**
   * @Then /^I create a new term "([^"]*)" under "([^"]*)" with quick form$/
   */
  public function iCreateNewTerm($term_name, $parent_term_name) {
    // Get parent term ID.
    $parent = taxonomy_get_term_by_name($parent_term_name);
    if (empty($parent)) {
      throw new \Exception("$parent_term_name is not a taxonomy term.");
    }
    $parent_id = key($parent);

    $steps = array();
    $steps[] = new Step\When('I fill in "name-' . $parent_id . '" with "' . $term_name . '"');
    $steps[] = new Step\When('I press "'. $parent_id .'"');

    return $steps;
  }

  /**
   * @Then /^I create a new category type "([^"]*)" with quick form$/
   */
  public function iCreateCategoryTypeInQuickForm($type_name) {
    $steps = array();
    $steps[] = new Step\When('I fill in "name" with "' . $type_name . '"');
    $steps[] = new Step\When('I press "add-term"');

    return $steps;
  }

  /**
   * @Then /^I create a new category type "([^"]*)" with edit form$/
   */
  public function iCreateCategoryType($type_name) {
    $steps = array();
    $steps[] = new Step\When('I click "edit-new-category"');
    $steps[] = new Step\When('I fill in "name" with "' . $type_name . '"');
    $steps[] = new Step\When('I press "Save"');

    return $steps;
  }

  /**
   * @Given /^I reset order to alphabetical$/
   */
  public function iResetOrderToAlphabetical() {
    $page = $this->getSession()->getPage();
    $el = $page->find('xpath', '//a[contains(text(),\'Order items alphabetically\') and not(ancestor::*[contains(@style,\'visibility: hidden\')])]');
    $el->click();
  }
}
