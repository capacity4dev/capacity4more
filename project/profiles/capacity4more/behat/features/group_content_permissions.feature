Feature: Test creation of the content permissions.
  Test group members' permissions.

  @javascript
  Scenario: Check Discussion creating in the own group
    Given a group "Discussion Insert 2" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    Then  I should be allowed to create a "discussion" in group "Discussion Insert 2"

  @javascript
  Scenario: Check Event creating in the own group
    Given a group "Discussion Insert 4" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    Then  I should be allowed to create a "event" in group "Discussion Insert 4"
