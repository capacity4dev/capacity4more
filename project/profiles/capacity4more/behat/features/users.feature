Feature: Testing user creation/manipulations.

  @api
  Scenario: Testing the user firstname+lastname URL alias path.
     Given: I am an anonymous user
      When: I visit "/users/charles-darwin"
      Then: I should see a "Country" field

