Feature: Test quick post
  In order to create entities from the quick post.
  As a drupal authenticated user.
  I need to be able to submit quick posts.

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as user "mariecurie"
    When  I visit "Tennis Group" node of type "group"
    And   I fill in "label" with "fo"
    Then  I should see "Title is too short."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I visit "Tennis Group" node of type "group"
    And   I press the "Add a Discussion" button
    And   I fill in "label" with "New discussion"
    And   I fill editor "body" with "New discussion description."
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The Discussion was saved successfully."

  @javascript
  Scenario: Check Quick post "event" submit.
    Given I am logged in as user "mariecurie"
    When  I visit "Tennis Group" node of type "group"
    And   I press the "Add an Event" button
    And   I press the "Meeting" button
    And   I fill in "label" with "New event"
    And   I fill editor "body" with "New event description."
    And   I fill in "startDate" with "2015-12-25"
    And   I fill in "endDate" with "2015-12-26"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The Event was saved successfully."
