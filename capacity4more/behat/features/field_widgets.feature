Feature: Test custom field widgets.

  @javascript @wip
  Scenario: Adding document to discussion.
    Given I am logged in as user "mariecurie"
    When  I start creating "discussion" in full form with title "some title" in group "Tennis Group"
    And   I upload the file "cat1.jpg"
    And   I wait
    And   I save document with title "New image document"
    Then  I wait
    And   I should see "New image document"
