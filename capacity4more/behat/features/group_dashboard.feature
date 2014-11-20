Feature: Group dashboard
  Test the group dashboard functionality.

  @api @group @dashboard
  Scenario: Check dashboard content as group owner
    Given I am logged in as user "mariecurie"
     When I visit the group dashboard of group "Movie Popcorn Corner"
     Then I should have access to the page
      And Group menu item "Home" should be active
      And I should see the Quick Post form
      And I should see the Activity stream
