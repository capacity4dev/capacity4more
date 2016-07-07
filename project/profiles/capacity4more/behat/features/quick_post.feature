#Feature: Test quick post
#  In order to create entities from the quick post
#  As a drupal authenticated user
#  I need to be able to submit quick posts

#  @javascript
#  Scenario: Check Quick post error validation.
#    Given I am logged in as user "mariecurie"
#    When  I create a discussion quick post with title "Fo" and body "Some text in the body" in "Tennis Group"
#    Then  I should see "Title is too short."

#  @javascript
#  Scenario: Check Quick post "discussion" submit.
#    Given I am logged in as user "mariecurie"
#    When  I create a discussion quick post with title "New discussion" and body "Some text in the body" in "Tennis Group"
#    Then  I should see "New discussion"
