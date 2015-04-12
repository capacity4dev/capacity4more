Feature: Group Creation
  Test group creation  field

  @javascript 
  Scenario: Check limit selected topics
    Given I am logged in as user "alfrednobel"
    When  I go to "node/add/group"
    And   I check the related topic checkbox "Earth"
    And   I check the related topic checkbox "Water"
    And   I check the related topic checkbox "Wind"
    And   I check the related topic checkbox "Fire"
    And   I wait
    Then  the "Fire" checkbox should not be checked
