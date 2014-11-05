Feature: Test tasks
  Test installation works

  @api
  Scenario: Create a comment on a task while changing some task fields and
    Given I am an anonymous user
    And   I visit "/user"
    Then  I should see "Log in"

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as the "admin"
    And   I visit "/stub-for-group-2/group/tennis-group"
    When  I fill in "label" with "fo"
    Then  I should see "Label is too short."

  @javascript
  Scenario: Check Quick post submit.
    Given I am logged in as the "admin"
    And   I visit "/stub-for-group-2/group/tennis-group"
    When  I fill in "label" with "foobar"
    And   I press the "quick-submit" button
    And   I wait
    Then  I should see "The discussions was saved successfully."
