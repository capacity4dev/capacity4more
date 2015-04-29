Feature: Group Creation
  Test group creation  field

  @javascript @test
  Scenario: Check limit selected topics
    Given I am logged in as user "alfrednobel"
    When  I go to "node/add/group"
    And   I check the related topics checkbox "Earth, Water, Wind, Fire"
    Then  I wait for the "Fire" checkbox should not be checked
