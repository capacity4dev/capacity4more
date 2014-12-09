Feature: Group content access
  Test group content privacy is changing due to the group privacy.

  @api 
  Scenario: Check group privacy from public to private
    Given a group "My public group" with "Public" access is created with group manager "turing"
    And   a discussion "My content in public group" in group "My public group" is created
    When  I am logged in as user "turing"
    And   I change access of group "My public group" to "Private"
    And   I am logged in as user "isaacnewton"
    Then  I visit "My content in public group" node of type "discussion"
    And   I should not have access to the page


