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
