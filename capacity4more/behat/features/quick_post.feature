Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as user "mariecurie"
    When  I visit "Tennis Group" node of type "group"
    And   I fill in "label" with "fo"
    Then  I should see "Title is too short."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I fill a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
    Then  I submit and should see "The Discussion was saved successfully."

  @javascript
  Scenario: Check Quick post "event" submit.
    Given I am logged in as user "mariecurie"
    When  I fill an event quick post with title "New event" and body "Some text in the body" that starts at "25/12/2018" and ends at "26/12/2018" in "Tennis Group"
    Then  I submit and should see "The Event was saved successfully."
