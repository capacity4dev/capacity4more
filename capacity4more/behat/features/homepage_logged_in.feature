Feature: Home page for logged in users
  As a logged in user
  In order to get an overview of the platform
  I visit the site homepage

  @api
  Scenario: Anonymous user should have access to the site homepage.
    Given I am logged in as user "mariecurie"
     When I visit the site homepage
     Then I should see the site homepage

  @api
  Scenario: Anonymous user should see button to open the introduction video.
    Given I am logged in as user "mariecurie"
     When I visit the site homepage
     Then I should not see the homepage introduction video block
