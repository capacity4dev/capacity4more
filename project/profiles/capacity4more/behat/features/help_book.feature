Feature: Help & Guidance
  Test the Help & Guidance book navigation

  @api
  Scenario: Check help book as a site admin
    Given I am logged in as user "survivalofthefittest"
    When  I define the main help book page
    And   I am on "help-guidance"
    Then  I should have access to the page
    And   I should see the link "Add child page"

  @api
  Scenario: Check help book as an anonymous user
    Given I am an anonymous user
    When  I am on "help-guidance"
    Then  I should have access to the page
    And   I should see an ".c4m-sidebar-book-navigation" element
    And   I should not see the link "Add child page"
