Feature: Content Forms
  As a group member I need to see a cancel button on every node form

  @api
  Scenario: Check cancel button on node forms as an authenticated user
    Given I am logged in as user "alfrednobel"
     When I visit the page "node/add/event" in the group "Nobel Prize"
     Then I should see "Cancel" in the "#edit-cancel" element
