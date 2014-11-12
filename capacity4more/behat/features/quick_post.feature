Feature: Test quick post
  Test quick post is working.

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as user "admin"
    When  I visit "Tennis Group" node of type "group"
    And   I fill in "label" with "fo"
    Then  I should see "Title is too short."

  @wip @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "admin"
    When  I visit "Tennis Group" node of type "group"
    And   I press the "Add a Discussion" button
    And   I fill in "label" with "New discussion"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The Discussion was saved successfully."

  @wip @javascript
  Scenario: Check Quick post "document" submit.
    Given I am logged in as user "admin"
    When  I visit "Movie Popcorn Corner" node of type "group"
    And   I press the "Upload a Document" button
    And   I check the box "Research Paper"
    And   I fill in "label" with "New document"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The Document was saved successfully."

  @wip @javascript
  Scenario: Check Quick post "event" submit.
    Given I am logged in as user "admin"
    When  I visit "Movie Popcorn Corner" node of type "group"
    And   I press the "Add an Event" button
    And   I press the "Meeting" button
    And   I fill in "label" with "New event"
    And   I fill in "start_date" with "2015-12-25"
    And   I fill in "end_date" with "2015-12-26"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The Event was saved successfully."
