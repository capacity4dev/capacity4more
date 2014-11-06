Feature: Test quick post
  Test quick post is working.

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as the "admin"
    When  I visit "Tennis Group" node of type "group"
    And   I fill in "label" with "fo"
    Then  I should see "Label is too short."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as the "admin"
    When  I visit "Tennis Group" node of type "group"
    And   I fill in "label" with "foobar"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The discussions was saved successfully."

  @javascript
  Scenario: Check Quick post "document" submit.
    Given I am logged in as the "admin"
    When  I visit "Movie Popcorn Corner" node of type "group"
    And   I press the "Upload a Document" button
    And   I check the box "Research Paper"
    And   I fill in "label" with "foobar"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The documents was saved successfully."
