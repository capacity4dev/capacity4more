Feature: Group Documents
  As a group member and non-member
  In order to see and search into all documents
  I need to be able to see a documents overview page
  I need to be able to switch between list and table view
  I need to be able to see a document detail page

  @api
  Scenario: Check documents list overview as an anonymous user
    Given I am an anonymous user
     When I visit the documents overview of group "Nobel Prize" in "list" view
     Then I should see the documents overview
      And I should not see the "Upload a document" link above the overview

  @api
  Scenario: Check documents table overview as an anomynous user
    Given I am an anonymous user
     When I visit the documents overview of group "Nobel Prize" in "table" view
     Then I should see the documents overview
      And I should not see the "Upload a document" link above the overview

  @api
  Scenario: Check documents list overview as group owner
    Given I am logged in as user "alfrednobel"
     When I visit the documents overview of group "Nobel Prize" in "list" view
     Then I should see the documents overview
      And I should see the "Upload a document" link above the overview

  @api
  Scenario: Check documents table overview as group owner
    Given I am logged in as user "alfrednobel"
     When I visit the documents overview of group "Nobel Prize" in "table" view
     Then I should see the documents overview
      And I should see the "Upload a document" link above the overview

  @api
  Scenario: Check if filters on documents overview are retained when I switch to table view style
    Given I am an anonymous user
     When I visit the filtered list view of the documents of group "Nobel Prize"
      And I switch to "table" view
     Then I should still have retained search filters

  @api
  Scenario: Check document detail as an anonymous user
    Given I am an anonymous user
    When I visit the group "document" detail page "Nobel Prize ceremony"
    Then I should see the document detail page

  @api
  Scenario: Check document detail as group owner
    Given I am logged in as user "alfrednobel"
    When I visit the group "document" detail page "Nobel Prize ceremony"
    Then I should see the document detail page

#  Tests are commented because file uploading is not working.
#  @javascript @wip
#  Scenario: Check group reference field is filled from context and hidden
#    Given I am logged in as user "mariecurie"
#    When  I start creating "document" "Some new document1" in group "Architecture" with file field "edit-c4m-document-und-0-upload"
#    And   I should not see an "edit-og-group-ref-und-0-default" element
#    And   I press "Save"
#    Then  I should see "Some new document1" in the activity stream of the group "Architecture"
#
#  @javascript
#  Scenario: Check group reference field is filled from context and hidden
#    Given I am logged in as user "mariecurie"
#    When  I start editing "document" "Some new document1" in group "Architecture"
#    Then  I should not see an "edit-og-group-ref-und-0-default" element
