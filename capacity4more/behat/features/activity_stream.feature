Feature: Test activity stream
  In order to see recent content in the group
  As a group member and non-member
  I need to be able to see an activity stream of recent operations

  @javascript 
  Scenario: Check message is created after Discussion is created in my public group
    Given a group "Discussion Insert 1" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 1" in the group "Discussion Insert 1"
    Then  I should see "Discussion added 1" in the activity stream of the group "Discussion Insert 1" when i am logged in as "isaacnewton"

  @javascript 
  Scenario: Check message is created after Event is created in my public group
    Given a group "Discussion Insert 3" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "event" is created with title "Event added" in the group "Discussion Insert 3"
    Then  I should see "Event added" in the activity stream of the group "Discussion Insert 3" when i am logged in as "isaacnewton"

  @javascript 
  Scenario: Message is not changing when the same user updates right after creation earlier than 6 hours ago.
    Given a group "Discussion Insert 5" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 5" in the group "Discussion Insert 5"
    And   I update a "discussion" with title "Discussion added 5" with new title "Discussion updated 5"
    Then  I should see a creation message for "Discussion updated 5" in the activity stream of the group "Discussion Insert 5"

  @javascript 
  Scenario: A new message is not created when the same user updates right after he has updated it earlier than 6 hours ago.
    Given a group "Discussion Insert 6" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 6" in the group "Discussion Insert 6"
    And   I am logged in as user "survivalofthefittest"
    And   I update a "discussion" with title "Discussion added 6" with new title "Discussion updated again 6" "2" times
    Then  I should see a new message for "Discussion updated again 6" in the activity stream of the group "Discussion Insert 6"

  @javascript 
  Scenario: New message is created when the other user updates the discussion.
    Given a group "Discussion Insert 7" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 7" in the group "Discussion Insert 7"
    And   I am logged in as user "survivalofthefittest"
    And   I update a "discussion" with title "Discussion added 7" with new title "Discussion updated 7"
    Then  I should see a new message for "Discussion updated 7" in the activity stream of the group "Discussion Insert 7"

  @javascript 
  Scenario: New message is created when updating after 6 hours.
    Given a group "Discussion Insert 8" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 8" in the group "Discussion Insert 8"
    And   I update a "discussion" with title "Discussion added 8" with new title "Discussion updated 8" after "7 hours"
    Then  I should see a new message for "Discussion updated 8" in the activity stream of the group "Discussion Insert 8"
