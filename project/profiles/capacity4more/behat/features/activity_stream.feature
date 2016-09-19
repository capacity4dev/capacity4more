Feature: Test activity stream
  In order to see recent content in the group
  As a group member and non-member
  I need to be able to see an activity stream of recent operations

  @javascript
  Scenario: Check message is created after Discussion is created in my public group
    Given a group "Discussion Insert 1" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 1" and topic "Fire" in the group "Discussion Insert 1"
    And   I am logged in as user "isaacnewton"
    Then  I should see "Discussion added 1" in the activity stream of the group "Discussion Insert 1"

  @javascript
  Scenario: Check author is displayed by Firstname + Lastname
    Given a group "Discussion Insert 3" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 3" and topic "Fire" in the group "Discussion Insert 3"
    And   I am logged in as user "isaacnewton"
    Then  I should see "Discussion added 3" with author "Isaac Newton" in the activity stream of the group "Discussion Insert 3"

  @javascript
  Scenario: Message is not changing when the same user updates right after creation earlier than 6 hours ago.
    Given a group "Discussion Insert 5" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 5" and topic "Fire" in the group "Discussion Insert 5"
    And   I update a "discussion" with title "Discussion added 5" with new title "Discussion updated 5" in group "Discussion Insert 5"
    Then  I should see a creation message for "Discussion updated 5" in the activity stream of the group "Discussion Insert 5"

  @javascript
  Scenario: A new message is not created when the same user updates right after he has updated it earlier than 6 hours ago.
    Given a group "Discussion Insert 6" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 6" and topic "Fire" in the group "Discussion Insert 6"
    And   I am logged in as user "survivalofthefittest"
    And   I update a "discussion" with title "Discussion added 6" with new title "Discussion updated again 6" "2" times
    Then  I should see a new message for "Discussion updated again 6" in the activity stream of the group "Discussion Insert 6"

  @javascript
  Scenario: New message is created when the other user updates the discussion.
    Given a group "Discussion Insert 7" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 7" and topic "Fire" in the group "Discussion Insert 7"
    And   I am logged in as user "survivalofthefittest"
    And   I update a "discussion" with title "Discussion added 7" with new title "Discussion updated 7" in group "Discussion Insert 7"
    Then  I should see a new message for "Discussion updated 7" in the activity stream of the group "Discussion Insert 7"

  @javascript
  Scenario: New message is created when updating after 6 hours.
    Given a group "Discussion Insert 8" with "Public" access is created with group manager "isaacnewton"
    When  I am logged in as user "isaacnewton"
    And   a "discussion" is created with title "Discussion added 8" and topic "Fire" in the group "Discussion Insert 8"
    And   I update a "discussion" with title "Discussion added 8" with new title "Discussion updated 8" after "7 hours"
    Then  I should see a new message for "Discussion updated 8" in the activity stream of the group "Discussion Insert 8"

  @javascript
  Scenario: Promote buttons shouldn't be displayed to anonymous users.
    Given  I am an anonymous user
    When  I visit the dashboard of group "Nobel Prize"
    Then  I should not see the ".fa-thumb-tack" element

  @javascript
  Scenario: Promote buttons shouldn't be displayed to users without access.
    Given  I am logged in as user "isaacnewton"
    When  I visit the dashboard of group "Nobel Prize"
    Then  I should not see the ".fa-thumb-tack" element

  @javascript
  Scenario Outline: Promote buttons should be displayed to users with access.
    Given  I am logged in as user "<user>"
    When  I visit the dashboard of group "Nobel Prize"
    Then  I should see the ".fa-star-o" element

    Examples:
      | user        |
      | alfrednobel |
      | mariecurie  |
