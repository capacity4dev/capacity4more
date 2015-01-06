Feature: Test full form
  In order to see that the full form forms work
  As a group member and non-member
  I need to be able to add entities with the full form

  @javascript
  Scenario: Check the tags-categories widget.
    Given I am logged in as user "mariecurie"
    When  I create a discussion full form with title "New discussion" and body "Some text in the body" in "Tennis Group"
    And   I fill the full form
    Then  I should see the entity details
