Feature: Group Documents
  As a group member and non-member
  In order to see and search into all documents
  I need to be able to see a documents overview page
  I need to be able to see a document detail page

  @api
  Scenario: Check documents list overview as an anonymous user
    Given I am an anonymous user
     When I visit the documents overview of group "Nobel Prize" in "list" view
     Then I should see the documents overview
      And I should not see the "Upload a document" link above the overview

  @api
  Scenario: Check documents list overview as group owner
    Given I am logged in as user "alfrednobel"
     When I visit the documents overview of group "Nobel Prize" in "list" view
     Then I should see the documents overview
      And I should see the "Upload a document" link above the overview

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

  @api
  Scenario: Check GA can edit a document's author
    Given I am logged in as user "galileo"
    When I visit the group "document" detail page "Nobel Prize ceremony"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Document Nobel Prize ceremony"
    And I should see the text "Authoring information"

  @api
  Scenario: Check GO can edit a document's author
    Given I am logged in as user "alfrednobel"
    When I visit the group "document" detail page "Nobel Prize ceremony"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Document Nobel Prize ceremony"
    And I should see the text "Authoring information"

  @api
  Scenario: Check SA can edit a document's author
    Given I am logged in as user "survivalofthefittest"
    When I visit the group "document" detail page "Nobel Prize ceremony"
    And I click "Edit" in the "primary tabs" region
    Then I should see the text "Edit Document Nobel Prize ceremony"
    And I should see the text "Authoring information"

  @javascript
  Scenario: Promote buttons shouldn't be displayed to anonymous users.
    Given  I am an anonymous user
    When I visit the documents overview of group "Nobel Prize"
    Then  I should not see the ".fa-thumb-tack" element

  @javascript
  Scenario: Promote buttons shouldn't be displayed to users without access.
    Given  I am logged in as user "isaacnewton"
    When I visit the documents overview of group "Nobel Prize"
    Then  I should not see the ".fa-thumb-tack" element

  @javascript
  Scenario Outline: Promote and highlight buttons should be displayed to users with access.
    Given  I am logged in as user "<user>"
    When I visit the documents overview of group "Nobel Prize"
    Then  I should see the ".fa-star-o" element
    And   I should see the ".fa-thumb-tack" element

    Examples:
      | user        |
      | alfrednobel |
      | mariecurie  |


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
