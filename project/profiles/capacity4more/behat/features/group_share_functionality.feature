Feature: Testing the sharing content between groups functionality and permissions.

  @api
  Scenario: Check share redirect to original content
    Given I am an anonymous user
    When I visit the group "share" detail page "Film Festival Ghent"
    Then  I should see the event detail page

  @api
  Scenario: Check access on redirect to share to a private group (non-member).
    Given I am logged in as user "alfrednobel"
    When I visit the group "share" detail page "Nobel Prize ceremony"
    Then  I should not have access to the page

  @api
  Scenario: Check access on redirect to share to a private group (member).
    Given I am logged in as user "badhairday"
    When I visit the group "share" detail page "Nobel Prize ceremony"
    Then  I should see the document detail page

  @api
  Scenario: Check access denied on redirect to original content from a private group.
    Given I am an anonymous user
    When I visit the group "share" detail page "Barclays ATP World Tour Finals"
    Then  I should not have access to the page

  @api
  Scenario: Check access on redirect to original content from a private group.
    Given I am logged in as user "alfrednobel"
    When I visit the group "share" detail page "Barclays ATP World Tour Finals"
    Then  I should see the event detail page
