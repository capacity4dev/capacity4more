Feature: Testing the projects overview page.

  @api
  Scenario: Check projects landing page as an anonymous user
    Given I am an anonymous user
    When I visit "projects"
    Then I should see the sidebar search
    And I should see the sidebar facet with title "Filter by type"
    And I should see the sidebar facet with title "Filter by stage"
    And I should see the sidebar facet with title "Topics"
    And I should see the sidebar facet with title "Regions & Countries"
    And I should be able to sort the overview
