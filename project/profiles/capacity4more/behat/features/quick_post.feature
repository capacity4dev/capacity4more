Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  Background:
    # The quick post is hidden on small screens.
    Given The window is maximized

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
    When  I create a discussion quick post with title "Fo" and body "" in "Tennis Group"
    Then  I should wait to see "Title is too short."
    And   I should see "Body is required."

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
    Then  I should wait to see "New discussion"
    And   I should not see "Create a post with additional details by using" in the "div#quick-post-fields" element
    When   I click "New discussion"
    Then  I should wait to see "Idea posted by"

  @javascript
  Scenario: Check Quick post advanced form.
    Given I am logged in as user "alfrednobel"
    When  I create a discussion quick post in advanced form with title "New nobel" and body "Some text in the body" in "Nobel Prize"
    Then  I should wait to see "Edit Discussion New nobel"
    And   I should not see "Latest activity"
