Feature: Feeds
  Test RSS feeds, overview and detail pages.

  @api
  Scenario: As an anonymous user I should not be able to create a feed.
    Given I am an anonymous user
    And   I am on "/node/add/feed"
    Then  I should not have access to the page

  @api
  Scenario: As a group member I should not be able to create a feed.
    Given I am logged in as user "alfrednobel"
    And   I am on "/node/add/feed"
     Then I should not have access to the page

  @api
  Scenario: As an administrator I should be able to access a feed creation form.
    Given I am logged in as user "mariecurie"
    When  I visit "/node/add/feed"
    Then  I should have access to the page
    And   I should see a "Title" field
    And   I should see a "Description" field
    And   I should see a "Related Topics" field
    And   I should see a "Articles" field
    And   I should see a "Groups" field

  @api
  Scenario: As an administrator I should be able to create a feed.
    Given I am logged in as user "mariecurie"
    When  I visit "/node/add/feed"
    And   I fill in "Title" with "An RSS feed"
    And   I fill in "Description" with "This is the description of the feed."
    And   I fill in "edit-c4m-related-articles-und-0-target-id" with "Electricity for Water"
    And   I fill in "edit-c4m-related-group-unlimited-und-0-target-id" with "Nobel Prize"
    And   I press "Save"
    Then  I should see "Feed An RSS feed has been created"

  @api
  Scenario: As an anonymous user I should be able to see a feed overview, detail page & RSS feed.
    Given I am an anonymous user
    When  I visit "feeds"
    Then  I should have access to the page
    And   I should see "Feeds"
    And   I should see "An RSS feed"
    When  I click "An RSS feed"
    Then  I should have access to the page
    And   I should see "An RSS feed"
    When  I click "/rss"
    Then  I should have access to the page
    And   I should see in the header "Content-Type":"application/rss+xml; charset=utf-8"
