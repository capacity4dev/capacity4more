Feature: Testing the projects overview page.

  @api
  Scenario: Check projects landing page as an anonymous user
    Given I am an anonymous user
    When I visit "projects"
    Then I should see the sidebar search
    And I should see the sidebar facet with title "Type"
    And I should see the sidebar facet with title "Stage"
    And I should see the sidebar facet with title "Topics"
    And I should see the sidebar facet with title "Regions & Countries"
    And I should be able to sort the overview

  @javascript
  Scenario: SA highlight a group via its dashboard.
    Given I am logged in as user "mariecurie"
    And   The window is maximized
    When  I visit the dashboard of project "Human Genome Project"
    Then  I should be able to toggle the project highlight link
