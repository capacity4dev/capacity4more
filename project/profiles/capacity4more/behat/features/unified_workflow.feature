Feature: Unified Workflow
  Test unified workflow

  @api
  Scenario: As a visitor I can request a membership of a moderated group.
    Given I am an anonymous user
     When  I visit the dashboard of group "Nobel Prize"
     And I click "Request membership for this group"
     Then  I should see "To join the Nobel Prize group you need to register with capacity4more by filling in your details below"
