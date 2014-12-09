Feature: Group content access
  Test group content privacy is changing due to the group privacy.

  @javascript
  Scenario: Check group privacy from public to private
    Given a group "My public group" with "Public" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "My content in public group" in group "My public group" is created
    And   I change access of group "My public group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "My content in public group" node of type "discussion"
    And   I should see "Access denied"

  @javascript 
  Scenario: Check group privacy from private to public
    Given a group "My private group" with "Private" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "My content in private group" in group "My private group" is created
    And   I change access of group "My private group" to "Public"
    When  I am logged in as user "isaacnewton"
    Then  I visit "My content in private group" node of type "discussion"
    And   I should not see "Access denied"
    And   I should see "My content in private group"


