Feature: Test full form
  In order to see that the full form forms work
  As a group member and non-member
  I need to be able to add entities with the full form

  @javascript
  Scenario: Check the taxonomy widgets.
    Given I am logged in as user "mariecurie"
    When  I create a discussion full form with title "New discussion for taxonomy" and body "Some text in the body" in "Tennis Group"
    And   I fill the taxonomy in the full form
    Then  I should see the following details "Earth,Masters Tournaments,2000,French"

  @javascript @work
  Scenario: Check the add a document widget.
    Given I am logged in as user "mariecurie"
    When  I create a discussion full form with title "New discussion with document" and body "Some text in the body" in "Nobel Prize"
    And   I add a document from the library
    Then  I should see the following details "Documents,Nobel Prize in Physics 2014"
