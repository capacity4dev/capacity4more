Feature: Test homepage activity stream
  In order to see recent content
  As a group member and non-member and anonymous user
  I need to be able to see an activity stream of recent operations

  @javascript
  Scenario: Anonymous user can see article activities and doesn't see filter.
    Given I am an anonymous user
    When  I visit ""
    Then  I should see the text "posted an Article" in the "activity-stream"
    And   I should not see "Filter by"

  @javascript
  Scenario: Logged in user can see article activities and filter.
    Given I am logged in as user "isaacnewton"
    When  I visit ""
    Then  I should see "posted an Article"
    And   I should see "Filter by"

  @javascript
  Scenario: Logged in user can't see article activities when My Groups filter is chosen.
    Given I am logged in as user "isaacnewton"
    When  I visit ""
    And   I select the radio button "My groups" with the id "edit-homepage-filter-groups"
    Then  I should not see "posted an Article"
    And   I should not see "Nobel Prize"
