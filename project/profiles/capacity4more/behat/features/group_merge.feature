Feature: Merge Groups & Projects

  @javascript
  Scenario: Check if admin from merged group becomes member in the new group
    Given I am logged in as user "mariecurie"
    When  I visit "node/18/merge"
    And   I fill in "edit-target-group" with "Football Talk (15)"
    And   I click the "#edit-merge" element
    And   I wait
    Then  User "galileo" is a member of Group "Football Talk"
    And   User "mariecurie" has "administrator member" role in Group "Football Talk"

  @javascript
  Scenario: Check if wiki pages of merged group are added to the book structure of the new group
    Given I am logged in as user "mariecurie"
    When  I visit "node/15/merge"
    And   I uncheck the box "edit-content-types-event"
    And   I fill in "edit-target-group" with "Tennis Group (16)"
    And   I click the "#edit-merge" element
    And   I wait
    Then  Node with id "104" is content of Group "Tennis Group"
    And   Content with id "104" is available for user "alfrednobel"
    And   Orphan node "64" should be deleted

  @javascript
  Scenario: Check documents are migrated after group merge
    Given I am logged in as user "mariecurie"
    When  I visit "node/17/merge"
    And   I check the box "edit-content-types-document"
    And   I fill in "edit-target-group" with "Tennis Group (16)"
    And   I click the "#edit-merge" element
    And   I wait
    And   Node with id "61" is content of Group "Tennis Group"
