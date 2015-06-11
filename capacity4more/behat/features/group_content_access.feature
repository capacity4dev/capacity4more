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
    And   I should see "Access denied"

  @javascript
  Scenario: Check group privacy from private to public
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Public"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should not see "Access denied"
    And   I should see "Test content"

  @javascript
  Scenario: Check group privacy from public to restricted
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Restricted"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Access denied"

  @javascript
  Scenario: Check group privacy from restricted to private
    Given I am logged in as user "turing"
    And   I change access of group "My test group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Test content" node of type "discussion"
    And   I should see "Access denied"

  @api
  Scenario: I should not be able to CREATE content out of group.
    Given I am logged in as user "isaacnewton"
    When  I go to "/node/add/discussion"
    Then  I should not have access to the page

  @api
  Scenario: I should not be able to EDIT content out of group.
    Given I am logged in as user "isaacnewton"
    When  a discussion "Test content" in group "Tennis Group" is created
    Then  I should not be allowed to edit "discussion" "Test content" out of group

  @api
  Scenario: I should not be able to VIEW content out of group.
    Given I am logged in as user "isaacnewton"
    When  a discussion "Test content1" in group "Tennis Group" is created
    Then I should not be allowed to view "discussion" "Test content1" out of group

  @api
  Scenario: I should not be able to DELETE content out of group.
    Given I am logged in as user "isaacnewton"
    When  a discussion "Test content2" in group "Tennis Group" is created
    Then  I should not be allowed to delete "discussion" "Test content2" out of group
