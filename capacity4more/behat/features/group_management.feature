Feature: Group management
  As a group admin, member and non-member
  In order to see the group information and edit links
  I need to be able to see a dashboard with different blocks

  @api
  Scenario: Check management dashboard content as group owner
    Given I am logged in as user "alfrednobel"
    When  I visit the management dashboard of group "Nobel Prize"
    Then  I should see the group management dashboard

  @api
  Scenario: Check management dashboard is not accessible for non admin member of the group.
    Given I am logged in as user "isaacnewton"
    When  I visit the management dashboard of group "Nobel Prize"
    Then  I should see "Page not found"
