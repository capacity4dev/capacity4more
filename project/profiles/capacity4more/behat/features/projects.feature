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

  @api @my
  Scenario: Verify that PO can see draft projects, while regular user can not.
    Given The project "Lusail City Hotel" status is changed by admin to "Draft"
    When  I am logged in as user "badhairday"
    Then  I should see "Lusail City Hotel" on the "projects" overview
    And   I am logged in as user "isaacnewton"
    And   I should not see "Lusail City Hotel" on the "projects" overview

  @api @my
  Scenario: Verify that regular user can see published projects.
    Given The project "Lusail City Hotel" status is changed by admin to "Published"
    When  I am logged in as user "isaacnewton"
    Then  I should see "Lusail City Hotel" on the "projects" overview
