Feature: Group Documents
  As a group member and non-member
  In order to see and search into all documents
  I need to be able to see a documents overview page

  @api
  Scenario: Check documents overview as an anonymous user
    Given I am an anonymous user
    When I visit the documents overview of group "Nobel Prize" in "list" view
    Then I should see the documents overview
      And I should not see the "Upload a document" link above the overview
      And I should not see the "Add Photo album" link above the overview
    When I visit the documents overview of group "Nobel Prize" in "table" view
    Then I should see the documents overview

  @api
  Scenario: Check documents overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the documents overview of group "Nobel Prize" in "list" view
    Then I should see the documents overview
      And I should see the "Upload a document" link above the overview
      And I should see the "Add Photo album" link above the overview
    When I visit the documents overview of group "Nobel Prize" in "table" view
    Then I should see the documents overview

  @api
  Scenario: Check if filters on documents overview are retained when I switch view style
    Given I am an anonymous user
    When I visit the filtered list view of the documents of group "Nobel Prize"
      And I switch to "table" view
    Then I should still have retained search filters


