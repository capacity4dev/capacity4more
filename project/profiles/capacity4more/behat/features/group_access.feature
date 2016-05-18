Feature: Group access
  Test group access

  @javascript
  Scenario: Check public group
    Given a group "My bad hair day new group 111" with "Public" access is created with group manager "turing"
      And a discussion "My content 111" in group "My bad hair day new group 111" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 111" node of type "group"
      And I should not see "User account"
      And I visit "My content 111" node of type "discussion"
      And I should not see "User account"

  @javascript
  Scenario: Check private group
    Given a group "My bad hair day new group 2" with "Private" access is created with group manager "turing"
      And a discussion "My content 2" in group "My bad hair day new group 2" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 2" node of type "group"
      And I should see "User account"
      And I visit "My content 2" node of type "discussion"
      And I should see "User account"

  @javascript
  Scenario: Check restricted group accessed by accepted user
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction is created with group manager "turing"
      And a discussion "My content 3" in group "My bad hair day new group 3" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 3" node of type "group"
      And I should not see "User account"
      And I visit "My content 3" node of type "discussion"
      And I should not see "User account"
      And I am logged in as user "badhairday"
      And I visit "My bad hair day new group 3" node of type "group"
      And I should see "User account"
      And I visit "My content 3" node of type "discussion"
      And I should see "User account"

  @javascript
  Scenario: Check restricted group accessed by accepted organization user
    Given a moderated group "My bad hair day new group 5" with "EC/EEAS" organization restriction is created with group manager "turing"
      And a discussion "My content 5" in group "My bad hair day new group 5" is created
     When I am logged in as user "president"
     Then I visit "My bad hair day new group 5" node of type "group"
      And I should not see "User account"
      And I visit "My content 5" node of type "discussion"
      And I should not see "User account"
      And I am logged in as user "isaacnewton"
      And I visit "My bad hair day new group 5" node of type "group"
      And I should see "User account"
      And I visit "My content 5" node of type "discussion"
      And I should see "User account"

  @api
  Scenario: Check hidden fields for an authorized user while creating a new group.
    Given I am logged in as user "isaacnewton"
    When I visit "node/add/group"
    Then I should not see an ".field-name-c4m-related-projects" element
    And I should not see an ".field-name-c4m-related-group" element
    And I should not see an ".field-name-c4m-og-status" element
    And I should not see an ".tabbable.tabs-left.vertical-tabs" element
