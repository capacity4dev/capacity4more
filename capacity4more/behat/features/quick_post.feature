Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as user "mariecurie"
    When  I fill label with "fo" in "Tennis Group"
    Then  I should see "Title is too short."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
    Then  I should see "New discussion"

  @javascript
  Scenario: Check Quick post "event" submit.
    Given I am logged in as user "mariecurie"
    When  I create an event quick post with title "New event" and body "Some text in the body" that starts at "25/12/2018" and ends at "26/12/2018" in "Tennis Group"
    Then  I should see "New event"

  @javascript
  Scenario: Adding document with image file to discussion.
    Given I am logged in as user "mariecurie"
    When  I start creating "discussion" in full form with title "some title" in group "Tennis Group"
    And   I upload the file "cat1.jpg"
    And   I wait for text "File cat1.jpg has been loaded!" to appear in "documentForm"
    And   I save document with title "New document" for a discussion
    And   I wait
    Then  I should see "New document"

  @javascript
  Scenario: Adding document with doc file to discussion.
    Given I am logged in as user "mariecurie"
    When  I start creating "discussion" in full form with title "some title" in group "Tennis Group"
    And   I upload the file "doc1.doc"
    And   I wait for text "File doc1.doc has been loaded!" to appear in "documentForm"
    And   I save document with title "New document" for a discussion
    And   I wait
    Then  I should see "New document"
