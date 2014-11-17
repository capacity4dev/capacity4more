Feature: Test activity stream
  In order to see recent content in the group
  As a group member and non-member
  I need to be able to see an activity stream of recent operations

  @api
  Scenario: Check Discussion creating in my public group
    Given a group "Discussion Insert 1" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 1" and body "Some text in the body" in the group "Discussion Insert 1"
    Then  I should see "Discussion added 1" in the activity stream of the group "Discussion Insert 1"

  @api
  Scenario: Check Event creating in my public group
    Given a group "Discussion Insert 3" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "event" is created with title "Event added" and body "Some text in the body" in the group "Discussion Insert 3"
    Then  I should see "Event added" in the activity stream of the group "Discussion Insert 3"

  @api
  Scenario: Check message don't change when the same user updates right after creation earlier than 6 hours ago.
    Given a group "Discussion Insert 5" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 5" and body "Some text in the body" in the group "Discussion Insert 5"
    And   I update a "discussion" with title "Discussion added 5" with new title "Discussion updated 5"
    Then  I should see a creation message for "Discussion updated 5" in the activity stream of the group "Discussion Insert 5"

  @api
  Scenario: Check new message is not created when the same user updates right after he has updated it earlier than 6 hours ago.
    Given a group "Discussion Insert 6" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 6" and body "Some text in the body" in the group "Discussion Insert 6"
    When  I am logged in as user "survivalofthefittest"
    And   I update a "discussion" with title "Discussion added 6" with new title "Discussion updated 6"
    And   I update a "discussion" with title "Discussion updated 6" with new title "Discussion updated again 6"
    Then  I should see a new message for "Discussion updated again 6" in the activity stream of the group "Discussion Insert 6"

  @api
  Scenario: Check new message creating when the other user updates the discussion.
    Given a group "Discussion Insert 7" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 7" and body "Some text in the body" in the group "Discussion Insert 7"
    When  I am logged in as user "survivalofthefittest"
    And   I update a "discussion" with title "Discussion added 7" with new title "Discussion updated 7"
    Then  I should see a new message for "Discussion updated 7" in the activity stream of the group "Discussion Insert 7"

  @api 
  Scenario: Check creating new message when updating after 6 hours.
    Given a group "Discussion Insert 8" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 8" and body "Some text in the body" in the group "Discussion Insert 8"
    And   I update a "discussion" with title "Discussion added 8" with new title "Discussion updated 8" after "7 hours"
    Then  I should see a new message for "Discussion updated 8" in the activity stream of the group "Discussion Insert 8"

