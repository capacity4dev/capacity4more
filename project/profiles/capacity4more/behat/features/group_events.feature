Feature: Group Events
  As a group member and non-member
  In order to see and search into all events
  I need to be able to see an upcoming events overview page
  I need to be able to see a past events overview page
  I need to be able to see the events landing page
  I need to be able to see an event detail page

  @api
  Scenario: Check events landing page as an anonymous user
    Given I am an anonymous user
    When I visit the events landing page of group "Nobel Prize"
    Then I should see an upcoming and past events block
    And I should not see the "Add an event" link above the overview

  @api
  Scenario: Check events landing page as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the events landing page of group "Nobel Prize"
    Then I should see an upcoming and past events block
    And I should see the "Add an event" link above the overview

  @api @nir
  Scenario: Check upcoming events overview as an anonymous user
    Given I am an anonymous user
    When I visit the upcoming events overview of group "Nobel Prize"
    Then I should see the upcoming events overview
    And I should not see the "ADD AN EVENT" link above the overview

  @api @nir
  Scenario: Check past events overview as an anonymous user
    Given I am an anonymous user
    When I visit the past events overview of group "Nobel Prize"
    Then I should see the past events overview
    And I should not see the "ADD AN EVENT" link above the overview

  @api @nir
  Scenario: Check upcoming events overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the upcoming events overview of group "Nobel Prize"
    Then I should see the upcoming events overview
    And I should see the "ADD AN EVENT" link above the overview

  @api @nir
  Scenario: Check past events overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the past events overview of group "Nobel Prize"
    Then I should see the past events overview
    And I should see the "ADD AN EVENT" link above the overview

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

  # TODO : Setting the topic does not work on events!
  # @javascript
  @wip
  Scenario: Check group reference field is filled from context and hidden
    Given I am logged in as user "mariecurie"
    When  I start creating "event" "Some new event1" in group "Architecture" without file field "document"
    And   I check the related topic checkbox
    And   I should not see an "edit-og-group-ref-und-0-default" element
    And   I press "Save"
    Then  I should see "Some new event1" in the activity stream of the group "Architecture"

  # TODO : Setting the topic does not work on events!
  # @javascript
  @wip
  Scenario: Check group reference field is filled from context and hidden
    Given I am logged in as user "mariecurie"
    When  I start editing "event" "Some new event1" in group "Architecture"
    Then  I should not see an "edit-og-group-ref-und-0-default" element
