Feature: Unified Workflow
  Test unified workflow

  @api
  Scenario: As a visitor I can request a membership of a moderated group.
    Given  I am an anonymous user
     When  I visit the dashboard of group "Nobel Prize"
     And   I click "Request membership for this group"
     Then  I should see "To join the Nobel Prize group you need to register with capacity4more by filling in your details below"

  @api
  Scenario: As a visitor I can request a membership of a moderated group.
    Given I am logged in with a temporal user
    When  I visit the dashboard of group "Football Talk"
    And   I click "Join this group"
    Then  I should see "Welcome to group Football Talk"
    When  I am logged in as user "mariecurie"
    Then  I block "temporal_user" from "Football Talk"
    When  I am logged in with a temporal user again
    And   I visit the dashboard of group "Football Talk"
    Then  I should not see the text "Join this group"
    When  I try to join the "Football Talk" group via url
    Then  I should not have access to the page
