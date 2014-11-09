Feature: Group access
  Test group access

  @api @wip
  Scenario: Check public group
    Given a group "My bad hair day new group" with "Public" access and "badhairgroup222" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "badhairgroup222"
     Then I should get a "200" HTTP response

  @api @wip
  Scenario: Check private group
    Given a group "My bad hair day new group" with "Private" access and "badhairgroup333" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "badhairgroup333"
     Then I should get a "403" HTTP response

  @api @wip
  Scenario: Check restricted group
    Given a group "My bad hair day new group" with "gravity.com" restriction and "badhairgroup3334" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "badhairgroup3334"
     Then I should get a "200" HTTP response
     When I am logged in as user "badhairday"
      And I visit "badhairgroup3334"
     Then I should get a "403" HTTP response
