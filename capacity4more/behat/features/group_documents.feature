Feature: Group Documents
  As a group member and non-member
  In order to see and search into all documents
  I need to be able to see a documents overview page

  @api
  Scenario: Check documents overview as an anonymous user
    Given I am an anonymous user
    When I visit the documents overview of group "Nobel Prize"
    Then I should see the documents overview
    And I should not see the "Upload a document" link above the overview
    And I should not see the "Add Photo album" link above the overview
    When I select value "Earth" of "Topics" filter
    And I switch to "table" view

  @api
  Scenario: Check documents overview as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the documents overview of group "Nobel Prize"
    Then I should see the documents overview
    And I should see the "Upload a document" link above the overview
    And I should see the "Add Photo album" link above the overview


