Feature: Content Forms
  As a group member I need to see a cancel button on every node form

  @api
  Scenario: Check cancel button on node forms as an authenticated user
    Given I am logged in as user "alfrednobel"
     When I visit the page "node/add/event" in the group "Nobel Prize"
     Then I should see "Cancel" in the "#edit-cancel" element

  @api
  Scenario: Check save draft button on node forms as an authenticated user
    Given I am logged in as user "alfrednobel"
     When I visit the page "node/add/event" in the group "Nobel Prize"
     Then I should see "Save as draft" in the "#edit-draft" element

  @javascript
  Scenario: Check unpublish button on node edit forms as an authenticated user
    Given I am logged in as user "mariecurie"
    And   a discussion "Edit this discussion" in group "Architecture" is created
    When  I start editing "discussion" "Edit this discussion" in group "Architecture"
    Then  I should see "Unpublish" in the "#edit-draft" element