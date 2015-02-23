Feature: Group menu
  As a group member and non-member
  I see the group menu links

  @api
  Scenario: Check group menu links as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the dashboard of group "Nobel Prize"
    Then I should see the group menu
