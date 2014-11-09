Feature: Group access
  Test group access

  @api
  Scenario: Check public group
    Given I am logged in as the "turing"
      And I should not see "Log in"
     When I visit "node/add/group"
      And I fill in "title" with "My badhairday new group"
      And I fill in "edit-purl-value" with "mybadhairdaygroup"
      And I fill in "edit-c4m-body-und-0-summary" with "This is my summary"
      And I check the box "Fire"
      And I press "Save"
     Then I am logged in as the "isaacnewton"
      And I visit "/mybadhairdaygroup"
      And I should print page to "mybadhairday"
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


