Feature: Group access
  Test group access

  @api
  Scenario: Check restricted access by domain
    Given I visit "/user"
     Then I should see "Log in"
