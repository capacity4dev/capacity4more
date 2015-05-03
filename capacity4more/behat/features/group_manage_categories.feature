Feature: Group manage Categories
  As a group administrator I can Add/Edit/Reorder/Delete group Categories and
  Subcategories.

  @api
  Scenario: Check I can manage group categories as group owner.
    Given I am logged in as user "mariecurie"
    When  I manage the categories of group "Movie Popcorn Corner"
    Then  I should have access to the page
    And   I should see "EDIT GROUP CATEGORIES"

  @api
  Scenario: Check I can't manage group categories as group member.
    Given I am logged in as user "isaacnewton"
    When  I manage the categories of group "Movie Popcorn Corner"
    Then  I should not have access to the page

  @javascript
  Scenario: Check I can reorder subcategories as group member.
    Given I am logged in as user "mariecurie"
    When  I manage the categories of group "Movie Popcorn Corner"
    And   I move category "Drama" under "Romance"
    And   I press "Save"
    Then  I should see "Drama" under "Romance"

  @javascript
  Scenario: Check I can reset subcategories order to alphabetical as group member.
    Given I am logged in as user "mariecurie"
    When  I manage the categories of group "Movie Popcorn Corner"
    And   I move category "Drama" under "Romance"
    And   I press "Save"
    And   I reset order to alphabetical
    And   I press "Reset to alphabetical"
    Then  I should see "Drama" under "Comedy"
    And   I should see "Horror" under "Drama"
    And   I should see "Romance" under "Horror"

  @javascript
  Scenario: Check I can reorder categories as group member.
    Given I am logged in as user "mariecurie"
    When  I manage the categories types of group "Nobel Prize"
    And   I move category "Locations" under "Prizes"
    And   I press "Save"
    Then  I should see "Locations" under "Prizes"

  @javascript
  Scenario: Check I can reset categories order to alphabetical as group member.
    Given I am logged in as user "mariecurie"
    When  I manage the categories types of group "Nobel Prize"
    And   I move category "Locations" under "Prizes"
    And   I press "Save"
    And   I should see "Locations" under "Prizes"
    And   I reset order to alphabetical
    And   I press "Reset to alphabetical"
    Then  I should see "Organization" under "Locations"
    And   I should see "Prizes" under "Organization"
