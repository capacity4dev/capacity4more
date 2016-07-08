Feature: Testing the sharing content between groups functionality and permissions.

  @share
  Scenario: Check share redirect to original content
    Given I am an anonymous user
    When I visit the group "share" detail page "Nobel Prize ceremony"
    Then  I should see the document detail page

  @share
  Scenario: Check access on redirect to share to a private group.
    Given I am logged in as user "alfrednobel"
    When I visit the group "share" detail page "Nobel Prize ceremony"
    Then  I should see the document detail page

  @share
  Scenario: Check access denied on redirect to original content from a private group.
    Given I am an anonymous user
    When I visit the group "share" detail page "Barclays ATP World Tour Finals"
    Then  I should not have access to the page

  @share
  Scenario: Check access on redirect to original content from a private group.
    Given I am logged in as user "alfrednobel"
    When I visit the group "share" detail page "Barclays ATP World Tour Finals"
    Then  I should have access to the page
