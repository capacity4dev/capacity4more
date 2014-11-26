Feature: Test activity stream
  In order to see recent content in the group
  As a group member and non-member
  I need to be able to see an activity stream of recent operations

  @api @wip
  Scenario: Check Discussion creating in my public group
    Given a group "Discussion Insert 1" with "Public" access is created with group manager "isaacnewton"
    When  a "discussion" is created with title "Discussion added 1" and body "Some text in the body" in the group "Discussion Insert 1" with group manager "isaacnewton"
    And   the cache has been cleared
    Then  I should see "Discussion added 1" in the activity stream of the group "Discussion Insert 1" when i am logged in as "isaacnewton"

  @api @wip
  Scenario: Check Event creating in my public group
    Given a group "Discussion Insert 3" with "Public" access is created with group manager "isaacnewton"
    When   a "event" is created with title "Event added" and body "Some text in the body" in the group "Discussion Insert 3" with group manager "isaacnewton"
    And   the cache has been cleared
    Then  I should see "Event added" in the activity stream of the group "Discussion Insert 3" when i am logged in as "isaacnewton"

  @api @wip
  Scenario: Check creating new message when updating before 6 hours.
    Given a group "Discussion Insert 5" with "Public" access is created with group manager "isaacnewton"
    And   a "discussion" is created with title "Discussion added 5" and body "Some text in the body" in the group "Discussion Insert 5" with group manager "isaacnewton"
    And   I update a "discussion" with title "Discussion added 5" with new title "Discussion updated 5"
    And   the cache has been cleared
    Then  I should see an updated message for "Discussion updated 5" in the activity stream of the group "Discussion Insert 5"

  @api @wip
  Scenario: Check creating new message when updating after 6 hours.
    Given a group "Discussion Insert 6" with "Public" access is created with group manager "isaacnewton"
    And   a "discussion" is created with title "Discussion added 6" and body "Some text in the body" in the group "Discussion Insert 6" with group manager "isaacnewton"
    And   I update a "discussion" with title "Discussion added 6" with new title "Discussion updated 6" after "7 hours"
    And   the cache has been cleared
    Then  I should see a new message for "Discussion updated 6" in the activity stream of the group "Discussion Insert 6"
