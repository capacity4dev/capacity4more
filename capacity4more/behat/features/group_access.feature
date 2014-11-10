Feature: Group access
  Test group access

  @api
  Scenario: Check public group
    Given a group "My bad hair day new group 1" with "Public" access and "badhairgroup1" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I go to "badhairgroup1/group/my-bad-hair-day-new-group-1"
     Then I should get a "200" HTTP response
      And I should see "Subscribe to group"

  @api
  Scenario: Check private group
    Given a group "My bad hair day new group 2" with "Private" access and "badhairgroup2" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I go to "badhairgroup2/group/my-bad-hair-day-new-group-2"
     Then I should get a "403" HTTP response

  @api
  Scenario: Check restricted group
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction and "badhairgroup3" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I go to "badhairgroup3/group/my-bad-hair-day-new-group-3"
     Then I should get a "200" HTTP response
      And I should see "Request group membership"
     When I am logged in as user "badhairday"
      And I go to "badhairgroup3/group/my-bad-hair-day-new-group-3"
     Then I should get a "403" HTTP response
