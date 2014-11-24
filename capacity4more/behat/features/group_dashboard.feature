Feature: Group dashboard
  As a group member and non-member
  In order to see the group latest activity and information
  I need to be able to see a dashboard with different widgets

  @api @foo
  Scenario: Check dashboard content as group owner
    Given I am logged in as user "mariecurie"
    When I visit the dashboard of group "Movie Popcorn Corner"
    Then I should see the group dashboard
