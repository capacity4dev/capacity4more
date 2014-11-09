Feature: Group access
  Test group access

  @api @momo
  Scenario: Check public group
    Given I am logged in as user "turing"
     When I create new group titled "My badhairday new group" linked as "newgroup4"
     Then I am logged in as user "isaacnewton"
      And I visit "newgroup4"
      And I should get a "200" HTTP response


  @api @wip
  Scenario: Check allowed access by domain
    Given I am logged in as the "mariecurie"
     Then I edit group "momo"
     Then I set permissions to "restricted"
     Then I set email domain to "gravity.com"
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


