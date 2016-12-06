Feature: Test quick post
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to be able to submit quick posts

  Background:
    # The quick post is hidden on small screens.
    Given The window is maximized

  @javascript
  Scenario: Check Quick post form validation.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "N" and body "" in "Tennis Group" without topic
    And   I should see "Title is missing or too short." in the "form#quick-post-form" element
    And   I should see "Body is required." in the "form#quick-post-form" element
    And   I should see "Topic is required." in the "form#quick-post-form" element

  @javascript
  Scenario: Check Quick post "discussion" submit.
    Given I am logged in as user "mariecurie"
    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis group" with topic
    Then  I wait for the text "New discussion" to appear in "activity-stream" class
    Then  I wait for the text "Create a post with additional details by using" to disappear from "quick-post-fields" id
    When  I click "New discussion"
    Then  I wait for the text "Idea posted by" to appear in "group-node-meta" class

  @javascript
  Scenario: Check Quick post advanced form.
    Given I am logged in as user "alfrednobel"
    When  I create a discussion quick post in advanced form with title "New nobel for QP advanced form" and body "Some text in the body" in "Nobel Prize"
    Then  I wait for the text "Type of Discussion" to appear in "form-item-c4m-discussion-type-und" class
    And   I should not see "Latest activity"
    But   I should validate the body field format of "New nobel for QP advanced form" discussion node is "filtered_html"
    And   I should see "By pressing 'Save', you will save this discussion as a draft - please press 'Publish' to create and publish this discussion."
