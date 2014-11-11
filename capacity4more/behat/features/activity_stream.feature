Feature: Test Activity Stream
  Test activity stream works

  @api @foo
  Scenario: Check public group
    Given a group "discussion insert" with "Public" access is created with group manager "admin"
    When  I am logged in as the "admin"
    And   a "discussion" is created with title "Discussion added" and body "Some text in the body" in the group "discussion insert"
    Then  I should see "Discussion added" in the activity stream of the group "discussion insert"

