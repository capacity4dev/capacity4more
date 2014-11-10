Feature: Group access
  Test group access

  @api @momo
  Scenario: Check public group
    Given a group "My bad hair day new group" with "Public" access and "badhairgroup" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "badhairgroup"
     Then I should get a "200" HTTP response
      And I should see "Subscribe to group"

  @api
  Scenario: Check private group
    Given a group "My bad hair day new group" with "Private" access and "badhairgroup2" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "badhairgroup2"
     Then I should get a "403" HTTP response

  @api
  Scenario: Check restricted group
    Given a moderated group "My bad hair day new group" with "gravity.com" restriction and "badhairgroup3" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "badhairgroup3"
     Then I should get a "200" HTTP response
      And I should see "Request group membership"
     When I am logged in as user "badhairday"
      And I visit "badhairgroup3"
     Then I should get a "403" HTTP response
