Feature: Group Discussions
  As a group member and non-member
  In order to see and search into all discussions
  I need to be able to see a discussions overview page

  @api @wip
  Scenario: Check discussions overview as group owner
    Given I am logged in as user "badhairday"
    When I visit the discussions overview of group "Football Talk"
    Then I should see the discussions overview
