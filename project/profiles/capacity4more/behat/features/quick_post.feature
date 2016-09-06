Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  Background:
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
    When  I visit the dashboard of group "Tennis Group"
    Then  I focus on "label" element
    Then  I should wait to see "Create a post with additional details"
#    When  I create a discussion quick post with title "Fo" and body "Some text in the body" in "Tennis Group"
#    Then  I should see "Title is too short."
#    Then  I wait for text "Title is too short." to appear in ".help-block"

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
    Then  I should see "New discussion"
