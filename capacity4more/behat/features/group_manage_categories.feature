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
  Scenario: Check I can create a new category type in the quick form.
    Given I am logged in as user "galileo"
    When  I manage the categories types of group "Nobel Prize"
    And   I create a new category type "Winners" with quick form
    Then  I should see "Created new term Winners."

  @javascript
  Scenario: Check I can create a new term in the quick form.
    Given I am logged in as user "galileo"
    When  I manage the categories of group "Nobel Prize"
    And   I create a new term "Albert Einstein" under "Winners" with quick form
    Then  I should see "Created new term Albert Einstein."

  @javascript
  Scenario: Check I can create a category type in edit form.
    Given I am logged in as user "galileo"
    When  I manage the categories of group "Nobel Prize"
    And   I create a new category type "Losers" with edit form
    Then  I should see "Created new category type Losers."

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
