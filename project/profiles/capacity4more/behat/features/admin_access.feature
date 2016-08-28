Feature: Test custom admin pages
  In order to check correct access permissions for admin
  As a site administrator and authenticated users
  I need to be able to access custom admin page

  @api
  Scenario: Authenticated user visits "Group Management" page should not have access
    Given I am logged in as user "isaacnewton"
    When  I go to "admin/c4m/groups"
    Then  I should not have access to the page

  @api
  Scenario: Admin user visits "Group Management" page should have access
    Given I am logged in as user "mariecurie"
    When  I go to "admin/c4m/groups"
    Then  I should have access to the page

  @api
  Scenario: Admin user visits "Group Management" page should see groups table
    Given I am logged in as user "mariecurie"
    When  I go to "admin/c4m/groups"
    Then  I should see the groups and the user "mariecurie" in the group management table

  @api @my
  Scenario: Site Admin user visits "Published" group, and is allowed to edit and delete it
    Given I am logged in as user "mariecurie"
    When  I visit "Published group" node of type "group"
    Then  I should be allowed to edit a group "Published group"
    And   I should see "Delete" in the "#edit-delete" element
    And   I should be allowed to delete a group "Published group"

  @api @my
  Scenario: Group Admin user visits "Published" group, and is allowed to edit but not to delete it
    Given I am logged in as user "turing"
    When  I visit "Published group" node of type "group"
    Then  I should be allowed to edit a group "Published group"
    And   I should not see an "#edit-delete" element
    And   I should not be allowed to delete a group "Published group"
