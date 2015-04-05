Feature: Group Manage
  Test group manage page links.


  @api 
  Scenario: Check anchors in the links on manage group page
    Given I am logged in as user "alfrednobel"
    When  I go to "nobelprize/manage"
    Then  the response should contain "#edit-details"
    And   the response should contain "#edit-permissions"
    And   the response should contain "#edit-related-content"
    And   the response should contain "#edit-image-banner"
    And   the response should contain "#edit-image-list"

  @api @foo
  Scenario: Check anchors in the edit form page
    Given I am logged in as user "alfrednobel"
    When  I go to "nobelprize/node/37/edit"
    And   I should see an "#edit-details" element
    And   I should see an "#edit-permissions" element
    And   I should see an "#edit-related-content" element
    And   I should see an "#edit-image-banner" element
    And   I should see an "#edit-image-list" element

