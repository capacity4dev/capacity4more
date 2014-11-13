Feature: Test Activity Stream
  Test group members' permissions.

  @api
  Scenario: Check Discussion creating if I don't have a group
    Given a group "Discussion Insert 2" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "turing"
    Then  I should not be allowed to create a "discussion"

  @api
  Scenario: Check Event creating if I don't have a group
    Given a group "Discussion Insert 4" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "turing"
    Then  I should not be allowed to create a "event"
