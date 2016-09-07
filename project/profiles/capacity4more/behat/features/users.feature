Feature: Testing user creation/manipulations.

  @api
  Scenario: Testing the user firstname+lastname URL alias path.
     Given I am an anonymous user
      When I visit "/users/charles-darwin"
      Then I should have access to the page

  @api
  Scenario: Testing the user profile fields
     Given I am an anonymous user
      When I visit "/users/galileo-galilei"
      Then I should see a "Country" field
      Then I should see a "Topics" field
       And I should see a "Topics of Expertise" field
       And I should see a "Regions & Countries" field
       And I should see a "About You" field
       And I should see a "Notable Contributions" field

  @api
  Scenario: The user tries to leave the platform but still has groups.
    Given I am logged in as user "mariecurie"
    When I visit the leave platform page of "mariecurie"
    Then I should see "You can't leave the platform"

  @javascript
  Scenario: The user leaves the platform.
    Given I am logged in with a temporal user
    When I visit the leave platform page of "temporaluser"
    And I press "Confirm"
    Then I should see "Cancelling account"
