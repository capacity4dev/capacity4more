Feature: Group Creation
  Test group creation  field

  @javascript @foo
  Scenario: Check limit selected topics
    Given I am logged in as user "alfrednobel"
    When  I go to "node/add/group"
    And   I check the related topic checkbox "Earth"
    And   I check the related topic checkbox "Water"
    And   I check the related topic checkbox "Wind"
    And   I check the related topic checkbox "Fire"
#    And   I check the related topic checkbox "1"
#    And   I check the related topic checkbox "17"
#    And   I check the related topic checkbox "2"
#    And   I check the related topic checkbox "3"
    And   I wait
    Then  the "Fire" checkbox should not be checked
