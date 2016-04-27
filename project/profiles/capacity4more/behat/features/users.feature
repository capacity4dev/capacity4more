Feature: Testing user creation/manipulations.

  @api2
  Scenario: Testing the user firstname+lastname URL alias path.
     Given: I am an anonymous user
      When: I visit "/users/charles-darwin"
      Then: I should see a "Country" field

