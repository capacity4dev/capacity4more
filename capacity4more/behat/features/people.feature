Feature: Global People overview
  As a group member and non-member
  In order to see and search into all people
  I need to be able to see a people overview list page
  I need to be able to see a people overview table page

  @api
  Scenario: Check people list overview as an anonymous user
    Given I am an anonymous user
    When I visit the people list overview
    Then I should see the people list overview

  @api
  Scenario: Check people table overview as an anonymous user
    Given I am an anonymous user
    When I visit the people table overview
    Then I should see the people table overview

  @api
  Scenario: Check people list overview as a logged in user
    Given I am logged in as user "mariecurie"
    When I visit the people list overview
    Then I should see the people list overview

  @api
  Scenario: Check people table overview as a logged in user
    Given I am logged in as user "mariecurie"
    When I visit the people table overview
    Then I should see the people table overview
