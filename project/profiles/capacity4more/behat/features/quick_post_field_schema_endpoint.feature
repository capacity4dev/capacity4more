Feature: Test quick post field schema endpoint
  In order to create entities from the quick post
  As a drupal authenticated user
  I need to have access to the quick post field schema endpoint

  @api
  Scenario: A visitor should not have access to the quick post field schema endpoint.
    Given I am an anonymous user
    When  I go to "nobelprize/quick-post/discussions/field-schema"
    Then  I should not have access to the page

  @api
  Scenario: A GO should have access to the quick post field schema endpoint.
    Given I am logged in as user "alfrednobel"
    When  I go to "nobelprize/quick-post/discussions/field-schema"
    Then  I should have access to the page
