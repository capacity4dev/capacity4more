Feature: Test homepage and activity stream in the homepage
  In order to see recent content
  As a group member and non-member and anonymous user
  I need to be able to see an activity stream of recent operations

  @api
  Scenario: Logged in user should have access to the site homepage.
    Given I am logged in as user "mariecurie"
    When I visit the site homepage
    Then I should see the site homepage

  @api
  Scenario: Logged in user should not see button to open the introduction video.
    Given I am logged in as user "mariecurie"
    When I visit the site homepage
    Then I should not see the homepage introduction video block

  @api
  Scenario: Anonymous user should have access to the site homepage.
    Given I am an anonymous user
    When I visit the site homepage
    Then I should see the site homepage

  @api
  Scenario: Anonymous user should see button to open the introduction video.
    Given I am an anonymous user
    When I visit the site homepage
    Then I should see the homepage introduction video block

  @javascript
  Scenario: Change one group access to restricted.
    Given I am logged in as user "admin"
    Then  I change access of group "Nobel prize" to Restricted with "gravity.com" restriction

  @javascript
  Scenario: Anonymous user can see article activities and doesn't see filter.
    Given I am an anonymous user
    When  I visit the site homepage
    And   I wait
    Then  I should not see "Filter by"
    And   I should not see "Nobel Prize" in the "div.activity-stream" element
    And   I should see "posted an Article" in the "div.activity-stream" element

  @javascript
  Scenario: Logged in user can see article activities and filter.
    Given I am logged in as user "isaacnewton"
    When  I visit the site homepage
    And   I wait
    Then  I should see "Filter by"
    And   I should see "Nobel Prize" in the "div.activity-stream" element
    And   I should see "My groups" in the "div.pane-filter" element
    And   I should see "posted an Article" in the "div.activity-stream" element

  @javascript
  Scenario: Logged in user can't see article activities when My Groups filter is chosen.
    Given I am logged in as user "isaacnewton"
    When  I visit the site homepage
    And   I select the radio button "My groups" with the id "edit-homepage-filter-groups"
    And   I wait
    Then  I should not see "Nobel Prize" in the "div.activity-stream" element
    And   I should not see "Football Talk" in the "div.activity-stream" element
    And   I should not see "posted an Article" in the "div.activity-stream" element

  @javascript
  Scenario: Logged in user not member can't see My group filter and restricted
  group activities
    Given I am logged in as user "president"
    When  I visit the site homepage
    And   I wait
    Then  I should see "Filter by"
    And   I should not see "My groups" in the "div.pane-filter" element
    And   I should not see "Nobel Prize" in the "div.activity-stream" element
    And   I should see "posted an Article" in the "div.activity-stream" element

  @javascript
  Scenario: Logged in user not member should see only activities from groups of
  interests when filter is set to My interests
    Given I am logged in as user "president"
    When  I visit the site homepage
    And   I select the radio button "My interests" with the id "edit-homepage-filter-interests"
    And   I wait
    Then  I should not see "Lusail City" in the "div.activity-stream" element
    And   I should see "posted an Article" in the "div.activity-stream" element

  @javascript
  Scenario: Change one group access back to public.
    Given I am logged in as user "admin"
    Then  I change access of group "Nobel prize" to "Public"
