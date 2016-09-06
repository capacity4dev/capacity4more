Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  @api
  Scenario: A visitor should not have access to the quick post field info schema endpoint.
    Given I am an anonymous user
    When  I go to "nobelprize/quick-post/discussions/field-schema"
    Then  I should not have access to the page

  @api
  Scenario: A GO should have access to the quick post field info schema endpoint.
    Given I am logged in as user "alfrednobel"
    When  I go to "nobelprize/quick-post/discussions/field-schema"
    Then  I should have access to the page

  @javascript
  Scenario: Check Quick post error validation.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "Fo" and body "Some text in the body" in "Tennis Group"
    Then  I should see "Title is too short."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
    Then  I should see "New discussion"
