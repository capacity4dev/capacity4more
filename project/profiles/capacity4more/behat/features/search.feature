Feature: Testing the did you mean feature offered for search api that provides
  spell check for what users may search for.

  @javascript
  Scenario: Testing the did you mean feature from search api with some result.
    Given I am an anonymous user
    When I visit the site homepage
    And I fill in "edit-keys" with "leve"
    And I press "<i class=\"fa fa-search\"></i>"
    And I wait
    Then I should see "Did you mean"

  @javascript
  Scenario: Testing the did you mean feature from search api when it should not be displayed.
    Given I am an anonymous user
    When I visit the site homepage
    And I fill in "edit-keys" with "level"
    And I press "<i class=\"fa fa-search\"></i>"
    And I wait
    Then I should not see "Did you mean"
