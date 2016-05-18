Feature: Group content access
  Test group content privacy is changing due to the group privacy.

  @javascript
  Scenario: Check group privacy from public to private
    Given a group "My test group" with "Public" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "Test content" in group "My test group" is created
    And   I change access of group "My test group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Please log in to continue"

  @javascript
  Scenario: Check group privacy from private to public
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Public"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should not see "Please log in to continue"
    And   I should see "Test content"

  @javascript
  Scenario: Check group privacy from public to restricted
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Restricted"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Please log in to continue"

  @javascript
  Scenario: Check group privacy from restricted to private
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Please log in to continue"
