Feature: Group content access
  Test group content privacy is changing due to the group privacy.

  @javascript
  Scenario: Check group privacy from public to private
    Given a group "My public to private group" with "Public" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "Content in public to private group" in group "My public to private group" is created
    And   I change access of group "My public to private group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Content in public to private group" node of type "discussion"
    And   I should see "Access denied"

  @javascript
  Scenario: Check group privacy from private to public
    Given a group "My private to public group" with "Private" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "Content in private to public group" in group "My private to public group" is created
    And   I change access of group "My private to public group" to "Public"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Content in private to public group" node of type "discussion"
    And   I should not see "Access denied"
    And   I should see "Content in private to public group"

  @javascript
  Scenario: Check group privacy from public to restricted
    Given a group "My public to restricted group" with "Public" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "Content in public to restricted group" in group "My public to restricted group" is created
    And   I change access of group "My public to restricted group" to "Restricted"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Content in public to restricted group" node of type "discussion"
    And   I should see "Access denied"

  @javascript
  Scenario: Check group privacy from restricted to private
    Given a moderated group "My restricted to private group" with "gravity.com" restriction is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "Content in restricted to private group" in group "My restricted to private group" is created
    And   I change access of group "My restricted to private group" to "Private"
    When  I am logged in as user "isaacnewton"
    Then  I visit "Content in restricted to private group" node of type "discussion"
    And   I should see "Access denied"

  @javascript 
  Scenario: Check group privacy from private to restricted with some email domain
    Given a group "My private to restricted group1" with "Private" access is created with group manager "turing"
    And   I am logged in as user "turing"
    And   a discussion "Content in private to restricted group1" in group "My private to restricted group1" is created
    And   I change access of group "My private to restricted group1" to Restricted with "gravity.com" restriction
    When  I am logged in as user "isaacnewton"
    Then  I visit "Content in private to restricted group1" node of type "discussion"
    And   I should not see "Access denied"
    And   I should see "Content in private to restricted group1"
