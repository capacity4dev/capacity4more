Feature: Testing user creation/manipulations.

  @api
  Scenario: Testing the user firstname+lastname URL alias path.
     Given I am an anonymous user
      When I visit "/users/charles-darwin"
      Then I should have access to the page

  @api
  Scenario: Testing the user profile fields
     Given I am an anonymous user
      When I visit "/users/charles-darwin"
      Then I should see a "Topics" field
       And I should see a "Topics of Expertise" field
       And I should see a "Regions & Countries" field
       And I should see a "Description" field

