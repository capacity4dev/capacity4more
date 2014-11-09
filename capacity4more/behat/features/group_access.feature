Feature: Group access
  Test group access

  @api @momo
  Scenario: Check public group
    Given a group "My bad hair day new group" with "Public" access and "badhairgroup222" url is created with group manager "turing"
     Then I am logged in as user "isaacnewton"
      And I visit "badhairgroup222"
     Then I should get a "200" HTTP response

  @api @wip
  Scenario: Check private group
    Given a group "My bad hair day new group" with "Private" access and "badhairgroup333" url is created with group manager "turing"
     Then I am logged in as user "isaacnewton"
      And I visit "badhairgroup333"
     Then I should get a "403" HTTP response


  @api @wip
  Scenario: Check allowed access by domain
    Given I am logged in as user "turing"
     Then I change group "newgroup4" permission to "restricted" with domains "gravity.com"
     Then I visit "momo" to see owner can still see the group
     Then I am logged in as the "isaacnewton"
     Then I visit "momo"
     Then I should see "quick post"

  @api @wip
  Scenario: Check restricted access by domain
    Given I am logged in as the "mariecurie"
    Then I edit group "momo"
    Then I set email domain to "gravity2.com"
    Then I am logged in as the"isaacnewton"
    Then I visit "momo"
    Then I should get 403

  @api @wip
  Scenario: Check
    Given I am logged in as the "mariecurie"
     Then I edit group "momo"
     Then I set email domain to "gravity2.com"
     Then I am logged in as the "isaacnewton"
     Then I visit "momo"
     Then I should get 403


