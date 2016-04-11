Feature: Learning space
  Test the learning space page

  @api
  Scenario: Check learning page as anonymous user
    Given I am an anonymous user
    When I visit the learning page
    Then I should have access to the page
    Then I should see only "1" events
    Then I should see only "2" documents
