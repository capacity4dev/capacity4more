Feature: Test full form
  In order to see that the full form forms work
  As a group member and non-member
  I need to be able to add entities with the full form

  @javascript @foo
  Scenario: Check the taxonomy widgets.
    Given I am logged in as user "mariecurie"
    When  I create a discussion full form with title "New discussion for taxonomy" and body "Some text in the body" in "Tennis Group"
    And   I fill the taxonomy in the full form and save
    Then  I should see the following details "Earth,Masters Tournaments,2000,French"

  @javascript @foo
  Scenario: Check the add a document widget.
    Given I am logged in as user "mariecurie"
    When  I create a discussion full form with title "New discussion for document" and body "Some text in the body" in "Nobel Prize"
    And   I add a document from the library
    Then  I should see the following details "Documents,Nobel Prize in Physics 2014"

  @javascript @foo
  Scenario: Adding document to discussion.
    Given I am logged in as user "mariecurie"
    When  I create a discussion full form with title "New discussion for new document" and body "Some text in the body" in "Tennis Group"
    And   I upload the file "cat1.jpg"
    And   I save document in the overlay
    Then  I should see "cat1.jpg"

