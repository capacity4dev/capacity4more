Feature: Test Activity Stream
  Test activity stream works

  @api @foo
  Scenario: Check Discussion creating in my public group
    Given a group "Discussion Insert 1" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "isaacnewton"
    And   a "discussion" is created with title "Discussion added 1" and body "Some text in the body" in the group "Discussion Insert 1"
    Then  I should see "Discussion added 1" in the activity stream of the group "Discussion Insert 1"

  @api @foo
  Scenario: Check Discussion creating if I don't have a group
    Given a group "Discussion Insert 2" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "turing"
    Then  I should not be allowed to go to "node/add/discussion"

  @api @foo
  Scenario: Check Event creating in my public group
    Given a group "Discussion Insert 3" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "isaacnewton"
    And   a "event" is created with title "Event added" and body "Some text in the body" in the group "Discussion Insert 3"
    Then  I should see "Event added" in the activity stream of the group "Discussion Insert 3"

  @api @foo
  Scenario: Check Event creating if I don't have a group
    Given a group "Discussion Insert 4" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "turing"
    Then  I should not be allowed to go to "node/add/event"

  @api @foo
  Scenario: Check creating new message when updating before 6 hours.
    Given a group "Discussion Insert 5" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "isaacnewton"
    And   a "discussion" is created with title "Discussion added 5" and body "Some text in the body" in the group "Discussion Insert 5"
    And   I update a "discussion" with title "Discussion added 5" with new title "Discussion updated 5"
    Then  I should see "Discussion updated 5" in the activity stream of the group "Discussion Insert 5"
    And   I should not see "posted Information"
    And   I should see "updated the Information"

  @api @foo
  Scenario: Check creating new message when updating after 6 hours.
    Given a group "Discussion Insert 6" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as the "isaacnewton"
    And   a "discussion" is created with title "Discussion added 6" and body "Some text in the body" in the group "Discussion Insert 6"
    And   After 6 hours
    And   I update a "discussion" with title "Discussion added 6" with new title "Discussion updated 6"
    Then  I should see "Discussion updated 6" in the activity stream of the group "Discussion Insert 6"
    And   I should see "posted Information" in the activity stream of the group "Discussion Insert 6"
    And   I should see "updated the Information" in the activity stream of the group "Discussion Insert 6"

