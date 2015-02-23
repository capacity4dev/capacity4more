Feature: Home page for anonymous users
  As a not-logged-in user
  In order to get to known the capacity4more project
  I visit the site homepage

  @api
  Scenario: Anonymous user should have access to the site homepage.
    Given I am an anonymous user
     When I visit the site homepage
     Then I should see the site homepage

  @api
  Scenario: Anonymous user should see button to open the introduction video.
    Given I am an anonymous user
     When I visit the site homepage
     Then I should see the homepage introduction video block
