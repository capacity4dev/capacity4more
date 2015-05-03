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
  Scenario: Check I can't manage group categories as group member.
    Given I am logged in as user "mariecurie"
    When  I manage the categories of group "Movie Popcorn Corner"
    And   I move subcategory "Drama" under "Romance"
    And   I press "Save"
    Then  I should see "Drama" under "Romance"


  @javascript
  Scenario: Check I can create a new term in the quick form.
    Given I am logged in as user "galileo"
    When  I manage the categories of group "Nobel Prize"
    And   I create a new term "London, England" under "Locations" with quick form
    Then  I should see "Created new term London, England."

