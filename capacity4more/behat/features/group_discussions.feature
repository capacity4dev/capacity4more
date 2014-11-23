Feature: Group Discussions
  As a group member and non-member
  In order to see and search into all discussions
  I need to be able to see a discussions overview page

  @api
  Scenario: Check discussions overview as an anonymous user
    Given I am an anonymous user
    When I visit the discussions overview of group "Nobel Prize"
    Then I should see the discussions overview
    Then I should not see the "Add a Discussion" link above the overview

  @api
  Scenario: Check discussions overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the discussions overview of group "Nobel Prize"
    Then I should see the discussions overview
    Then I should see the "Add a Discussion" link above the overview