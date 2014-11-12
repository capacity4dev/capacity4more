Feature: Group access
  Test group access

  @api
  Scenario: Check public group
    Given a group "My bad hair day new group 1" with "Public" access is created with group manager "turing"
      And a discussion "My content 1" in group "My bad hair day new group 1" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 1" node of type "group"
      And I should get a "200" HTTP response
      And I should see "Subscribe to group"
      And I visit "My content 1" node of type "discussion"
      And I should get a "200" HTTP response

  @api
  Scenario: Check private group
    Given a group "My bad hair day new group 2" with "Private" access is created with group manager "turing"
      And a discussion "My content 2" in group "My bad hair day new group 2" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 2" node of type "group"
      And I should get a "403" HTTP response
      And I visit "My content 2" node of type "discussion"
      And I should get a "403" HTTP response

  @api
  Scenario: Check restricted group accessed by accepted user
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction is created with group manager "turing"
      And a discussion "My content 3" in group "My bad hair day new group 3" is created
     When I am logged in as user "isaacnewton"
     Then I visit "My bad hair day new group 3" node of type "group"
      And I should get a "200" HTTP response
      And I should see "Request group membership"
      And I visit "My content 3" node of type "discussion"
      And I should get a "200" HTTP response

  @api
  Scenario: Check restricted group accessed by denied used
    Given a moderated group "My bad hair day new group 4" with "gravity.com" restriction is created with group manager "turing"
      And a discussion "My content 4" in group "My bad hair day new group 4" is created
     When I am logged in as user "badhairday"
     Then I visit "My bad hair day new group 4" node of type "group"
      And I should get a "403" HTTP response
      And I visit "My content 4" node of type "discussion"
      And I should get a "403" HTTP response
