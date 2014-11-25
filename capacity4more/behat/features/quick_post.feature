Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as user "mariecurie"
    When  I visit the dashboard of group "Tennis Group"
    And   I fill in "label" with "fo"
    Then  I should see "Title is too short."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
    Then  I should see "The Discussion was saved successfully."

  @javascript
  Scenario: Check Quick post "event" submit.
    Given I am logged in as user "mariecurie"
    When  I create an event quick post with title "New event" and body "Some text in the body" that starts at "25/12/2018" and ends at "26/12/2018" in "Tennis Group"
    Then  I should see "The Event was saved successfully."

  @javascript @foo
  Scenario: Test uploading files.
    Given I am logged in as user "mariecurie"
    When I start creating "discussion" in full form with title "some title" in group "Tennis Group"
    And I attach the file "/var/www/html/capacity4more/www/dan.jpg" to "document-file"
    Then I wait for text "was saved successfully." to appear in "entityForm"
    And I wait for text "File dan.jpg has been loaded!" to appear in "documentForm"
