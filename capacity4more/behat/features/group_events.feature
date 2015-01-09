Feature: Group Events
  As a group member and non-member
  In order to see and search into all events
  I need to be able to see an upcoming events overview page
  I need to be able to see a past events overview page
  I need to be able to see an event detail page

  @api
  Scenario: Check upcoming events overview as an anonymous user
    Given I am an anonymous user
    When I visit the upcoming events overview of group "Nobel Prize"
    Then I should see the upcoming events overview
    And I should not see the "Add an Event" link above the overview

  @api
  Scenario: Check past events overview as an anonymous user
    Given I am an anonymous user
    When I visit the past events overview of group "Nobel Prize"
    Then I should see the past events overview
    And I should not see the "Add an Event" link above the overview

  @api
  Scenario: Check upcoming events overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the upcoming events overview of group "Nobel Prize"
    Then I should see the upcoming events overview
    And I should see the "Add an Event" link above the overview

  @api
  Scenario: Check past events overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the past events overview of group "Nobel Prize"
    Then I should see the past events overview
    And I should see the "Add an Event" link above the overview

  @api
  Scenario: Check event detail as an anonymous user
    Given I am an anonymous user
    When I visit the group "event" detail page "Nobel Prize Issueing"
    Then I should see the event detail page

  @api
  Scenario: Check event detail as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the group "event" detail page "Nobel Prize Issueing"
    Then I should see the event detail page

