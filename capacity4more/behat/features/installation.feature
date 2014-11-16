Feature: Test tasks
  Test installation works

  @api
  Scenario: Create a comment on a task while changing some task fields and
    Given I am an anonymous user
     When I visit "/user"
     Then I should see "Log in"
