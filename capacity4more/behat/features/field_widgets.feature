Feature: Test custom field widgets.

  @javascript 
  Scenario: Adding document to discussion.
    Given I am logged in as user "mariecurie"
    When  I start creating "discussion" in full form with title "some title" in group "Tennis Group"
    And   I upload the file "cat1.jpg"
    And   I wait
    And   I save document in the overlay
    Then  I wait
    And   I should see "cat1.jpg"
