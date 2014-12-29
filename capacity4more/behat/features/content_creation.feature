Feature: Test content creation in full forms using custom widgets.

  @javascript @wip
  Scenario: Adding document with image file to discussion.
    Given I am logged in as user "mariecurie"
    When  I start creating "discussion" in full form with title "some title" in group "Tennis Group"
    And   I upload the file "cat1.jpg"
    And   I wait
    And   I save the document with title "New image document"
    Then  I wait for text "New image document" to appear in "add-document-form"
