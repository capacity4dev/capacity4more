Feature: Group access
  Test group access

  @api
  Scenario: Check public group
    Given I am logged in as the "mariecurie"
     Then I should not see "Log in"
     Then I create group "momo" with "public" permission
     Then I login as "isaacnewton"
     Then I visit "momo"
     Then I should see "quick post"

  @api @wip
  Scenario: Check allowed access by domain
    Given I am logged in as the "mariecurie"
     Then I edit group "momo"
     Then I set permissions to "restricted"
     Then I set email domain to "gravity.com"
     Then I visit "momo" to see owner can still see the group
     Then I login as "isaacnewton"
     Then I visit "momo"
     Then I should see "quick post"

  @api @wip
  Scenario: Check restricted access by domain
    Given I am logged in as the "mariecurie"
     Then I edit group "momo"
     Then I set email domain to "gravity2.com"
     Then I login as "isaacnewton"
     Then I visit "momo"
     Then I should get 403
