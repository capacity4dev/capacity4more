Feature: Group access
  Test group access

  @api
  Scenario: Check public group
    Given a group "My bad hair day new group 1" with "Public" access is created with group manager "turing"
      And a discussion "My content 1" in group "My bad hair day new group 1" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 1" node of type "group"
      And I should have access to the page
      And I visit "My content 1" node of type "discussion"
      And I should have access to the page

  @api
  Scenario: Check private group
    Given a group "My bad hair day new group 2" with "Private" access is created with group manager "turing"
      And a discussion "My content 2" in group "My bad hair day new group 2" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 2" node of type "group"
      And I should not have access to the page
      And I visit "My content 2" node of type "discussion"
      And I should not have access to the page

  @api
  Scenario: Check restricted group accessed by accepted user
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction is created with group manager "turing"
      And a discussion "My content 3" in group "My bad hair day new group 3" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 3" node of type "group"
      And I should have access to the page
      And I visit "My content 3" node of type "discussion"
      And I should have access to the page

  @api
  Scenario: Check restricted group accessed by denied used
    Given a moderated group "My bad hair day new group 42" with "gravity.com" restriction is created with group manager "turing"
      And a discussion "My content 42" in group "My bad hair day new group 4" is created
     When I am logged in as user "badhairday"
     Then I visit "My bad hair day new group 42" node of type "group"
      And I should not have access to the page
      And I visit "My content 4" node of type "discussion"
      And I should not have access to the page
