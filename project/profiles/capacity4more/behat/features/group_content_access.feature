Feature: Group content access
  Test group content privacy is changing due to the group privacy.

  @javascript
  Scenario: Check group privacy from public to private
    Given a group "My test group" with "Public" access is created with group manager "turing"
    And   a discussion "Test content" in group "My test group" is created
    When  I am an anonymous user
    Then  I should see "My test group" on the "groups" overview
    When  I am logged in as user "turing"
    And   I change access of group "My test group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Access denied"
    Then  I should not see "My test group" on the "groups" overview

  @javascript
  Scenario: Check group privacy from private to public
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Public"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should not see "Access denied"
    And   I should see "Test content"
    And   I should see "My test group" on the "groups" overview

  @javascript
  Scenario: Check group privacy from public to restricted
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Restricted"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Access denied"
    And   I should not see "My test group" on the "groups" overview

  @javascript
  Scenario: Check group privacy from restricted to private
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Access denied"
    And   I should not see "My test group" on the "groups" overview

  @javascript
  Scenario: An anonymous user shouldn't be able to see a restricted group's content.
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Restricted" with the domain "turingmachine.com"
    When  I am an anonymous user
    Then  I visit "Test content" node of type "discussion"
    And   I should not see "Test content"
    And   I should see "Please log in to continue"
    And   I should not see "My test group" on the "groups" overview
    When  I am logged in with a temporal user with email domain "turingmachine.com"
    And   I should see "My test group" on the "groups" overview

  @javascript
  Scenario: A non-member of the organization shouldn't be able to see the group's content.
    Given I am logged in as user "president"
    Then  I visit "Test content" node of type "discussion"
    And   I should not see "Test content"
    And   I should see "Access denied"
    And   I should not see "My test group" on the "groups" overview

  @javascript
  Scenario: A member of the organization (by email domain) should be able to see the group's content.
    Given I am logged in as user "charlesbabbage"
    Then  I visit "Test content" node of type "discussion"
    And   I should not see "Access denied"
    And   I should see "Test content"
    And   I should see "My test group" on the "groups" overview
