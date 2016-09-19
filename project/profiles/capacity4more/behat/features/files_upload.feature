Feature: Files upload
  As a group member
  In order to upload a file
  I need to be able to see the file upload form

  @api
  Scenario: Check that anonymous user can not see the file upload form
    Given I am an anonymous user
    When  I go to the media browser page
    Then  I should not have access to the page

  @javascript
  Scenario Outline: Check that authenticated user sees the upload file form
    Given I am logged in as user "<user>"
    When  I go to the media browser page
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
