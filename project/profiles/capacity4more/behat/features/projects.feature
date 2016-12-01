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

  @api @my
  Scenario: Verify that PO can see draft projects, while regular user can not.
    Given I am logged in as user "badhairday"
    When  The project "Lusail City Hotel" status is changed by admin to "Draft"
    Then  I visit "projects"
    And   I should see "Lusail City Hotel"
    And   I am logged in as user "isaacnewton"
    And   I visit "projects"
    And   I should not see "Lusail City Hotel"

  @api @my
  Scenario: Verify that non member can see published project.
    Given I am logged in as user "badhairday"
    When  The project "Lusail City Hotel" status is changed by admin to "Published"
    Then  I visit "projects"
    And   I should see "Lusail City Hotel"
