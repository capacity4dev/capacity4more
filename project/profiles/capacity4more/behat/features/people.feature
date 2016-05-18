Feature: Global People overview
  As a group member and non-member
  In order to see and search into all people
  I need to be able to see a people overview list page

  @api
  Scenario: Check people list overview as an anonymous user
    Given I am an anonymous user
    When I visit the people list overview
    Then I should see the people list overview

  @api
  Scenario: Check people list overview as a logged in user
    Given I am logged in as user "mariecurie"
    When I visit the people list overview
    Then I should see the people list overview

  @api
  Scenario: Check sorting options on the people overview
    Given I am an anonymous user
    When I visit the people list overview
    Then I should be able to sort the overview
    And I should be able to sort the overview by "First Name"
    And I should be able to sort the overview by "Last Name"
    And I should be able to sort the overview by "Date of registration"
    And I should be able to sort the overview by "Number of activity"
