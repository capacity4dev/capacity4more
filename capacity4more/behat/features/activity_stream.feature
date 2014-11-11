Feature: Test Activity Stream
  Test activity stream works

  @api @foo
  Scenario: Check Discussion creating in my public group
    Given a group "Discussion Insert" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "isaacnewton"
    And   a "discussion" is created with title "Discussion added" and body "Some text in the body" in the group "Discussion Insert"
    Then  I should see "Discussion added" in the activity stream of the group "Discussion Insert"

  @api @foo
  Scenario: Check Discussion creating if I don't have a group
    Given a group "Discussion Insert" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "turing"
    And   I visit "node/add/discussion"
    Then  I should get a "403" HTTP response

