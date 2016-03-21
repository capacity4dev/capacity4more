Feature: Group Members overview
  As a group member and non-member
  In order to see and search into all group members
  I need to be able to see a members overview list page
  I need to be able to see a members overview table page

  @api
  Scenario: Check group members list overview as an anonymous user
    Given I am an anonymous user
    When I visit the members list overview of group "Nobel Prize"
    Then I should see the group members list overview

  @api
  Scenario: Check group members table overview as an anonymous user
    Given I am an anonymous user
    When I visit the members table overview of group "Nobel Prize"
    Then I should see the group members table overview

  @api
  Scenario: Check members list overview as the group owner
    Given I am logged in as user "alfrednobel"
    When I visit the members list overview of group "Nobel Prize"
    Then I should see the group members list overview

  @api
  Scenario: Check people table overview as the group owner
    Given I am logged in as user "alfrednobel"
    When I visit the members table overview of group "Nobel Prize"
    Then I should see the group members table overview
