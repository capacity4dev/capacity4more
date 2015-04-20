Feature: Content Forms
  As a group member I need to see a cancel button on every node form

  @api @wip
  Scenario: Check cancel button on node forms as an authenticated user
    Given I am logged in as user "alfrednobel"
    When I visit the group "nobelprize" overview
      And I visit "node/add/event"
    Then I should see "Cancel" in the "#edit-cancel" element