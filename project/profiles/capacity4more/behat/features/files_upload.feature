Feature: Files upload
  As a group member
  In order to upload a file
  I need to be able to see the file upload form

  Background:
    Given The window is maximized

  @javascript
  Scenario: Check that anonymous user can not see the file upload form
    Given I am an anonymous user
    When  I go to "media/browser?render=media-popup&plugins="
    Then  I should not see "Upload a new file"
    And  I follow "Library"

  @javascript
  Scenario Outline: Check that authenticated user sees the upload file form
    Given I am logged in as user "<user>"
    When  I go to "media/browser?render=media-popup&plugins="
    Then  I should see "Upload a new file"
    When  I press "Next"
    Then  I should see "Upload a new file field is required"
    Then  I follow "My files"
    Then  I should see the "#media-tab-media_default--media_browser_my_files" element

    Examples:
      | user           |
      | charlesbabbage |
      | alfrednobel    |
      | mariecurie     |
